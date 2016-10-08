#include<iostream>
#include<fstream>
#include<pgm.h>
#include<imagen.h>
#include<byte.h>
#include<cstring>
#include <lista.h>
#include<string>
using namespace std;
// CONSTRUCTOR DE INICIALIZACION
Imagen::Imagen(){

	nfilas = 0 ;
	ncolumnas = 0 ;
	datos = 0 ;

}

 Imagen::Imagen(int filas, int columnas)
{
 	crear(filas, columnas);

}

Imagen::~Imagen(){
		if(datos != NULL)
		{
			delete [] datos ;
	  	datos = NULL ;
			nfilas = 0 ;
			ncolumnas = 0 ;
		}
}

void Imagen::crear(int filas, int columnas)
{
	if(datos != 0)
	delete [] datos ;

	nfilas = filas ;
	ncolumnas = columnas ;

	datos = new byte[filas*columnas] ;

	byte *puntero = datos ;

	for(int i = 0 ; i < nfilas * ncolumnas ; i++, puntero++)
	{
		*puntero = 0  ; //ponemos todo las casillas a cero.
	}
}

int Imagen::filas()
   {
	return nfilas ;
   }

 int Imagen::columnas()
   {
	return ncolumnas ;
   }
// En la posicion X,Y se le asigna un dato que contiene v--> (x=3 y=150 le metemos el dato que tenga v=(0--254)), depende el tono que
// le hayamos puesto
void Imagen::set(int y, int x, byte v)// En el pixel de la posición x,y metes el valor de V.
{
	if(datos != NULL)
	datos[y*ncolumnas + x] = v ;
}// es lo mismo que SetPos pero no te dan la i, sino que te dan x e y; y tu calculas i = y*col + x

//Devuelve el dato que contiene datos[] de la posicion que hemos seleccionado mediante x,y
 byte Imagen::get(int y, int x)
{
	return datos[y*ncolumnas + x] ;
}



void Imagen::setPos(int i, byte v)
{
	if( i < ncolumnas * nfilas)
	datos[i] = v ; // es lo mismo que set, pero te dan el valor de i (con i=y*col+x) diréctamente.

}

byte Imagen::getPos(int i)
{
	return datos[i] ;
} // lo mismitico.

//Nos devolvera un booleano diciendo true o false, dependiendo si la imagen se ha cargado correctamente
bool Imagen::leerImagen(const char nombreFichero[])
{

	TipoImagen tipo ;// nos creamos un enum llamado tipo


	// devuelve IMG_DESCONOCIDO o IMG_PGM_BINARIO o IMG_PGM_TEXTO. segun el tipo de archivo que sea
	tipo = infoPGM (nombreFichero,nfilas, ncolumnas) ; //no hace falta poner corchetes, ya esta implementado en la cabecera de la funcion

	crear(nfilas, ncolumnas) ;

	bool salida = false;
// si alguno de los requisitos falla, devuelve false y no carga la imagen. Lo correcto es IMG_PGM_BINARIO y tamaño menor que MAXPIXELS.
	if(tipo == IMG_PGM_BINARIO){
		salida = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas) ; // la funcion leerBinario carga la imagen y guarda en salida si se ha cargado bien (true) o no (false)
	} else if(tipo == IMG_PGM_TEXTO){
		salida = leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas) ;
	}
	return salida ;
}

//Nos indica si se ha escrito/sobrescrito la imagen
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){

	bool salida = false;

 	if(esBinario){
		salida=escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas) ;
	} else{
		salida = escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas) ;
	}

	return salida ;
  }

