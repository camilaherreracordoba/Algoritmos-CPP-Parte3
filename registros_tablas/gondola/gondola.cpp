#include <iostream>
#include <String>
#include <vector>

#include "gondola.h"

using namespace std;

void printProducto(Producto producto) {
    if(producto.codigo_barras != "") {
        cout << producto.nombre << "    " << producto.codigo_barras << "    " << producto.precio << "   " << precioFinal(producto) << "     " << ((producto.oferta) ? "Si" : "No") << endl;
    }
}
float precioFinal(Producto producto){
    return (producto.oferta) ? producto.precio - producto.precio * 0.1 : producto.precio;
}

void printGondola(const Gondola &gondola) {
    cout << "-------------------------------------------------------" << endl;
    cout << "Nombre   Codigo   Precio   Precio Final   Oferta" << endl;
    for (int i = 0; i < gondola.cantidad; i++) {
        printProducto(gondola.productos[i]);
    }
    cout << "Total de productos en la gondola: " << gondola.cantidad << endl;
    cout << "-------------------------------------------------------" << endl;
    
}
void cargarProductosEnGondola(Gondola &gondola, const vector<Producto> &nuevosProductos) {

    if (gondola.cantidad + nuevosProductos.size() <= 50){
        for (int i = 0; i < nuevosProductos.size(); i++) {
            gondola.productos[gondola.cantidad] = nuevosProductos[i];
            gondola.cantidad++;
        }
        cout << "Productos agregados exitosamente." << endl;
    } else {
        cout << "No se pueden agregar mas productos, la gondola esta llena." << endl;
    }
}

Producto buscarProductoPorNombre(const Gondola &gondola, const string &nombre){
    for (int i = 0; i < gondola.cantidad; i++) {
        if (gondola.productos[i].nombre == nombre) {
            return gondola.productos[i];
        }
    }
    cout << "No se encontro el producto " << nombre << endl;
    return {"", "", 0.0, false};
}

Producto buscarProductPorCodigo(const Gondola &gondola, const string &codigo_barras){
    for (int i = 0; i < gondola.cantidad; i++) {
        if (gondola.productos[i].codigo_barras == codigo_barras) {
            return gondola.productos[i];
        }
    }
    cout << "No se encontro el producto con codigo " << codigo_barras << endl;
    return {"", "", 0.0, false};
}
void modificarPrecio(Gondola &gondola, const string &codigo_barras, float nuevoPrecio){
    for (int i = 0; i < gondola.cantidad; i++) {
        if (gondola.productos[i].codigo_barras == codigo_barras) {
            gondola.productos[i].precio = nuevoPrecio;
            cout << "Precio modificado exitosamente." << endl;
            return;
        }
    }
    cout << "No se encontro el producto con codigo " << codigo_barras << endl;
}
void elimiarProducto(Gondola &gondola, const string &codigo_barras){
    vector<Producto> productos_aux(gondola.cantidad - 1);
    int j = 0;
    for (int i = 0; i < gondola.cantidad; i++) {
        if (gondola.productos[i].codigo_barras != codigo_barras) {
            productos_aux[j] = gondola.productos[i];
            j++;
        }
    }

    if (productos_aux.size() < gondola.cantidad) {
        gondola.cantidad--;
        for (int i = 0; i < productos_aux.size(); i++) {
            gondola.productos[i] = productos_aux[i];
        }
        cout << "Producto eliminado exitosamente." << endl;
        return;
    }
    cout << "No se encontro el producto con codigo " << codigo_barras << endl;
}

int cantidadProductosEnOferta(const Gondola &gondola) {
    int cantidad = 0;
    for (int i = 0; i < gondola.cantidad; i++) {
        if (gondola.productos[i].oferta) {
            cantidad++;
        }
    }
    return cantidad;
}

void cobrarProductosEnChango(vector<Producto> chango){
    float total = 0;
    float descuento = 0;

    for (int i = 0; i < chango.size(); i++) {
        total += precioFinal(chango[i]);
        if (chango[i].oferta) {
            descuento += chango[i].precio * 0.1;
        }
    }

    cout << "Total: $" << total << endl;
    cout << "Descuento: $" << descuento << endl;
}