/* El programa lee unos valores de entrada para la edad y el salario de un individuo.
Si la edad es mayor de 65 y el salario menor de 300, aplica un aumento del 5% al salario del individuo. */

#include<iostream>
using namespace std;
int main (){
    int edad ;
    double salario ; // entrada
    cout << "Introduce la edad del individuo: " ;
    cin >> edad ;
    cout << "Introduce el salario del individuo (en euros/mes): ";
    cin >> salario ;
    const double INCREMENTO = 0.05 ;
    double salario_incrementado; // salida
    salario_incrementado = salario + INCREMENTO * salario ;
    bool valido ; // Se considera válido a un usuario si cumple las condiciones para que se aplique el incremento de salario.
    valido = edad > 65 && salario < 300 ;

    if (valido){
        salario = salario_incrementado;
        cout << "El salario se incrementará hasta un valor de: " << salario << " euros." ;}
    else
        cout << "\nNo es aplicable la subida.";



    }//Por FRancisco Navarro Morales. grg121@correo.ugr.es

