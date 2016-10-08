#include<iostream>
using namespace std;
int main(){
    int minimo, maximo, cifra ;
    cout << "Introduce la cifra que queremos contar: " ;
    cin >> cifra ;
    cout << "Introduce el valor minimo del intervalo en el que buscar: ";
    cin >> minimo ;
    cout << "introduce el valor maximo del intervalo en el que buscar: ";
    cin >> maximo ;
    int contador = 0 ;

    for (int i = minimo ; i <= maximo ; i++)
        for (int numero = i ; numero != 0 ; numero = numero / 10){
            int digito = numero % 10 ;
            if (digito == cifra)
                contador ++ ;
        }

    cout << "en total, el numero de " << cifra << "s en el intervalo es de: " << contador ;

    }
