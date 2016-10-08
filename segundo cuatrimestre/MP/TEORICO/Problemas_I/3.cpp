/* 3. Haz un programa que lea un conjunto de números enteros (como máximo 100), los guarde en un
array e indique cuál es el mayor de todos. Tanto la lectura de los elementos del array como el
cálculo del máximo se harán mediante funciones. Debe incluirse un programa principal (main)
para probar las funciones implementadas. */

#include<iostream>
using namespace std;


void LecturaDeEnteros(int vector[], int leer){
  // los enteros se almacenan en el vector pasado a la función.
  // se leen tantos enteros como indique el argumento leer.

  for(int i=0 ; i < leer ; i++){
    cin >> vector[i];
  }

}

int CalculaMaximo(int vector[], int util){
  int maximo = 0 ;
  for(int i=0 ; i < util ; i++){
    if(vector[i] > maximo)
      maximo = vector[i] ;
  } return maximo ;
}


int main(){
  const int MAX = 100 ;
  int v[MAX] ;
  int a_leer = 0 ;
  cout << "\nNúmero de enteros a leer: " ;
    cin >> a_leer ;

  cout << "\nIntroduce los enteros. \n " ;

  LecturaDeEnteros(v,a_leer) ;

  cout << "\nEl máximo es: " << CalculaMaximo(v,a_leer) << endl ;
}
