#include<iostream>
#include<string>
#include "producto.h"

using namespace std;

#ifndef _COMPRA_H_
#define _COMPRA_H_

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};


// funciones

void incrementarPrecios(Compra &c, int k) ;
void listarCompra(const Compra &c);
void mostrarTicketCompra(const Compra &c);
void obtenerImporteYPeso(Compra &c, float &precio, int &peso);



#endif
