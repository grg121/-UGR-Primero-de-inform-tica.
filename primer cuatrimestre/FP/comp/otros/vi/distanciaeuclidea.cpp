/*Ejercicio. Construid una expresión para calcular la distancia euclídea entre dos puntos del plano 
P1 = (x1, y1), P2 = (x2, y2). Usad las funciones sqrt y pow. d(P1, P2) = raiz cuadrada de [(x1 - x2)^2 + (y1 - y2)^2]  */
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x1,y1,x2,y2,distancia;
	cout << "A continuacion se calculara la distancia euclídea entre dos puntos del plano.  \nPara ello, en primer lugar, introduzca la cordenada X del primer punto: \n";
	cin >> x1;
	cout << "\nA continuación, introduzca la cordenada Y (del primer punto):\n";
	cin >> y1;
	cout << "\nLa cordenada X del segundo punto... \n";
	cin >> x2;
	cout << "\nY, finalmente, la cordenada Y del segundo punto: \n";
	cin >> y2;
	distancia = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	cout << "\nLa distancia euclídea será, por tanto, de: " << distancia << " unidades" ;
}

