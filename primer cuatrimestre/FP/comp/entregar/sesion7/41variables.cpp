#include <iostream>
using namespace std;
int main(){

    char min_izquierda, max_izquierda, min_derecha, max_derecha ;

    cout << "Vamos a crear dos series de letras y a combinarlas."
     << "\nIntroduce una letra inicial para la primera serie: " ;
    cin  >> min_izquierda ;
    cout << "Introduce una letra final para la primera serie: " ;
    cin  >> max_izquierda ;
    cout << "Introduce una letra inicial para la segunda serie: " ;
    cin  >> min_derecha ;
    cout << "Introduce una letra final para la segunda serie: " ;
    cin  >> max_derecha ;

    for (char izquierda = min_izquierda ; izquierda <= max_izquierda ; izquierda++){
        for (char derecha = min_derecha ; derecha <= max_derecha ; derecha++)
            cout << izquierda << derecha << " " ;

        cout << endl ;
    }

}
