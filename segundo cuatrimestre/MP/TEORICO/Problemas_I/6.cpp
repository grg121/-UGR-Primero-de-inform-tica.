#include<iostream>
using namespace std;

/* 6. Haz un programa que obtenga la mayor secuencia monótona creciente de un array de enteros,
guardándola en otro array (mediante una función). El array se inicializará de forma explı́cita
en la función main. El programa contendrá además una función para imprimir un array y ası́
poder mostrar el resultado. */

void LecturaDeEnteros(int vector[], int leer){
  // los enteros se almacenan en el vector pasado a la función.
  // se leen tantos enteros como indique el argumento leer.

  for(int i=0 ; i < leer ; i++){
    cin >> vector[i];
  }

}

void MostrarElementos(int v[], int util){
  for(int i=0 ; i < util ; i++){
    cout << v[i] << "-";
  }
}

int MayorSecAsc(int util_entrada, int entrada[], int salida[]){
  int start_aux,
        end_aux,
    final_start = 0 ,
      final_end = 0 ;

    int i = 0 ;

  while(i < util_entrada){
    start_aux = i ;
    while(entrada[i] < entrada[i+1])
      i++ ;
    end_aux = i ;

  if( end_aux - start_aux > final_end - final_start){
    final_end = end_aux ;
    final_start = start_aux ;
  }
 i++ ;
 }
 for(int x = 0, y = final_start ; y <= final_end ; x++, y++){
    salida[x] = entrada[y] ;
 }

 return (final_end - final_start + 1 ) ;
 }

int main(){

  const int MAX = 20 ;

  int original[MAX] ;

  cout << "\nlectura. \n" ;

  int a_leer ;

  cin >> a_leer ;

  LecturaDeEnteros(original, a_leer) ;

  int secuencia[MAX] ;

  int util_out =  MayorSecAsc(a_leer, original, secuencia) ;

  cout << "\nresultado.\n" ;

  MostrarElementos(secuencia, util_out ) ;
}
