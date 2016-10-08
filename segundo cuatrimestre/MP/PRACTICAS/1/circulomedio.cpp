/* Programa que calcula un círculo con centro en medio de dos círculos y radio la mitad de la distancia.
   También calcula su área.

   Author: MP
   Módulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecución es:
     Introduzca un circulo en formato radio-(x,y): 3-(0,0)
     Introduzca otro circulo: 4-(5,0)
     El círculo que pasa por los dos centros es: 2.5-(2.5,0)
	 Su area es: 19.63
**/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359 ;

// Definición de las estructuras
struct Punto {
    double x;
    double y;
};

struct Circulo {
    Punto centro;
    double radio;
};

// Prototipos de las funciones
void EscribirPunto(const Punto &p);
Punto LeerPunto();
double DistanciaPuntos(const Punto &p1, const Punto &p2);
Punto PuntoMedio(const Punto &p1, const Punto &p2);

void EscribirCirculo(const Circulo &c);
Circulo LeerCirculo();
double AreaCirculo(const Circulo &c);

// Programa principal
int main()
{
    Circulo c1,c2, c3;

    do {
        cout << "Introduzca un circulo en formato radio-(x,y): ";
        c1 = LeerCirculo();

        cout << "Introduzca otro circulo: ";
        c2 = LeerCirculo();
    } while ( DistanciaPuntos (c1.centro,c2.centro) == 0 );

    c3.centro = PuntoMedio( c1.centro, c2.centro );

    c3.radio = DistanciaPuntos( c1.centro, c2.centro ) / 2;

    cout << "El circulo que pasa por los dos centros es: ";
	EscribirCirculo( c3 );
    cout << endl << "Su area es: " << AreaCirculo( c3 ) << endl;
}

// Implementación de las funciones
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
