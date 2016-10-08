#include<iostream>
#include"alumno.h"
#include"examen.h"
using namespace std;

int main(){
int numero = 0 ;
alumno primero ;

cout << "\nIntroduce los siguientes datos. Pulsa enter entre dato y dato. \n"
     << "Nombre. Apellidos. Número de examenes. \n nombre de la asignatura"
     << "(tantas veces como examenes). Nota del examen (Tantas veces como examenes)." ;
NuevoAlumno(primero) ;
cin >> numero ;
NumeroExamenes(primero, numero) ;
AddExamenes(primero) ;

ImprimeDatos(primero);


}
