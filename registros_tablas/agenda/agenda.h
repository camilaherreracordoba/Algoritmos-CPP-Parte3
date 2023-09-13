/*
41) Definir un vector Agenda, en donde se pueda guardar los datos de, a lo sumo, 50
personas (definidas en el ej. anterior) y permita:
a. Cargar los datos en la Agenda.
b. Poder buscar el teléfono de una persona indicando su nombre.
c. Poder buscar el nombre de una persona indicando su teléfono.
d. Poder modificar el número de teléfono de alguna persona.
e. Poder agregar un nuevo contacto.
f. Poder dar de baja a un contacto.
*/
#ifndef AGENDA_H
#define AGENDA
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    string telefono;
};
struct Agenda {
    vector<Persona> personas[50];
    int cantidad = 0;

    
};

void printPersona(Persona persona);
void printAgenda(const Agenda &agenda);
void agregarPersona(Agenda &agenda, const Persona &nuevaPersona);
string buscarTelefono(const Agenda &agenda, const string &nombre);
string buscarPersona(const Agenda &agenda, const string &telefono);
void modificarTelefono(Agenda &agenda, const string &nombre, const string &nuevoTelefono);
void eliminarPersona(Agenda &agenda, const string &nombre);
#endif // AGENDA_H
