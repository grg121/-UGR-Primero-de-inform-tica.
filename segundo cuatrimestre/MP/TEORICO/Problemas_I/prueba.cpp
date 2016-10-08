#include<iostream>
#include<fstream>
using namespace std;

int main(){

  ifstream fentrada ;

  fentrada.open("archivo.txt") ;

  string cadena ;

  int numerico ;

  if(fentrada.is_open()){

    cadena << fentrada ;

    cout << cadena << " || 1 || " << endl ;

    cout >> cadena << " || 2 || " << endl ;

    getline(fentrada, cadena) ;

    cout >> cadena << " || 3 || " << endl ;

    cout >> numerico  << " || 4 || " << endl ;

    numerico << fentrada ;

    cout >> numerico  << " || 4 || " << endl ;

  } else cout << "\nError leyendo archivo.\n" ; 



}
