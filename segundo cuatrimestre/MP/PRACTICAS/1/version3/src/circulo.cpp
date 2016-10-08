#include "circulo.h"
// circulo.cpp


void EscribirCirculo(const Circulo &p){
  cout << "\ncentro: " ; EscribirPunto(p.centro) ;
  cout << "\nRadio: " << p.radio ;
}

Circulo LeerCirculo(){
  char basura ; // lee los caracteres - ( , )
  Circulo salida ;

  cin >> salida.radio ;
    cin >> basura ; // -
    cin >> basura ; // (
  cin >> salida.centro.x ;
    cin >> basura ; // ,
  cin >> salida.centro.y ;
    cin >> basura ; // )


return salida ;
}

double AreaCirculo(const Circulo &c){
// salida <-- área.

double salida = PI* pow(c.radio,2) ;

return salida ;
}
/* Fin: circulomedio.cpp */
