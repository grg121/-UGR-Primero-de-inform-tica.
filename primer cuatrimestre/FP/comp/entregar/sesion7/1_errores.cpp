// Errores de las siguientes funciones:
#include<iostream>
using namespace std;

    int ValorAbsoluto (int entero){
        if (entero < 0)
            entero = -entero;
        else
            return entero;
    }
    /*En este ejemplo, al colocar el return dentro del else, si el entero es menor que cero, no devuelve nada.
    lo correcto sería eliminar el "else" :
    */

   void Imprime(double valor){
        double valor
        cout << valor;
    }
    /* Aquí el error radica en declarar la variable "valor" dentro de la definición de la función. Dicha variable ya existe dentro de la función, pues ha
    sido asignada como un parámetro formal. Bastaría con eliminar la linea en que se vuelve a declarar la variable valor para que la función actue correctamente.
    */

    void Cuadrado (int entero) {
        return entero*entero ;

    /*Las funciones void son procesos que NO DEVUELVEN NINGÚN PARÁMETRO. es decir, que es incorrecto usar un void para que la función devuelva el cuadrado
    de un entero. Lo correcto sería sustituir el tipo de función, void, por un int. */

    bool EsPositivo (int valor){
        if (valor > 0)
            return true;
        }

        /*No es correcto que el return forme parte de un condicional, pues en este caso, si el número es negativo o cero, la función no devolvera false.
        Lo correcto sería: */

        bool EsPositivo (int valor){
            bool es_positivo = valor > 0 ;
            return es_positivo ;

        }

