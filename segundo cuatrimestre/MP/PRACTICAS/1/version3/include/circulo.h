#include<iostream>
#include<cmath>
using namespace std;
#include "punto.h"
#ifndef _CIRCULO_H_
#define _CIRCULO_H_

const double PI = 3.141516 ;

struct Circulo{
  Punto centro ;
  double radio ;
} ;

// funciones

void EscribirCirculo(const Circulo &c) ;
Circulo LeerCirculo();
double AreaCirculo(const Circulo &c);

#endif
