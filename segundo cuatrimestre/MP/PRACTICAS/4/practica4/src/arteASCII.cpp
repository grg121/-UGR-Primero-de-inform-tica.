
#include<iostream>
#include<imagen.h>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;


const int MAX = 500 ;


void leelinea(char *s){
	do{
		cin.getline(s, MAX);
	} while (s[0]=='\0');
}


int main(){

	ifstream fentrada ;
	ofstream fsalida ;

	Imagen origen;

	int NRO = 0 ;

	char comentario[MAX] ;
	char archivo_imagen[MAX] = "imagenes/gio.pgm" ;
	char conjunto_grises[MAX] = ".01" ;
  char arteASCII[90000];
	char archivo_grises[MAX] ;
	char archivo_salida[MAX] ;
	char txt[MAX] = ".txt" ;


	cout << "Introduzca nombre de la imagen: ";
	leelinea(archivo_imagen);

	cout << "Introduzca el nombre del fichero con el conjunto de caracteres: ";
	leelinea(archivo_grises);

	fentrada.open(archivo_grises) ; // abre el archivo con los conjuntos de grises.

	cout << "escribe el nombre del fichero de salida: ";
	leelinea(archivo_salida);

	fentrada.getline(comentario,MAX) ;

	fentrada >> NRO ;

	/* Lee la imagen */

		if (!origen.leerImagen(archivo_imagen)){
	   		cerr << "error leyendo la imagen\n";
	  		return 1;
   		}



			for( int i = 1 ; i <= NRO ; i++){

				fentrada >> conjunto_grises ;

			char nombre[MAX] = "" ; // creamos nombre vacía.

			strcat(nombre, archivo_salida) ;
			// le añadimos el nombre de salida. PEj: salida.

			char numerico[2] = {'0' + i, '\0'} ;

			/* creamos un char que contiene el caracter 0 + i
		importante poner el \0 al final para que funcione como un
		C_STRING */

		strcat(nombre, numerico) ; //añadimos el numerico al nombre

		strcat(nombre, txt) ; // y el .txt

		fsalida.open(nombre) ; // abre el archivo a escribir



   	if(origen.aArteASCII(conjunto_grises, arteASCII, 90000)){
				 fsalida << arteASCII ;
			 }

		else
        	cout << "La conversión no ha sido posible" << endl;


									fsalida.close() ;
									// importante el close antes de cada open.
				}


/*RECUERDA CERRAR LOS FSTREAM */


					fentrada.close() ;





}
