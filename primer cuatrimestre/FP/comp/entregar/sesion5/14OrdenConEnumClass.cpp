/*  El usuario introduce tres valores enteros y el programa informa de si estos estan ordenados de mayor a menor o de menor a mayor */

#include<iostream>
using namespace std;
enum class TipoDeOrden
        {MayorAmenor,menoraMayor,Ninguno} ;
int main () {
    int primero, segundo, tercero;
    cout << "Introduce tres numeros enteros separados por un espacio: ";
    cin >> primero >> segundo >> tercero;
    TipoDeOrden orden;
    cout << "Los datos se han introducido ";
    if (primero > segundo && segundo > tercero)
        orden = TipoDeOrden::MayorAmenor;
    else if (tercero > segundo && segundo > primero)
        orden = TipoDeOrden::menoraMayor;
    else
        orden = TipoDeOrden::Ninguno;

    switch (orden){
        case TipoDeOrden::MayorAmenor:
            cout << "de mayor a menor.";
            break;
        case TipoDeOrden::menoraMayor:
            cout << "de menor a mayor.";
            break;
        case TipoDeOrden::Ninguno:
            cout << "sin ningn tipo de orden.";
            break;
            }
}// Por Francisco Navarro Morales - grg121@
