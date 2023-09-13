/*
42) Definir un vector Gondola en donde puedan almacenar datos de a lo sumo 50
productos del supermercado. Cada producto se define por su nombre, código de
barras, precio y un indicador si está en oferta o no (si estuviera en oferta al precio
se le debe descontar un 10%).
La aplicación debe permitir mediante un menú de opciones:
a. Cargar productos en el vector.
b. Buscar un producto indicando su nombre.
c. Buscar un producto por código de barra.
d. Poder modificar el precio de algún producto.
e. Quitar un producto que esté en el vector.
f. Indicar la cantidad de productos en oferta.
g. Cargar productos de Gondola en un nuevo vector Chango, indicando
luego: monto a abonar y ahorro total teniendo en cuenta los productos
en oferta
*/
#ifndef GONDOLA_H
#define GONDOLA

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    string codigo_barras;
    float precio;
    bool oferta;
};

struct Gondola {
    vector<Producto> productos;
    int cantidad = 0;

    Gondola() : productos(50) {}
};

void printProducto(Producto producto);
float precioFinal(Producto producto);

void printGondola(const Gondola &gondola);
void cargarProductosEnGondola(Gondola &gondola, const vector<Producto> &nuevosProductos);
Producto buscarProductoPorNombre(const Gondola &gondola, const string &nombre);	
Producto buscarProductPorCodigo(const Gondola &gondola, const string &codigo_barras);
void modificarPrecio(Gondola &gondola, const string &codigo_barras, float nuevoPrecio);
void elimiarProducto(Gondola &gondola, const string &codigo_barras);
int cantidadProductosEnOferta(const Gondola &gondola);
void cobrarProductosEnChango(vector<Producto> chango);
#endif // GONDOLA_H