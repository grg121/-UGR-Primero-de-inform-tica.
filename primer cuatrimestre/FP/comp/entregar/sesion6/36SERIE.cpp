#include<iostream>
using namespace std;
int main(){
    int base_potencia  , valor_inicial,
        tope, suma     , contador = 0 , elemento_i ;

    /* Se va a crear una serie: ai = b*c^(i-1)
       El usuario introduce los valores de b y c, y un tope, k,  ( i = 0, 1 , 2.... k )
       El programa calcula la sumatoria de los k valores de la serie. */

       cout << "Tenemos una serie de la forma: ai = a1 * c^(i-1) \n"
            << "Introduce un valor inicial (a1) para la serie: \n";
        cin >> valor_inicial ;
       cout << "Introduce un valor para la base de la potencia, c:  \n" ;
        cin >> base_potencia ;
       cout << "El programa calculara la sumatoria de los primeros k valores de la serie. \n"
            << "Introduce un valor para k (un tope): " ;
        cin >> tope ;

        elemento_i = valor_inicial ;
        suma       = valor_inicial ;
        while (contador + 1 != tope) {
            contador++ ;
            elemento_i =  base_potencia * elemento_i ;
            suma = suma + elemento_i ;
            }

        cout << "El resultado de sumar los primeros " << tope << " valores de la serie es :"
             << endl << suma ;

        }



