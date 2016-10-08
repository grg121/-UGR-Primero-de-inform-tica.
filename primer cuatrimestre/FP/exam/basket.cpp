// NOMBRE:
// PROBLEMA: Baloncesto

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Constantes globales
const char EQUIPO_A = 'A';
const char EQUIPO_B = 'B';
const char FIN = 'S';

enum class Final {GANAA, GANAB, EMPATE};

// funcion: Muestra mensaje proporcionado y leer (un char) equipo de E/.
// salida : Un equipo ya filtrado (A, B, o terminador).
char leerEquipo (string mensaje) {

	char equipo;

	do {
		cout << mensaje;
		cin >> equipo;
		equipo = toupper(equipo);
	} while (equipo != EQUIPO_A && equipo != EQUIPO_B && equipo != FIN);

	return equipo;
}

// funcion: Muestra mensaje proporcionado  y lee (un int) los puntos de E/.
// salida : puntos anotados ya filtrados, valores: 1, 2 o 3.
int leerPuntos (string mensaje) {

	int puntos;

	do {
		cout << mensaje;
		cin >> puntos;
	} while (puntos < 1 || puntos > 3);

	return puntos;
}

// funcion: Muestra mensaje proporcionado  y lee (un int)  minuto de anotación.
// salida : minuto filtrado valores: 0-39.
int leerMinuto (string mensaje, int anterior) {

	/*
	 * Sin suponer que los minutos se introducen de forma ascendente.
	 */

	int minuto;

	do {
		cout << mensaje;
		cin >> minuto;
	} while (minuto < anterior || minuto > 39);

	return minuto;
}
// funcion: Muestra mensaje proporcionado  y lee (un int)  minuto de anotación.
// salida : minuto filtrado valores: 0-39.
int leerMinuto (string mensaje) {

	/*
	 * Suponemos que los minutos se introducen de forma ascendente.
	 */

	int minuto;

	do {
		cout << mensaje;
		cin >> minuto;
	} while (minuto < 0 || minuto > 39);

	return minuto;
}
// funcion: Recibe las puntuaciones del equipo local, equipo visitante
// Devuelve una variable con 3 estados GANAA, GANAB, EMPATE
Final  equipoGanador (int puntosA, int puntosB) {
	Final ganador = Final::EMPATE;

	if (puntosA > puntosB)
		ganador = Final::GANAA;
	else if (puntosA <  puntosB)
		ganador = Final::GANAB;
	return ganador;
}

//  funcion: Imprime el resultado de cada parcial del partido.
//  entrada : el mensaje puede identificar cada parte del partido
void imprimeGanador (string msg, int local, int visitante) {

	cout << msg;
	Final ganador = equipoGanador (local,visitante);
	if (ganador == Final::EMPATE)
		cout << "EMPATE de los dos equipos"<< endl;
	else if (ganador == Final::GANAA)
		cout << "Gana el equipo " << EQUIPO_A << endl;
	else
		cout << "Gana el equipo " << EQUIPO_B << endl;
	cout << local << " -- " << visitante << endl;
}


int main() {

	const int TIEMPO1 = 20;
	const string MENSAJE_EQUIPO = "Introduce identificador de equipo (A o B): ";
	const string MENSAJE_PUNTOS = "Introduce los puntos anotados (1, 2 o 3): ";
	const string MENSAJE_MINUTO = "Introduce el minuto de anotación (0-39): ";
	const string SIN_DATOS 	    = "No se han introducido datos.";

	char equipo;
	int puntos, minuto;
	int puntosEquipoAM1, puntosEquipoAM2, puntosEquipoBM1, puntosEquipoBM2, triples;


    minuto  = 0; // Empieza en el minuto 0
	puntosEquipoAM1 = puntosEquipoBM1 = 0;
	puntosEquipoAM2 = puntosEquipoBM2 = 0;
	triples = 0;
	equipo    = leerEquipo(MENSAJE_EQUIPO);		// Lectura anticipada

	while (equipo != FIN) {

	     puntos = leerPuntos(MENSAJE_PUNTOS);
	     minuto = leerMinuto(MENSAJE_MINUTO,minuto);

        if (minuto < TIEMPO1)
            if (equipo == EQUIPO_A)  			// Se acumulan los puntos al equipo correspondiente
                puntosEquipoAM1 += puntos;
            else puntosEquipoBM1 += puntos;
        else
            if (equipo == EQUIPO_A)  			// Se acumulan los puntos al equipo correspondiente
                puntosEquipoAM2 += puntos;
            else puntosEquipoBM2 += puntos;

        if (puntos == 3)  // si triple
            triples++;

        equipo = leerEquipo(MENSAJE_EQUIPO);

	}
	// Mostrar las estadísticas del partido si procede

	if (minuto > 0) {	// hay_datos
		imprimeGanador("En la primera parte del partido ", puntosEquipoAM1, puntosEquipoBM1);
        puntosEquipoAM2 += puntosEquipoAM1;
		puntosEquipoBM2 += puntosEquipoBM1;
		imprimeGanador("Al final del partido ", puntosEquipoAM2, puntosEquipoBM2);
		cout << "Numero total de triples : " << triples << endl;
	}
	else
		cout << SIN_DATOS << endl;


   return 0;
}
 
