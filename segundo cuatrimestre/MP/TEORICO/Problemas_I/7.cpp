/* 7. Haz un programa que lea un texto desde cin y que, al finalizar la entrada de datos, muestre
cuántas veces aparece cada letra (a..z), teniendo en cuenta lo siguiente:
• la entrada de datos finaliza con el carácter #.
• no se diferenciarán mayúsculas y minúsculas.
• el texto se lee carácter a carácter en una función que guarda los caracteres en un array de
char recibido como parámetro.
• usaremos una función que reciba como parámetro un array de caracteres y construya un
array de enteros con la frecuencia para cada carácter.*/

#include<iostream>
using namespace std;

void EscribirTexto(char entrada[]){
  int r = 0 ;
  while(entrada[r] != '#'){
    cout << entrada[r] ;
    r++ ;
  }
}

void Afrecuencias(char entrada[], int salida[24]){
  char lectura ;
  int r = 0 ; // variable de lectura Read.

  for(int i = 0 ; i < 24 ; i++){
    salida[i] = 0 ;
  } // nos aseguramos que salida contiene solo 0.

  while(entrada[r] != '#'){
  int c = r ; // comparador ;
  int contador = 1 ;
  if(salida[entrada[r] - 'a'] == 0){
    while(entrada[c] != '#'){
      if(tolower(entrada[r]) == tolower(entrada[c]))
        contador++ ;
        c++ ;
    }
    salida[entrada[r] - 'a'] = contador ;
  }
    r++ ;
  }

  }



void LeerTexto(char texto[]){
  char lectura ;
  int  w = 0 ; // Write -- variable de escritura.
  cin.get(lectura) ;
  while(lectura != '#'){
    texto[w] = lectura ;
    w++ ;
    cin.get(lectura) ;
  }texto[w] = lectura ;
}

void EscribirFrecuencias(int frecuencias[]){
  char letra = 'a' ;
  for(int i = 0 ; i < 24 ; i++, letra++){
    cout << ";   " << letra << ": " << frecuencias[i] ;
  }
}

int main(){



const int MAXR = 100 ; // máximo de carácteres a leer.

char texto[MAXR] ;

int frecuencias[24] ;

cout << "Lectura del texto. " ;

LeerTexto(texto) ;

cout << "\nEl texto introducido ha sido : \n\n\t" ;

EscribirTexto(texto) ;

Afrecuencias(texto, frecuencias) ;

cout << "\n\n Y las frecuencias to chungas: " ;

EscribirFrecuencias(frecuencias) ;


}
