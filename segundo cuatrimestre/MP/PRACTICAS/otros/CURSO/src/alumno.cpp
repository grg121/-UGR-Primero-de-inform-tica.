#include<iostream>
#include"alumno.h"
#include"examen.h"

using namespace std;

void NuevoAlumno(alumno entrada){
	cin.get(entrada.nombre,49);
	cin.get(entrada.apellido,49) ;
	entrada.evaluaciones = 0 ;
}

void NumeroExamenes(alumno entrada, int numero){
	entrada.evaluaciones = numero ;
}

void AddExamenes(alumno entrada){
	for(int i = 0 ; i < entrada.evaluaciones ; i++){
		cin.getline(entrada.examenes[i].asignatura,50) ;
	}
	for(int i = 0 ; i < entrada.evaluaciones ; i++){
		cin >> entrada.examenes[i].nota ;
	}
}

double NotaMedia(alumno entrada){
	double media = 0 ;
	for(int i=0 ; i<entrada.evaluaciones ; i++){
		media += entrada.examenes[i].nota ;
	}

	media /= entrada.evaluaciones ;

	return media ;
}

double NotaMax(alumno entrada){
	double max = 0 ;

	for(int i=0 ; i < entrada.evaluaciones ; i++){
		if(entrada.examenes[i].nota > max)
			max = entrada.examenes[i].nota ;
	}
	return max ;
}

double NotaMin(alumno entrada){

	double min = 10 ;

	for(int i=0 ; i<entrada.evaluaciones ; i++){
		if(entrada.examenes[i].nota < min)
			min = entrada.examenes[i].nota ;
	}
	return min ;
}


void ImprimeDatos(alumno entrada){

	cout << "\nNombre: " << entrada.nombre << "\n" ;
	cout << "\nApellidos: " << entrada.apellido ;

	cout << endl ;

	cout << "\nAsignaturas: \n" ;

	for (int i = 0 ; i < entrada.evaluaciones; i++){
		cout << "\t" << entrada.examenes[i].asignatura ;
	}

	cout << "\nNota media: " << NotaMedia(entrada) ;
	cout << "\nNota minima: " << NotaMin(entrada) ;
	cout << "\nNota maxima: " << NotaMax(entrada) ;

	cout << endl ;

}
