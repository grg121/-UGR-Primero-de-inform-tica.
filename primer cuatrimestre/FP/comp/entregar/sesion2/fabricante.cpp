/*Las ganancias de un determinado producto se reparten entre el dise�ador
y los tres fabricantes del mismo. El programa pide la ganancia total de la empresa
(los ingresos realizados con la venta del producto) y dice cu�nto cobran cada uno de ellos, 
sabiendo que el dise�ador cobra el doble que cada uno de los fabricantes. El dato de entrada ser� la ganancia total a repartir. */
#include<iostream>
#include<cmath>
using namespace std;
main (){
	double ingresos, designer, fabricante; // Pongamos que cada fabricante cobra "X", el dise�ador cobrar� 2X, los 3 fabricantes, 3X
	cout << "Introduce la ganancia de la empresa en euros: \n(los ingresos realizados con la venta del producto)\n " ; 
	cin >> ingresos; // Los ingresos se dividir�n en 5 partes (2x+3x). Cada parte es igual a lo que cobra un fabricante 
	fabricante = ingresos/5;
   designer = fabricante*2;
   cout << "Las ganancias del dise�ador son: " << designer << " euros";
   cout << "\nY cada fabricante gana: " << fabricante << " euros";
}
	//Por Francisco Navarro Morales - GRG121
	
