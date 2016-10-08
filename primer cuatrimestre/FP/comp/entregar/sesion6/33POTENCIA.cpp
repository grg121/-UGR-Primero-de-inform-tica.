#include<iostream>
using namespace std;
int main (){

    /* POTENCIA DE UN REAL ELEVADO A UN ENTERO A^b */
    /* introducción de datos:                      */

    int exponente, contador ;
    double base   ;
    double exponente_real ;
    double numero_final ;
    cout << "Introduce un número real que funcionará como base de la potencia. ";
    cin >> base   ;
    /* Bluce que actúa como filtro de numeros enteros para el exponente */

    do {
        cout << "\nIntroduce un número entero al que elevar la base: " ;
        cin >> exponente_real;
        exponente = exponente_real;
        }while(exponente_real - exponente != 0);

    /* Fin del filtro || Comenzamos a elevar la base al exponente. */

    if (exponente == 0)
        numero_final = 1 ;

    contador = exponente ;
    numero_final = base ;
        while (contador > 1){
            numero_final = numero_final * base;
            contador-- ;
            }

cout << "El resultado de elevar " << base << " a " << exponente << " es: " << numero_final ;





}
