#include <iostream>
#include <String>
#include <vector>
#include "agenda.h"

using namespace std;

void printPersona(Persona persona){
    cout << persona.nombre << ", " << persona.telefono << endl;
}
void printAgenda(const Agenda &agenda) {
    cout << "Nombre   Telefono" << endl;
    for (int i = 0; i < agenda.cantidad; i++) {
        for (const Persona &persona : agenda.personas[i]) {
            printPersona(persona);
        }
    }
    cout << "Total de personas registradas: " << agenda.cantidad << endl;
    
    
}

void agregarPersona(Agenda &agenda, const Persona &nuevaPersona) {
    if (agenda.cantidad < 10) {
        agenda.personas[agenda.cantidad] = {nuevaPersona};
        agenda.cantidad++;
        cout << "Persona agregada exitosamente." << endl;
    } else {
        cout << "La agenda esta llena, no se puede agregar mas personas." << endl;
    }
}

string buscarTelefono(const Agenda &agenda, const string &nombre){
    for (int i = 0; i < agenda.cantidad; i++) {
        for (const Persona &persona : agenda.personas[i]) {
            if (persona.nombre == nombre) {
                return persona.telefono;
            }
        }
    }
    return "No se encontró el nombre";
}

string buscarPersona(const Agenda &agenda, const string &telefono){
    for (int i = 0; i < agenda.cantidad; i++) {
        for (const Persona &persona : agenda.personas[i]) {
            if (persona.telefono == telefono) {
                return persona.nombre;
            }
        }
    }
    return "No se encontró el telefono";
}

void modificarTelefono(Agenda &agenda, const string &nombre, const string &nuevoTelefono){
    for (int i = 0; i < agenda.cantidad; i++) {
        for (Persona &persona : agenda.personas[i]) {
            if (persona.nombre == nombre) {
                persona.telefono = nuevoTelefono;
                cout << "Telefono modificado exitosamente." << endl;
                return;
            }
        }
    }
    cout << "No se encontró el nombre." << endl;
}
void eliminarPersona(Agenda &agenda, const string &nombre) {
    vector<Persona> personas_aux;
    for (int i = 0; i < agenda.cantidad; i++) {
        for (Persona &persona : agenda.personas[i]) {
            if (persona.nombre != nombre) {
                personas_aux.push_back(persona);
            }
        }
    }
    if (personas_aux.size() < agenda.cantidad) {
        agenda.cantidad--;
        for (int i = 0; i < personas_aux.size(); i++) {
            agenda.personas[i] = {personas_aux[i]};
        }
        cout << "Persona eliminada exitosamente." << endl;
        return;
    }

    cout << "No se encontró el nombre de la persona a eliminar." << endl;
}
