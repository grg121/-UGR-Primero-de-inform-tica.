#include<iostream>
using namespace std;

    // La clase recta representa una función cuya formula es: Ax + By + C = 0
    class Recta {
        public:
        int coeficiente_x, coeficiente_y, termino_independiente;
    } ;

    int main (){

        Recta una_recta, otra_recta ;

        cout << "\nIntroduce seis reales (separados por un espacio) que representarán \nlos coeficientes A, B y C de dos rectas Ax+By+C = 0.\n" ;
        cin  >> una_recta.coeficiente_x  >> una_recta.coeficiente_y  >> una_recta.termino_independiente  ;
        cin  >> otra_recta.coeficiente_x >> otra_recta.coeficiente_y >> otra_recta.termino_independiente ;

        double una_pendiente, otra_pendiente ;

        una_pendiente  = -una_recta.coeficiente_x  /  una_recta.coeficiente_y ;
        otra_pendiente = -otra_recta.coeficiente_x / otra_recta.coeficiente_y ;

        cout << "Las pendientes de la primera y segunda recta, respectivamente, son: "
             << una_pendiente << " y " << otra_pendiente ;
}
