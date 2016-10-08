// 18. Lee un entero e imprime en pantalla todos sus divisores.
#include<iostream>
using namespace std;
int main(){
    bool is_entero;
    int entero;
    double no_entero;
    cout << "Introduce un número entero: ";

    /* A continuación, un filtro de números enteros. El valor introducido se guarda como decimal y se transfiere a una variable entera. Después se restan. Si el valor introducido era
    entero, el resultado será 0, si era decimal, el resultado será distinto de 0. Eje: introduces 3.3 y el programa opera 3.3 - 3 = 0.3 o introduces 2 y opera: 2-2 = 0 */

    do {
    cin >> no_entero;
    entero = no_entero;
    } while (no_entero - entero > 0);

    bool es_divisor;
    int divisor = 1;
    while (divisor <= (entero / 2)){
    divisor++ ;
    es_divisor = (entero % divisor == 0 );
    if (es_divisor)
    cout << "\n" << divisor;
    }






}// Por Francisco Navarro Morales grg121@correo.ugr.es
