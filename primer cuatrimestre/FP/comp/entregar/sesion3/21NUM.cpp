/* El usuario introduce un valor entre 0 y 9 y el programa obtiene el correspondiente valor entero, lo asigna a una
variable de tipo int llamada entero y lo imprime en pantalla. */
#include<iostream>
#include<cmath>
using namespace std;
int main (){
	int entero;
	char caracter;
    caracter = '4' ;
    entero = caracter - 48 ;
    // como caracter contiene un caracter encerrado entre comillas, al poner la variable entero en un cout, se imprimirá el valor
    // correspondiente al caracter 4 en el codigo ASCII, en este caso 52. POr tanto, restando a ese 53 48 unidades, obtenemos el mismo
    // valor que el del caracter que, a continuación, se muestra en pantalla.
    cout << caracter ;
}//Por Francisco Navarro Morales
