#include<iostream>
using namespace std;

int SumaDivisoresDe(int numero){
    int suma = 0 ;
    int tope = numero / 2 ;
    for (int divisor = 2 ; divisor <= tope ; divisor ++){
        if (numero % divisor == 0)
            suma += divisor ;
            }
    return suma ;


    }

bool SonAmigos(int numero1, int numero2){

        int suma_de_divisores_1, suma_de_divisores_2 ;

        suma_de_divisores_1 = SumaDivisoresDe(numero1);
        suma_de_divisores_2 = SumaDivisoresDe(numero2);

        bool son_amigos = suma_de_divisores_1 + 1 == numero2 && suma_de_divisores_2 + 1 == numero1 ;
        return son_amigos ;
}


int main (){
    string espacio = "\n\n\n\n\n\n\n\n\n\n\n" ;
    double real1, real2;
    int entero1, entero2;
    double numero_real ;
    int numero ;
    do{
    cout << "\nIntroduce dos numeros naturales (separados por un espacio): ";
    cin >> real1 >> real2;
    entero1 = real1 ;
    entero2 = real2 ;
    }while(real1 - entero1 != 0 || real2 - entero2 != 0 || entero1 < 0 || entero2 < 0);

    bool son_amigos = SonAmigos(entero1, entero2);

    if (son_amigos)
        cout << "Los números introducidos son amigos. ";
    else
        cout << "Los numeros introducidos no son amigos. ";

    cout << espacio ;

    cout << "A continuacion, introduzca un valor n para calcular \nsi existe un número amigo del mismo en un radio de 3.\n" ;
    do{
    cin >> numero_real ;
    numero = numero_real ;
    }while(numero < 0 || numero_real - numero != 0) ;
    int contador = 0 ;
    bool amigos ;
    for (int i = numero -3 ; i <= numero + 3 ; i++){
        amigos = SonAmigos(i, numero) ;
        if (amigos){
            cout << i << " es un amigo de " << numero ;
            contador++ ;
        }
    } cout << "\nhay " << contador << " numeros amigos en el intervalo de radio 3 " ;

}
