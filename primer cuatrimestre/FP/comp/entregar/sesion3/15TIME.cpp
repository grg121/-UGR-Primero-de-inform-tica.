/*Lee desde teclado tres variables correspondientes a un n�mero de horas, minutos
y segundos, respectivamente. Calcula las horas, minutos y
segundos dentro de su rango correspondiente. Por ejemplo, dadas 10 horas, 119 minutos
y 280 segundos, entrega como resultado 12 horas, 3 minutos y 40 segundos.
El programa no calcular� meses, a�os, etc sino que se quedar� en los d�as.*/

#include<iostream>
#include<cmath>
using namespace std;
int main () {
    int dias, horas, minutos, segundos;
    cout << "Introduce el valor para las horas: " ;
    cin >> horas ;
	cout << "Introduce el valor para los minutos: ";
	cin >> minutos;
	cout << "Introduce el valor para los segundos: ";
	cin >> segundos ;
	minutos = minutos + segundos / 60;
    segundos = segundos % 60 ;
    horas = horas + minutos / 60;
    minutos = minutos % 60;
    horas = horas % 60;
    dias = horas / 24;
	cout << "El equivalente a los datos ingresados es: " << dias << " d�as, "
	<< horas << " horas, " << minutos << " minutos y " << segundos << " segundos";

}// Por Francisco Navarro - GRG121@
