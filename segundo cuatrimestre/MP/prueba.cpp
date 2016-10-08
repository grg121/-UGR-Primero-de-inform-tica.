#include<iostream>
using namespace std;

void lee_linea(char c[], int longitud) {
  do{
    cin.getline(c, longitud) ;
  }while(c[0] == '\0') ;
}



struct alumno{
    char nombre[50] ;
    };


int main(){

alumno nuevo ;

lee_linea(nuevo.nombre, 50) ;


cout << nuevo.nombre ;

}
