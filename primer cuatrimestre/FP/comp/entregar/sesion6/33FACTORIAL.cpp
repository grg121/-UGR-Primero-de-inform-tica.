#include<iostream>
#include<cmath>
using namespace std;
int main (){
    int entero  ;
    double real ;
    int factorial= 1  ;
    int producto = 2  ;
/* filtro de numeros enteros */

do {
    cout << "Insert a positive whole number: " ;
    cin >> real ;
    entero = abs(real) ;
    } while (real - entero != 0) ;


/* Calcula el factorial de entero */

    if (entero == 0)
        factorial = 1 ;
    else
       while (producto <= entero){
       factorial = factorial * producto ;
       producto ++ ;
       }
    cout << "The " << entero << "\'s factorial is " << factorial ;


    }
