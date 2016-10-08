#include<iostream>
#include"Fecha.h"
#include"Hora.h"
#include"Instante.h"
#include"Punto.h"
#include"Recorrido.h"

int main(){

  Recorrido viaje(false) ;

  PuntoDeRecorrido PR ;

  for(int i = 0 ; i < 5 ; i++){
    Punto P(9.2+i,11.1-i,2.0*i) ;

    PR.punto = P ;

    Hora h(10 + i, 23-2*i, 59-3*i) ;

    Fecha f(23,03,1997) ;

    Instante inst(f,h) ;

    PR.instante = inst ;

    viaje.AgregarPunto(PR) ;
  }

  viaje.escritura("viaje.txt") ;



}
