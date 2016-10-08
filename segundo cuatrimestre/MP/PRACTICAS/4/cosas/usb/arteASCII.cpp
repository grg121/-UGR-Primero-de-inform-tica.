//lee imagenes/gio.txt y la convierte en ascii con los conjuntos de caracteres contenidos en nombreConjunto
#include<iostream>
#include<fstream>
#include<imagen.h>


using namespace std;


const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(){
    char grises[MAXLONG];
    char arteASCII[MAXLONG]; 
    char nombreImagen[MAXLONG];
    char nombreConjunto[MAXLONG];
    Imagen origen;
    char nombreFicheroSalida[MAXLONG];
    ifstream fich;
    ofstream fichout;
    int numeroGrises=0,tamanio=0;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(nombreImagen);
	
    // Leer la imagen gio.txt
    if (!origen.leerImagen(nombreImagen)){
		cerr << "error leyendo imagen" << nombreImagen << endl;
	   return 1;
    }
	
	cout << "Introduzca el nombre del fichero con el conjunto de caracteres: ";
	leelinea(nombreConjunto);
 
    //procesar nombreConjunto y generar las conversiones
	cout << "escribe el nombre del fichero de salida: ";
	leelinea(nombreFicheroSalida);
	//abre el fichero de grises	
	fich.open(nombreConjunto);
	if(fich){
		//salta el comentario
		fich.ignore(256,10);
		
		//obtiene el numero de grises
		fich >> numeroGrises;

		//para cada conjunto de grises lo guarda en un fichero con su nombre correspondiente
		while(nombreFicheroSalida[tamanio]!='\0'){
			tamanio++;
		}
		nombreFicheroSalida[tamanio+1]='\0';
		for(int i=0; i<numeroGrises; i++){
			//abre el fichero de salida
			nombreFicheroSalida[tamanio]=i+'0';
			fichout.open(nombreFicheroSalida);
			
			//lee los grises de esta iteracion			
			fich >> grises;
			cout << grises << "| \n";
			
			//lo escrie en el fichero
			if(origen.aArteASCII(grises, arteASCII, MAXLONG-1)){
				fichout << arteASCII;
			}
			else{
				cout << "La conversión no ha sido posible" << endl;
			}
			fichout.close();
		}
		fich.close();		
    	}else{
		cerr << "error leyendo fichero.";
	}
  
      
	
}
