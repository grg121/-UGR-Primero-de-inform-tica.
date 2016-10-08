#include<iostream>
using namespace std;

int main(){
  int array[10]  = {1, 3, 9, 10, -4, 7, 4, 9, 2, 120};

  int *min = array ;

  int *max = array ;

  int *lectura = array ;

  for(int i = 0 ; i < 10 ; i++, lectura++){
    if(*lectura > *max)
      max = lectura ;
    if(*lectura < *min)
      min = lectura ;
    }

    cout << "El máximo es: " << *max ;
    cout << endl ;
    cout << "El mínimo es: " << *min ;
    cout << endl ;

    cout << "...Invirtiendo Array... ";

    int aux = 0 ;

    int *right, *left ;

    left = array ;

    right = array + 9 ;

    for(int i = 0; i < 5 ; i++, left++, right--){
      aux = *right ;
      *right = *left ;
      *left = aux ;
    }

    cout << "\nEl array invertido es: " << endl ;

    lectura = array ;

    for (int i = 0 ; i < 10 ; i++, lectura++)
      cout << *lectura << " " ;

  }
