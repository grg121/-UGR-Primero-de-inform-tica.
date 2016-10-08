#include<iostream>
#include"head.h"
using namespace std;


void lee_linea(char c[], int longitud) {
  do{
    cin.getline(c, longitud) ;
  }while(c[0] == '\0') ;
}
