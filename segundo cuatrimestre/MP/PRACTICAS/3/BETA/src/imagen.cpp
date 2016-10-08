#include<iostream>
#include<pgm.h>
#include<imagen.h>
#include<byte.h>
#include<cstring>
using namespace std;
// CONSTRUCTOR DE INICIALIZACION
Imagen::Imagen(){

	nfilas = 0 ;
	ncolumnas = 0 ;
}

//Esto es un CONSTRUCTOR POR PARAMETROS--> Imagen I(7,5);
 Imagen::Imagen(int filas, int columnas)
{
 	crear(filas, columnas);

}

void Imagen::crear(int filas, int columnas)
{

	nfilas = filas ;
	ncolumnas = columnas ;

	for(int i = 0 ; i < nfilas * ncolumnas ; i++)
	{
		datos[i] = 0  ; //ponemos todo las casillas a cero.
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
	datos[y*ncolumnas + x] = v ;
}// es lo mismo que SetPos pero no te dan la i, sino que te dan x e y; y tu calculas i = y*col + x

//Devuelve el dato que contiene datos[] de la posicion que hemos seleccionado mediante x,y
 byte Imagen::get(int y, int x)
{
	return datos[y*ncolumnas + x] ;
}



void Imagen::setPos(int i, byte v)
{
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

	bool salida = false;
// si alguno de los requisitos falla, devuelve false y no carga la imagen. Lo correcto es IMG_PGM_BINARIO y tamaño menor que MAXPIXELS.
	if(tipo == IMG_PGM_BINARIO && (nfilas * ncolumnas < MAXPIXELS)){
		salida = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas) ; // la funcion leerBinario carga la imagen y guarda en salida si se ha cargado bien (true) o no (false)
	} //else salida = false ; //si tipo no contiene (IMG_PGM_BINARIO), o el tamaño es superior al prermitido, nos vamos al else

	return salida ;
}

//Nos indica si se ha escrito/sobrescrito la imagen
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){

	bool salida = false;

 	if(esBinario){
		salida=escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas) ;
	}//(else salida = false ;

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
	bool salida = false ;
	int lectura = 0;
	int escritura = 0 ;
	int tamanio=1+nfilas*(ncolumnas+1);//1+ es para el barra cero, y el otro 1 es pk queremos una columna mas
	salida = (tamanio < maxlong) ;
	if (salida) // con este if comprobamos que en el momento que tamanio sea mas grande que maxlong, asi no se nos repite la imagen dos veces
	{
		for(int i=0 ; i < nfilas ; i++)
		{
			for(int j=0;j<ncolumnas  ; j++)
			{
				int posicion = datos[lectura]*strlen(grises)/256;
				arteASCII[escritura] = grises[posicion] ;
				lectura++ ;
				escritura++;
			}
			arteASCII[escritura] = '\n' ;
			escritura++ ;
			arteASCII[escritura]='\0';
		}

	}
	return salida ; 
}
