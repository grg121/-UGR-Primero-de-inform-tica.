/* Ejercicio. Declarad dos variables de tipo bool, es_joven y es_varon. 
Asig- nadles cualquier valor. Declarad otra variable es_varon_viejo y 
asignadle el valor correcto usando las variables anteriores y los operadores lógicos.
*/

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	bool es_joven, es_varon;
	es_joven = true;
	es_varon = true;
	bool es_varon_viejo;
	es_varon_viejo = !es_joven;
	cout << es_varon_viejo;
}
