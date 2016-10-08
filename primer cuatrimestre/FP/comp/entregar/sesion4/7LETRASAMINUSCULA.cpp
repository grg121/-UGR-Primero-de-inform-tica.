/* El programa lee un caracter. Si es una letra mayúscula, la pasa a minúscula. Si no, lo deja como está.
Finalmente introduce el carácter de salida (haya sido o no convertido) */

#include<iostream>
using namespace std;
int main (){
    char letra_original, letra_convertida;
    cout << "Introduce un caracter: " ;
    cin >> letra_original ;
    letra_convertida = letra_original ; // esto nos permite utilizar un condicional simple en lugar de uno compuesto cuyo else solo realice esta asignación.
    const int SALTO = 'a' - 'A' ;
    bool es_mayuscula = (letra_original >= 'A' && letra_original <= 'Z');
    bool es_minuscula = (letra_original >= 'a' && letra_original <= 'z');
    if (es_mayuscula){
        letra_convertida = letra_original + SALTO ;
        cout << letra_original << " es una letra mayuscula y su minuscula correspondiente es: ";}
    else if (es_minuscula){
        letra_convertida = letra_original - SALTO;
        cout << letra_original << " es una letra minuscula y su mayuscula correspondiente es: ";}
    else
        cout << "No se ha introducido un caracter alfabetico. El caracter introducido ha sido: ";
    cout << letra_convertida;
    }
