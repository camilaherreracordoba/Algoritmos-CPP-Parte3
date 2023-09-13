#include <iostream>
#include <String>
#include <vector>

#include "gondola.h"

using namespace std;

void menuGondola() {
    int opcion;
    Gondola gondola;
    vector<Producto> chango;
    
    do {
        cout << "------------------- Menu de Gondola -------------------" << endl;
        cout << "1. Cargar productos en la gondola" << endl;
        cout << "2. Buscar producto por nombre" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "4. Modificar precio de un producto" << endl;
        cout << "5. Cantidad de productos en oferta" << endl;
        cout << "6. Agregar productos al chango" << endl;
        cout << "7. Cobrar chango" << endl;
        cout << "8. Imprimir gondola" << endl;
        cout << "9. Salir" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                vector<Producto> nuevosProductos;
                int numProductos;
                cout << "Ingrese la cantidad de productos a cargar en la gondola: ";
                cin >> numProductos;
                for (int i = 0; i < numProductos; i++) {
                    Producto producto;
                    cout << "Producto " << i + 1 << ":" << endl;
                    cout << "Nombre: ";
                    cin >> producto.nombre;
                    cout << "Codigo de barras: ";
                    cin >> producto.codigo_barras;
                    cout << "Precio: ";
                    cin >> producto.precio;
                    cout << "Oferta (1 para Si, 0 para No): ";
                    cin >> producto.oferta;
                    nuevosProductos.push_back(producto);
                }
                cargarProductosEnGondola(gondola, nuevosProductos);
                break;
            }
            case 2: {
                string nombre;
                cout << "Ingrese el nombre del producto a buscar: ";
                cin >> nombre;
                Producto productoEncontrado = buscarProductoPorNombre(gondola, nombre);
                if (productoEncontrado.codigo_barras != "") {
                    cout << "Producto encontrado:" << endl;
                    printProducto(productoEncontrado);
                }
                break;
            }
            case 3: {
                string codigo;
                cout << "Ingrese el codigo de barras del producto a buscar: ";
                cin >> codigo;
                Producto productoEncontrado = buscarProductPorCodigo(gondola, codigo);
                if (productoEncontrado.codigo_barras != "") {
                    cout << "Producto encontrado:" << endl;
                    printProducto(productoEncontrado);
                }
                break;
            }
            case 4: {
                string codigo;
                float nuevoPrecio;
                cout << "Ingrese el codigo de barras del producto cuyo precio desea modificar: ";
                cin >> codigo;
                cout << "Ingrese el nuevo precio: ";
                cin >> nuevoPrecio;
                modificarPrecio(gondola, codigo, nuevoPrecio);
                break;
            }
            case 5: {
                int cantidadOferta = cantidadProductosEnOferta(gondola);
                cout << "Cantidad de productos en oferta: " << cantidadOferta << endl;
                break;
            }
            case 6: {
                string codigo;
                printGondola(gondola);
                cout << "Ingrese el codigo de barras del producto a agregar al chango: ";
                cin >> codigo;
                Producto productoEnChango = buscarProductPorCodigo(gondola, codigo);
                if (productoEnChango.codigo_barras != "") {
                    chango.push_back(productoEnChango);
                    cout << "Producto agregado al chango." << endl;
                }
                break;
            }
            case 7: {
                cobrarProductosEnChango(chango);
                break;
            }
            case 8: {
                printGondola(gondola); 
                break;
            }
            case 9: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 9);
}



int main() {
    menuGondola();
    return 0;
}