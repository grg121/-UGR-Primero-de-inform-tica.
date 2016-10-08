#include<iostream>
using namespace std;



bool EsMayuscula(char letra){
    bool Mayuscula = letra >= 'A' && letra <= 'Z' ;
    return Mayuscula ; }

int main(){

    const int NUMERO_DE_LETRAS = 26; // se establece un maximo de 26 letras de acuerdo con el número de mayusculas del código ASCII

    /*Utilizamos dos vectores relacionados entre sí. El primer vector contiene las letras de la A a la Z y el segundo, el número de veces que aparece la letra que corresponde a esa posición. */

    char vector_letras[NUMERO_DE_LETRAS];

    int vector_count[NUMERO_DE_LETRAS] = {0};



    for (int i = 'A', k = 0; i <= 'Z' ; i++, k++)
        vector_letras[k] = i ;


    cout << "\nIntroduce un conjunto de carácteres acabado en punto. \n";

    int posicion;
    char caracter;


    do{
        caracter = cin.get();
        if (EsMayuscula(caracter)){
            posicion = 0 ;
            while (vector_letras[posicion] != caracter)
                posicion++;
            vector_count[posicion]++;
        }
    } while (caracter != '.');

    for (int i = 0 ; i < NUMERO_DE_LETRAS ; i++){
        cout << "\nEl caracter " << vector_letras[i] << " aparece " << vector_count[i] << " veces. \n";
        }






    }
