#include<iostream>
using namespace std;
int main (){
    int whole;
    double caracter;
    int least;
    bool is_whole;
    int contador;
    cout << "Insert as whole numbers as you want. Program will count how many have you introduced and show the least of them."
         << "\nWhen you want to finish, you only have to insert cero." << "\n" << "¡Program only takes whole numbers! " << "\n";


         /* El primer paso es aislado del bucle principal. Hay un bucle que actúa como filtro. */

          do {
            cin >> caracter;
            whole = caracter;
            is_whole = (caracter - whole == 0);
            }while (!is_whole);
            least = caracter;
            contador = 1;

         /* Habrá un bucle dentro de otro. El principal es el que realiza la función de contar y seleccionar el mínimo, el secundario (interior) es el filtro. */

    while (caracter != 0){
        do {
            cin >> caracter;
            whole = caracter;
            is_whole = (caracter - whole == 0);
            }while (!is_whole);
        if (caracter != 0){
            if (caracter < least)
            least = caracter;
        contador++ ;
        }
        }

    cout << "You have inserted  " << contador << " numbers, and the least have been: " << least ;

}
