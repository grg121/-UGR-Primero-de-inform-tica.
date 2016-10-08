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

int main(int argc, char*argv[])
{


   // char ficheroGrises[MAXLONG];
    char *nomb_imagen1;//ficheroImagen
    char *nomb_imagen2;
    char *nomb_imagen_out;
    Imagen img1,img2,img_out,img_aux;//origen
    Lista celdas;
    bool esBinario;
	char binario;
 if(argc>=4)//son los cuatro parametros que vamos a meter, mas 1 siempre
 {
 	nomb_imagen1=argv[2];
 	//nomb_imagen2=argv[2];
 	nomb_imagen_out=argv[1];
 	//binario=*argv[4];//esta es la manera de pasarselo tambien por parametro en el terminar pero deberiamos de poner en ese caso argc==5
 	binario='b';

	/*cout << "Introduzca nombre de la imagen1: ";
	leelinea(nomb_imagen1);*/

    // Leer la imagen desde fichero
    if (!img_aux.leerImagen(nomb_imagen1))
    {
		cerr << "Error leyendo imagen " << nomb_imagen1 << endl;//si todo ha ido mal, se metera en el if
		return 1;
	}
	else cout << "Se ha leido la imagen correctamente. " << endl ;

	for(int i = 0 ; i < argc - 3 ; i++){
			nomb_imagen2 = argv[3+i] ;
			img1 = img_aux ;
/*	cout << "Introduzca nombre de la imagen2: ";
	leelinea(nomb_imagen2);*/


    // Leer la imagen desde fichero
    if (!img2.leerImagen(nomb_imagen2))
    {
		cerr << "Error leyendo imagen " << nomb_imagen2 << endl;//si todo ha ido mal, se metera en el if
		return 1;
	} else cout << "Se ha leido la imagen correctamente. " << endl ;

/*	cout<<"Introduce el nombre del nuevo fichero"<<endl;
	leelinea(nomb_imagen_out);*/

	img_aux = img1 + img2;

}

img_out = img_aux ; 


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
	cout << "La suma se ha realizado. Comprueba el resultado." ;
 }
 else
 	cout<<"Numero de parametros introducido es incorrecto"<<endl;


 return 0;

}
