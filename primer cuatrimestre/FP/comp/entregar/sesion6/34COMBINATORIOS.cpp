#include<iostream>
using namespace std;
int main(){
   int n, m ;
   double n_real, m_real ;


   cout << "Vamos a calcular el combinatorio de n sobre m \n"
        << "                       n debe ser mayor que m \n";

        do {
    cout << "Introduce un valor (positivo y entero) para n: ";
    cin >> n_real ;
    n = n_real ;
    } while (n_real - n != 0 || n_real < 0) ;

    do{
   cout << "Introduce un valor (positivo, entero y menor que el de n) para m: ";
    cin >> m_real;
    m = m_real ;
    }while(m > n || m_real - m != 0 || m_real < 0);


    int diferencia = n - m ;

   /* Factorial de n */

    int factorial_n= 1  ;
    int producto_n = 2  ;


    if (n == 0)
        factorial_n = 1 ;
    else
       while (producto_n <= n){
       factorial_n = factorial_n * producto_n ;
       producto_n ++ ;
       }

    /* Factorial de m */


    int factorial_m = 1  ;
    int producto_m = 2  ;


    if (m == 0)
        factorial_m = 1 ;
    else
       while (producto_m <= m){
       factorial_m = factorial_m * producto_m ;
       producto_m ++ ;
       }

    /* Factorial de la diferencia de n y m */

    int factorial_diferencia = 1  ;
    int producto_diferencia = 2  ;


    if (diferencia == 0)
        factorial_diferencia = 1 ;
    else
       while (producto_diferencia <= diferencia){
       factorial_diferencia = factorial_diferencia * producto_diferencia ;
       producto_diferencia ++ ;
       }

/* CALCULAMOS EL COMBINATORIO */

    int numerador = factorial_n ;
    int denominador = factorial_m * factorial_diferencia ;

    int combinatorio = numerador / denominador ;

    cout << "El combinatorio de " << n << " sobre " << m << " es: " << combinatorio ;



    }

