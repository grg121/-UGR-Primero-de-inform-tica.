#include "punto.h"
// Punto.cpp

void EscribirPunto(const Punto &p){
  cout << "(" << p.x << "," << p.y << ") " ;
}

Punto LeerPunto(){
  Punto salida ;
  cin >> salida.x ;
  cin >> salida.y ;

  return salida ;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2){
  /**
  * cto <-- cateto.
  * salida <-- distancia.
  **/

  double cto1 = p2.x - p1.x ;
  double cto2 = p2.y - p1.y ;

  double salida = sqrt(pow(cto1,2)+pow(cto2,2)) ;

  return salida ;
}

Punto PuntoMedio(const Punto &p1, const Punto &p2){
  /**
  * ho <-- distancia horizontal de p1 a salida. (sumar a p1.x)
  * ve <-- distancia vertical de p2 a salida. (restar a p2.y)
  **/

  double ho = (p2.x - p1.x)/2 ;
  double ve = (p2.y - p1.y)/2 ;

  Punto salida = {p1.x+ho, p2.y-ve} ;

  return salida ;
}
