/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;


const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main()
{


   // char ficheroGrises[MAXLONG];
    char nomb_imagen1[MAXLONG];//ficheroImagen
    char nomb_imagen2[MAXLONG];
    char nomb_imagen_out[MAXLONG];
    Imagen img1,img2,img_out;//origen
    Lista celdas;

	cout << "Introduzca nombre de la imagen1: ";
	leelinea(nomb_imagen1);


    // Leer la imagen desde fichero
    if (!img1.leerImagen(nomb_imagen1)){
		cerr << "Error leyendo imagen 1" << nomb_imagen1 << endl;//si todo ha ido mal, se metera en el if
		return 1;
	} else cout << "Se ha leido la imagen correctamente. " << endl ;


	cout << "Introduzca nombre de la imagen2: ";
	leelinea(nomb_imagen2);


    // Leer la imagen desde fichero
    if (!img2.leerImagen(nomb_imagen2)){
		cerr << "Error leyendo imagen 2" << nomb_imagen2 << endl;//si todo ha ido mal, se metera en el if
		return 1;
	} else cout << "Se ha leido la imagen correctamente. " << endl ;
	
	cout<<"Introduce el nombre del nuevo fichero"<<endl;
	leelinea(nomb_imagen_out);
	img_out= img1 + img2;

	bool esBinario;
	char binario;
	
	cout<< "escriba 'b' si el archivo es binario o 't' si es de texto"<<endl;
	cin>> binario;
	/*while(binario !='b' && binario !='t')
	{
		cout<<"error debes de escribir las opciones b o t"<<endl;
		cin>>binario;
	}*/
	if(binario=='b')
		esBinario=true;
	else 
	{
		if (binario=='t')
		{
			esBinario=false;
		}
		else
			cout<<"debes de introducir b o t"<<endl;
			
	}	
	
	img_out.escribirImagen(nomb_imagen_out,esBinario);
 
 
	return 0; 

}
