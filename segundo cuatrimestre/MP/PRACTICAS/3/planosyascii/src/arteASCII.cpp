
#include<iostream>
#include<imagen.h>
#include<string>
#include<cstring>
using namespace std;


const int MAX = 500 ;


void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}


int main(){

	Imagen origen;

	char archivo_imagen[MAX] = "imagenes/gio.pgm" ;

	char conjunto_grises[MAX] = ".01" ;

  char arteASCII[90000];


		if (!origen.leerImagen(archivo_imagen)){
	   		cerr << "error leyendo la imagen\n";
	  		return 1;
   		}

   		if(origen.aArteASCII(conjunto_grises, arteASCII, 90000))  //para lena 66000 y caracteres como ((@&%*-._))



    		else
        	cout << "La conversión no ha sido posible" << endl;
