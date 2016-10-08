#include<iostream>
using namespace std;
// Función factorial de n:
    long long FactorialDe(int n){
        long long factorial=1;
        for (int i = 2 ; i <= n ; i++)
            factorial = factorial * i ;
        return factorial;
        }

int main (){

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


        //Factoriales de n, m y diferencia.

        long long fac_n, fac_m, fac_dif ;

        fac_n = FactorialDe(n);
        fac_m = FactorialDe(m);
        fac_dif = FactorialDe(diferencia);



/* CALCULAMOS EL COMBINATORIO */

    int numerador = fac_n ;
    int denominador = fac_m * fac_dif ;

    int combinatorio = numerador / denominador ;

    cout << "El combinatorio de " << n << " sobre " << m << " es: " << combinatorio ;

    }
