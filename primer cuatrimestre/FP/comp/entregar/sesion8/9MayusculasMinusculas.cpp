#include<iostream>
using namespace std;

const double SALTO = 'a' - 'A' ;

enum class TipoDeCaracter {Mayuscula, minuscula, otro};

TipoDeCaracter Capitalizacion(char una_letra){
    TipoDeCaracter tipo_de_caracter;
    if (una_letra >= 'a' && una_letra <= 'z')
        tipo_de_caracter = TipoDeCaracter::minuscula ;
    else if (una_letra >= 'A' && una_letra <= 'Z')
        tipo_de_caracter = TipoDeCaracter::Mayuscula ;
    else
        tipo_de_caracter = TipoDeCaracter::otro ;
    return tipo_de_caracter ;
}

char Convierte_a_Mayuscula(char caracter){
    TipoDeCaracter tipo_de_caracter = Capitalizacion(caracter) ;
    if (tipo_de_caracter == TipoDeCaracter::minuscula)
        caracter = caracter - SALTO ;
    return caracter ;
}

char ConvierteAminuscula(char caracter){
    TipoDeCaracter tipo_de_caracter = Capitalizacion(caracter) ;
    if (tipo_de_caracter == TipoDeCaracter::Mayuscula)
        caracter = caracter + SALTO ;
    return caracter ;
}

char CambiaMayusculaMinuscula(char caracter){
    TipoDeCaracter tipo_de_caracter = Capitalizacion(caracter) ;
    if (tipo_de_caracter == TipoDeCaracter::Mayuscula)
        caracter = ConvierteAminuscula(caracter);
    else if (tipo_de_caracter == TipoDeCaracter::minuscula)
        caracter = Convierte_a_Mayuscula(caracter);
    return caracter;
}

int main(){
    char caracter;
    cout << "Introduce un caracter desde el teclado: " ;
    cin >> caracter;

    cout << "Si el caracter es una letra mayuscula, la convertiremos en minuscula."
         << "\nSi el caracter es una letra minuscula, la convertiresmo en mayuscula."
         << "\nSi el caracter no es una letra, lo dejaremos como estaba.\n\n\n";

    caracter = CambiaMayusculaMinuscula(caracter) ;

    cout << "Salida: " << caracter << "\n\n\n";
}
