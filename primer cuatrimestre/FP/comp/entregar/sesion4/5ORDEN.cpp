/* 4. El usuario introduce tres valores enteros y el programa informa de si estos estan ordenados de mayor a menor o de menor a mayor */

#include<iostream>
using namespace std;
int main () {
    int primero, segundo, tercero ;
    cout << "Introduce tres numeros enteros separados por un espacio: ";
    cin >> primero >> segundo >> tercero;
    bool primero_mayor_que_segundo ;
    bool segundo_mayor_que_tercero ;
    primero_mayor_que_segundo = (primero > segundo) ;
    segundo_mayor_que_tercero = (segundo > tercero) ;
    cout << "Los datos se han introducido ";
    if (primero_mayor_que_segundo && segundo_mayor_que_tercero)
        cout << "ordenados de mayor a menor.";
    else if (!(primero_mayor_que_segundo || segundo_mayor_que_tercero)) // = (!primero_mayor_que_segundo) && (!segundo_mayor_que_tercero)
        cout << "ordenados de menor a mayor.";
    else
        cout << "desordenados.";
}// Por Francisco Navarro Morales - grg121@
