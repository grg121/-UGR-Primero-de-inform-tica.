
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
	char archivo_imagen[MAX];
	char conjunto_grises[MAX];
	char archivo_grises[MAX] ;
	char archivo_salida[MAX] ;
	//char txt[MAX] = ".txt" ;

	char *arteASCII ;


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

		if (!origen.leerImagen(archivo_imagen))
		{
	   		cerr << "error leyendo la imagen\n";
	  		return 1;
   		}

			int lenght = 1+origen.filas()*(origen.columnas()+1) ;

			arteASCII = new char[lenght] ;

		for( int i = 1 ; i <= NRO ; i++)
		{

				fentrada >> conjunto_grises ;//cogemos nº[i]linea de caracteres de grises.txt y la almacenamos en conjunto_grises

			string nombre; // creamos nombre vacía.
			nombre=archivo_salida + to_string(i) + "txt";//creamos el nombre del archivo de salida
			
			
			fsalida.open(nombre) ; // abre el archivo a escribir

   			if(origen.aArteASCII(conjunto_grises, arteASCII, lenght))
   			{
				 fsalida << arteASCII ;// si se ha podico convertir la imagen.pgm a caracteres ascii y guardarse en arteASCII pues al 
				 						//fichero de salida que guardamos los datos.
			}

			else
        	{
        		cout << "La conversión no ha sido posible" << endl;
			}

			fsalida.close() ;
									// importante el close antes de cada open.
		}


/*RECUERDA CERRAR LOS FSTREAM  y liberar memoria. */


			fentrada.close() ;

			delete [] arteASCII ;
			
			origen.destruir() ;







}
