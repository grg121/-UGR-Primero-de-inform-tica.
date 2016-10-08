#include<iostream>
using namespace std;
int main(){
    int tope ;
    cout << "Introduce un numero entero que sera el tope \n(buscaremos numeros triangulares menores que el): " ;
    cin >> tope ;

    int triangular = 1 ,
        i = 1          ;


    cout << "numeros triangulares menores que " << tope << ": ";
    while (triangular < tope){
        cout << triangular << endl;
        i++                ;
        triangular = triangular + i ;
        }

}
