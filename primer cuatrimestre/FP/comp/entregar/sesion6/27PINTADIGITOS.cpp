#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int entero_in, digito, contador ;
    double entrada_real ;
    bool es_entero ;
    cout << "Introduce un número entero: ";
    /* A continuación un filtro de números enteros. La intención es impedir la introducción de un número real.
    El número entero que usaremos tras el bucle es el que almacenamos en la variable entero_in. */
    do {
    cin >> entrada_real ;
    entero_in = entrada_real ;
    es_entero = (entrada_real - entero_in == 0);
    } while (!es_entero);
    digito = entero_in;

/* A continuacion he añadido un bucle dentro de otro.
El "secundario" (while) obtiene la cifra más a la izquierda.
Una vez hecho esto, el resto del bucle "principal" (do while) imprime el numero en pantalla y lo elimina del numero original (obteniendose un número con una cifra menos).
Repetimos hasta que solo quede una cifra, salimos del bucle e imprimimos esa última cifra. */
    do{ contador = 1;
        while(digito >= 10){
        digito = digito / 10 ;
        contador = contador * 10 ; }

        cout << digito << "   " ;
        entero_in = entero_in - digito * contador;
        digito = entero_in ;
      }while(digito >= 10);
    cout << digito ;
    } // Por Francisco Navarro Morales 1ºF grg121@correo.ugr.es



