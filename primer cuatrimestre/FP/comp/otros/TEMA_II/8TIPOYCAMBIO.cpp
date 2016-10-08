/* El programa lee un caracter. Si es una letra mayúscula, la pasa a minúscula. Si no, lo deja como está.
Finalmente introduce el carácter de salida (haya sido o no convertido) */

#include<iostream>
using namespace std;
enum class TipoCaracter {Mayuscula, minuscula, otro};
int main (){
    TipoCaracter Tipo;
    char letra_original, letra_convertida;
    cout << "Introduce un caracter: " ;
    cin >> letra_original ;
    letra_convertida = letra_original ; // esto nos permite utilizar un condicional simple en lugar de uno compuesto cuyo else solo realice esta asignación.
    const int SALTO = 'a' - 'A' ;
    if (letra_original >= 'A' && letra_original <= 'Z')
        Tipo = TipoCaracter::Mayuscula;
    else if (letra_original >= 'a' && letra_original <= 'z')
        Tipo = TipoCaracter::minuscula;
    else
        Tipo = TipoCaracter::otro;


    switch (Tipo){
        case TipoCaracter::Mayuscula:
        letra_convertida = letra_original + SALTO;
        cout << letra_original << " es una letra mayuscula y su minuscula correspondiente es: ";
        break;
        case TipoCaracter::minuscula:
        letra_convertida = letra_original - SALTO;
        cout << letra_original << " es una letra minuscula y su mayuscula correspondiente es: ";
        break;
        case TipoCaracter::otro:
        cout << "No se ha introducido un caracter alfabetico. El caracter introducido ha sido: ";
        break;}

    cout << letra_convertida;
    }// Por Francisco Navarro - grg@
