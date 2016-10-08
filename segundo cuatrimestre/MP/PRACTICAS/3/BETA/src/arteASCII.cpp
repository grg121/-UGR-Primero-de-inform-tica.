
#include<iostream>
#include<imagen.h>
#include<string>
#include<cstring>
using namespace std;

int main(){

	Imagen origen;
	string conjunto,nombre;
	cout<<"Introduce el conjunto de caracteres para realizar la conversion"<<endl;
	do
	{
		getline(cin,conjunto);

	}while(conjunto=="");

    char grises[conjunto.length()+1];
	strcpy(grises,conjunto.c_str());


    char arteASCII[90000]; // 4500 + el \0


	cout<<"\n\n Introduce el nombre del archivo para cargar"<<endl;
	do
	{
		getline(cin,nombre);

	}while(nombre=="");

	char nom_archivo[nombre.length()+1];
	strcpy(nom_archivo,nombre.c_str());

    // Leer la imagen

    if (!origen.leerImagen(nom_archivo)){
	   cerr << "error leyendo la imagen\n";
	   return 1;
    }



    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 90000))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;




}
