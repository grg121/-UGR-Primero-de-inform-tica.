/* 4. Haz un programa que lea una serie de números enteros (como máximo 100), los guarde en un
array y que lo invierta, mostrando el resultado. Si la secuencia introducida es 1, 100, 34, 48,
153, entonces el resultado final mostrado debe ser 53, 48, 34, 100, 1. Deberá contener funciones
para: lectura de los elementos del array, mostrar los elementos del array en la salida estándar
e invertir los elementos de un array. Se implementará la función main para probar que todo
funciona de forma correcta. */

#include<iostream>
using namespace std;


void LecturaDeEnteros(int vector[], int leer){
  // los enteros se almacenan en el vector pasado a la función.
  // se leen tantos enteros como indique el argumento leer.

  for(int i=0 ; i < leer ; i++){
    cin >> vector[i];
  }

}

void InvierteArray(int v[], int util){
  int aux ;
  for(int i=0, j=util-1 ; i < util/2 ; i++, j--){
    aux = v[i] ;
    v[i] = v[j] ;
    v[j] = aux ;
  }
}

void MostrarElementos(int v[], int util){
  for(int i=0 ; i < util ; i++){
    cout << v[i] << " ";
  }
}

int main(){

  const int MAX = 100 ;

  int v[MAX] ;

  int util = 0 ;

  cout << "\nNúmero de enteros a trabajar: " ;
    cin >> util ;

    LecturaDeEnteros(v,util) ;

    cout << "\nHas introducido: " ;

    MostrarElementos(v, util) ;

    InvierteArray(v,util) ;

    cout << "\nInvertido: " ;

    MostrarElementos(v, util) ;

    cout << endl ;




}
