#include<iostream>
using namespace std;




int main(){

    const int ELEMENTOS = 100;
    char caracteres[ELEMENTOS];

    cout << "Introduce los datos: \n" ;

    char caracter ;

    caracter = cin.get();

    int total_utilizados = 0;

    while( total_utilizados < ELEMENTOS  && caracter != '#'){
        caracteres[total_utilizados] = caracter;
        caracter = cin.get();
        total_utilizados++;
        }


    cout << "\nLos datos han sido recogidos." ;
    cout << "\nHemos recogido " << total_utilizados << " caracteres. \n";

    int ultimo_util = total_utilizados - 1;



    // comprobamos si se trata de un palindromo:


    int j = ultimo_util;
    int i = 0;

    bool es_palindromo = caracteres[i] == caracteres[j];
    int contador=1;

    while ( es_palindromo && contador <= total_utilizados/2){
        j = ultimo_util - i;
        es_palindromo = caracteres[i] == caracteres[j];
        contador++;
        i++;
        }

        if (es_palindromo)
            cout << "\nEl vector es un palindromo" ;
        else
            cout << "\nEl vector no es un palindromo";



    cout << "\nSi le damos la vuelta a los caracteres tenemos: \n";

    for ( int k = ultimo_util ; k >= 0 ; k--)
        cout << caracteres[k] ;


        //contar el numero de mayusculas.

        int mayusculas = 0;

    for (int k = ultimo_util ; k >= 0 ; k--){
        if (caracteres[k] >= 'A' && caracteres[k] <= 'Z')
            mayusculas++;
    }

    cout << "\nEl numero de mayusculas es: " << mayusculas ;

}



