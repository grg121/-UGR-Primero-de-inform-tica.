#include <iostream>
using namespace std;


double Max(double un_valor, double otro_valor, double el_tercero) {
    double maximo = un_valor ;
    if (otro_valor > maximo)
        maximo = otro_valor;
    if (el_tercero > maximo)
        maximo = el_tercero ;
    return maximo ;
    }


int main (){


    double primer_valor, segundo_valor, tercer_valor ;
    cout << "Este programa calcula el máximo de tres valores."
         << "\nIntroduce tres numeros reales separados por un espacio: \n" ;
    cin >> primer_valor >> segundo_valor >> tercer_valor;
    double maximo = Max(primer_valor, segundo_valor, tercer_valor);
    cout << "El máximo de estos tres valores es: " << maximo ;

    }//GRG
