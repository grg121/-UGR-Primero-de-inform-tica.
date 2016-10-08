
#include<iostream>
#include<imagen.h>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}


int main(){

	Imagen origen;
	string conjunto,nombre;
	char imagen[MAXLONG] ;
	char archivo_grises[MAXLONG] ;
	

	cout<<"\n\n Introduce el nombre la imagen para cargar"<<endl;
	leelinea(imagen) ;


	cout<<"Introduce el nombre del fichero que contiene los conjuntos de caracteres: "<<endl;
	leelinea(archivo_grises);
	
	ifstream fentrada;

	ofstream fsalida; 

	// lectura de la imagen ;

	if (!origen.leerImagen(imagen))
			{
			   cerr << "error leyendo la imagen\n";
			   return 1;
	   		}

/*Al abrir el archivo, el método open lee un C STRING, luego como tenemos un string, tenemos que convertirlo. */ 

	fentrada.open(archivo_grises) ; 

	char comentario[MAXLONG] ;

	int NRO ;	// el número de grises que se van a leer (y de imagenes a crear) 


	fentrada.getline(comentario, 256,'\n'); // mete en comentario la primera linea del fichero.

	fentrada >> NRO ;  // lee del fichero el número de imagenes a realizar.

	cout << "El comentario era: " << comentario << endl; ; 


	string f ;

	string s = "img" ;

	char numb ; 



	for( int i = 0 ; i < NRO ; i++)
	{

		numb = i ; 

		f = s + numb + ".txt" ;
	
		fentrada >> conjunto ;  // lee los distintos conjuntos de carácteres ; 

		cout << conjunto << endl ;
		

		char arteASCII[66000];

	    		

	    	cout << "\nLa imagen en arte ASCII es:\n";
	    		

		if(origen.aArteASCII(conjunto, arteASCII, 66000)){  //para lena 66000 y caracteres como ((@&%*-._))
	       			// cout << arteASCII;	<-- aqui ya no mostramos en pantalla, sino en un archivo. 

				fsalida.open(f.c_str()) ; 

				fsalida << arteASCII ; 


			}
	    		else
				cout << "La conversión no ha sido posible" << endl;  





	 	
	}


} ; 

