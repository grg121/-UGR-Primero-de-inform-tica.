// eco.cpp 
#include<iostream>
#include<fstream>
using namespace std;
int main(){

	ifstring F1; 

 	string s = "grises.txt" ;

	char comentario[256] ;

	int NRO ;	// el número de grises que se van a leer (y de imagenes a crear) 

	string cadena ;

// abrimos el fichero:

	
	/*Al abrir el archivo, el método open lee un C STRING, luego como tenemos un string, tenemos que convertirlo. */ 

	F1.open(s.c_str()) ;

	F1.getline(comentario, 256) // con este método nos comemos la primera linea ;

	F1 >> NRO ; 

	for( int i = 0 ; i < NRO ; i++){
	
		F1 >> cadena ; 

		cout << cadena ; 

	} ; 


cout << "El comentario era: " << comentario ; 
