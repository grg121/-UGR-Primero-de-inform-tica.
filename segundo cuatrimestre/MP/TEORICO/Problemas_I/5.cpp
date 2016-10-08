/* 5. Haz un programa que lea una serie de números enteros (como máximo 100) y
que elimine los elementos repetidos guardándolos en un nuevo array. Debe
contener funciones para leer los elementos de un array, imprimirlo y eliminar
los elementos repetidos. Haz una segunda versión de la función para eliminar los
elementos repetidos de forma que la eliminación de repetidos se haga sobre el
mismo array de v, sin usar un segundo array. Las funciones implementadas
se probarán en la función main. */


#include<iostream>
using namespace std;


void LecturaDeEnteros(int vector[], int leer){
  // los enteros se almacenan en el vector pasado a la función.
  // se leen tantos enteros como indique el argumento leer.

  for(int i=0 ; i < leer ; i++){
    cin >> vector[i];
  }

}

void MostrarElementos(int v[], int util){
  for(int i=0 ; i < util ; i++){
    cout << v[i] << " ";
  }
}

void EliminaRepetidos(int v[], int &util){
  int escritura = 1 ;
  int lectura = 1   ;
  for(lectura = 1 ; lectura < util ; lectura++){
    bool repetido = false ;
    int comprueba = escritura - 1 ;
    while(comprueba >= 0 && !repetido){
      repetido = (v[lectura] == v[comprueba]) ;
      comprueba-- ;
    }

    if(!repetido){
      v[escritura] = v[lectura] ;
      escritura ++ ;
    }
  }  util = escritura ;
}



 int main(){

   int util ;

   const int MAX = 100 ;

   cin >> util ;

   int data[MAX] ;

   LecturaDeEnteros(data, util) ;

   MostrarElementos(data, util) ;

   cout << endl << "SIN REPETIDOS : " ;

   EliminaRepetidos(data, util) ;

   MostrarElementos(data, util) ;



 }
