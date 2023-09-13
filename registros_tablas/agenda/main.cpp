#include <iostream>
#include <String>
#include <vector>
#include "agenda.h"

using namespace std;

void menuAgenda() {
    Agenda agenda;

    while (true) {
        cout << "------------------------ Agenda -----------------------" << endl;
        cout << "1. Mostrar agenda" << endl;
        cout << "2. Agregar persona" << endl;
        cout << "3. Buscar telefono por nombre" << endl;
        cout << "4. Buscar nombre por telefono" << endl;
        cout << "5. Modificar telefono" << endl;
        cout << "6. Eliminar persona" << endl;
        cout << "7. Salir" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                printAgenda(agenda);
                break;
            case 2: {
                Persona nuevaPersona;
                cout << "Ingrese el nombre: ";
                cin >> nuevaPersona.nombre;
                cout << "Ingrese el telefono: ";
                cin >> nuevaPersona.telefono;
                agregarPersona(agenda, nuevaPersona);
                break;
            }
            case 3: {
                string nombre;
                cout << "Ingrese el nombre a buscar: ";
                cin >> nombre;
                string telefono = buscarTelefono(agenda, nombre);
                cout << "Telefono de " << nombre << ": " << telefono << endl;
                break;
            }
            case 4: {
                string telefono;
                cout << "Ingrese el telefono a buscar: ";
                cin >> telefono;
                string nombre = buscarPersona(agenda, telefono);
                cout << "Nombre con telefono " << telefono << ": " << nombre << endl;
                break;
            }
            case 5: {
                string nombre, nuevoTelefono;
                cout << "Ingrese el nombre de la persona a modificar: ";
                cin >> nombre;
                cout << "Ingrese el nuevo telefono: ";
                cin >> nuevoTelefono;
                modificarTelefono(agenda, nombre, nuevoTelefono);
                break;
            }
            case 6: {
                string nombre;
                cout << "Ingrese el nombre de la persona a eliminar: ";
                cin >> nombre;
                eliminarPersona(agenda, nombre);
                break;
            }
            case 7:
                cout << "Saliendo del programa..." << endl;
                return;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    }
}

int main() {
    menuAgenda();
    return 0;
}