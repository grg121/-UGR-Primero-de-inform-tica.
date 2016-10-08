// copiar archivo de texto.

#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char * argv[]){
  // el primer argumento es el archivo de lectura
  // el segundo argumento es el archivo de escritura

  if(argc==3){
    ifstream entrada(argv[1]);
    if(entrada.fail()){
      cerr << "No se ha podido abrir el archivo " << argv[1] << endl ;
      return 1 ;
    }
   ofstream salida(argv[2]) ;
   if(salida.fail()){
     cerr << "No se ha podido abrir el archivo " << argv[2] << endl ;
     return 1 ;
   }

   if(salida.is_open() && entrada.is_open()){
     char c ;
     while(entrada.get(c))
      salida.put(c) ;

     if(!entrada.eof()){
      cerr << "La copia no se ha realizado correctamente " << endl ;
      return 1 ;
     }
   } return 0 ;

 } else{
   cerr << "El número de argumentos es incorrecto " << endl ;
   return 1 ;
   }

 }
