#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int numero_inicial, numero_util,
        numero_de_cifras = 1, digito_util,
        posible_narcisista = 0, contador;

    cout << "Insert a Whole number (Example: 4259) in order to find out if it is a narcissistic number. \n";
    cin >> numero_inicial;

    numero_util = numero_inicial;

    /* Este bucle calcula el número de cifras del número introducido. *Nota: el número inicial de cifras es 1. */

    while (numero_util >= 10){
        numero_de_cifras++ ;
        numero_util = numero_util / 10 ;
    }

    /* Este bucle calcula el numero resultante de sumar los digitos del numero inicial elevado al numero de cifras del mismo. */

    for (contador = 0; contador == numero_de_cifras ; contador ++){
        digito_util = numero_util % 10 ;
        posible_narcisista = posible_narcisista + pow(digito_util,numero_de_cifras) ;
        numero_util = numero_util / 10 ;
        }

    bool es_narcisista = posible_narcisista == numero_inicial ;

    cout << posible_narcisista;

    }
