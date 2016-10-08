#include<iostream>
#include<string>
using namespace std;

#ifndef _PRODUCTO_H_
#define _PRODUCTO_H_

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};


// funciones

string productoToString(Producto a) ;
Producto creaProducto(string nombre, int peso, float precio) ;

#endif
