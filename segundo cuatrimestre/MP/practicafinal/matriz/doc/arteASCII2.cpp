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


const int MAXLONG = 10000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);//entera
	} while (s[0]=='\0');
}

int main(){

    char ficheroGrises[MAXLONG];//
    char ficheroImagen[MAXLONG];//
    Imagen origen;
    Lista celdas;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(ficheroImagen);


    // Leer la imagen desde fichero
    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;//si todo ha ido mal, se metera en el if
		return 1;
	} else cout << "Se ha leido la imagen correctamente. " << endl ;

	cout << "Introduzca el nombre de fichero con el conjunto de caracteres: ";
	leelinea(ficheroGrises);
	// Leer cadenas desde fichero
	if (celdas.leerLista(ficheroGrises))//coge y mete en las celdas de la lista celdas, los datos de ficheroImagen(que es el grises.txt)
	{
		cout << "La lista se ha leido correctamente ; " << endl ;
		/* LO QUE HAGO ES que miro si me ha guardado las cadenas de caracteres de grises en las celdas

		int longitud = celdas.longitud() ;

		cout << "longitud: " << longitud<<endl ;

		for(int i=0 ; i<longitud ; i++){
			cout << celdas.getCelda(i) << endl ;//AQUI MIRO SE HA ALMACENADO TODAS LAS LINEAS DE CARACTERES DE grises.txt, 
		}

		cout << "\nend bucle. \n\n" ;
		*/
		if (origen.listaAArteASCII(celdas))//en la imagen origen vamo introducciendo los caracteres ascii que nos proporcionan cada celda
		{
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else
		{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
		//celdas.destruir(); // liberar memoria listas de celdas y no de celda
	}else
	{
		cerr << "Error lista de grises " << ficheroGrises << endl;
	}

    //origen.destruir();   // liberar memoria imagen

}


