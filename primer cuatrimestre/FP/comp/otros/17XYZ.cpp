/* 
17. Realizar un programa que declare las variables x, y y z, les asigne los valores 10, 20
y 30 e intercambien entre s� sus valores de forma que el valor de x pasa a y, el de y
pasa a z y el valor de z pasa a x (se pueden declarar variables auxiliares aunque se
pide que se use el menor n�mero posible).
Finalidad: Mostrar la importancia en el orden de las asignaciones. Dificultad Media.*/

#include<iostream>
using namespace std;
int main (){
	int x = 10 , y = 20 , z = 30 , w;
	w = z ;
	y = x ;
	z = y ;
	x = w ;
	cout << x << y << z ;
}