Imagen Imagen::plano (int k)//La k es la posicion de cada byte de donde quieres sacar el plano.
{
	Imagen nueva;

	nueva.crear(nfilas,ncolumnas);//crear una nueva imagen con el mismo tamaño que la que ya tenemos.

	for(int i = 0 ; i < nfilas*ncolumnas ; i++)
	{
		//nueva.datos[i]=datos[i];
	/*con getbit devuelve el estado de la posicion k de cada byte(bloque),Esta funcion es de byte.cpp (archivo copiado de bloqueLed )*/
		if(getbit(datos[i], k))
		{
			nueva.datos[i]=0x80;//si nos devuelve verdad, es que el dato que hemos comparado esta encendido y
				      //ese dato lo vamos a poner en el bit mas significativo de la ((NUEVA IMAGEN)) a traves de la funcion on
		}		//El i=0 equivale al 7 de un (unsigned char)
		//else
			//off(nueva.datos[i],7);//si nos devuelve falso, apagamos el bit mas significativo(que poreso le pasamos un 0)*/
	}

	return nueva;
}

bool Imagen::aArteASCII(const char grises[],char arteASCII[], int maxlong)
{	//grise[] contiene "@xo."
	// el arteASCII es igual a la original mas una columna.
	bool salida = true ;
	int lectura = 0;
	int escritura = 0 ;
	//int tamanio=1+nfilas*(ncolumnas+1);//1+ es para el barra cero 1="\0", y el otro 1 es pk queremos una columna mas
	//cout<<"tamanio es-->"<<tamanio<<endl;
	//cout<<"malong es-->"<<maxlong<<endl;
	//salida = (tamanio <= maxlong) ; //	POR LO QUE EH VISTO NO TIENE SENTIDO HACER ESTO, PK MAXLONG Y TAMANIO VALEN SIEMPRE IGUAL

//	if (salida) // con este if comprobamos que en el   tamanio sea mas pequeño o igual que maxlong, asi nos aseguramos que cabe y no se
			  //nos repite la imagen dos veces
	//{
		for(int i=0 ; i < nfilas ; i++)
		{
			for(int j=0;j<ncolumnas  ; j++)
			{
				int posicion = datos[lectura]*strlen(grises)/256;// esto nos lo dice el pdf(con eso sabemos un numero y
				//dependiendo el numero que obtega podicion representaremos un caracter u otro )
				arteASCII[escritura] = grises[posicion] ;//dependiendo el dato que tenga pisicion grises cogera un caracter u otro
				lectura++ ;	//cada vez que escribimos en arteASCII[] incrementamos escritura para la nueva posicion y
				escritura++;	//coger nuevo dato par
			}
			arteASCII[escritura] = '\n' ;//al final de cada fila nos dice el pdf que hay que meter un \n(logico para que se
						     //represente bien todo)
			escritura++ ;

				}
			arteASCII[escritura]='\0';


//	}
	return salida;
}


bool Imagen::listaAArteASCII(const Lista celdas){

	bool salida = false ;

	int lenght = 1+nfilas*(ncolumnas+1) ; //tamaño de arteASCII

	char *arteASCII ;

	arteASCII = new char[lenght] ;


	//nota: getCelda(0) devuelve la cabecera.

	int longitud = celdas.longitud() ;//Aqui meto en longuitud, el tamaño total de celdas, osea el numero de cadenas de caracteres que hay
					//en grises.txt
	ofstream fsalida ;//mejor declararla fuera del for, pk solo debe de hacerse una vez

	  for( int i = 0 ; i < longitud  ; i++)
	  { //comprueba que el conjunto de grises no esté vacío.

		/*char nombre[] = "ascii" ;
		char numerico[2] = {'0' + i, '\0'} ;
		strcat(nombre, numerico) ;
		strcat(nombre, ".txt") ;*/
		string nombre;
		nombre="ascii"+ to_string(i)+ ".txt";

		fsalida.open(nombre) ;

	//	arteASCII = new char[lenght] ;

		salida = aArteASCII(celdas.getCelda(i).c_str(),arteASCII,lenght); //aArteASCII devuelve si se ha hecho bien la escritura.
		// en arteASCII se guarda la imagen que ahora vamos a pasar al archivo txt:
		// como vemos, celdas.getCelda(i) lo pasamos a char pk la funcion getCelda nos devuelve un string

		if(salida)
		{
			fsalida << arteASCII ;
   	   	}

		//delete [] arteASCII ;

		fsalida.close() ;


	} 	delete [] arteASCII ;

	return salida ;

}
