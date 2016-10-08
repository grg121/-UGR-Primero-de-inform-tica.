#include<iostream>
using namespace std;

    // La clase recta representa una función cuya formula es: Ax + By + C = 0
    class Recta {
        public:
        int coeficiente_x, coeficiente_y, termino_independiente;
        double CalcularPendiente(){
            double pendiente = -coeficiente_x / coeficiente_y;
            return pendiente ;
        };


    } ;

    int main (){

        Recta una_recta, otra_recta ;

        cout << "\nIntroduce seis reales (separados por un espacio) que representarán \nlos coeficientes A, B y C de dos rectas Ax+By+C = 0.\n" ;
        cin  >> una_recta.coeficiente_x  >> una_recta.coeficiente_y  >> una_recta.termino_independiente  ;
        cin  >> otra_recta.coeficiente_x >> otra_recta.coeficiente_y >> otra_recta.termino_independiente ;

        double una_pendiente, otra_pendiente ;

       // una_pendiente  = una_recta.CalcularPendiente ;
       // otra_pendiente = otra_recta.CalcularPendiente;

        cout << "Las pendientes de la primera y segunda recta, respectivamente, son: "
             << una_recta.CalcularPendiente() << " y " << otra_recta.CalcularPendiente() ;
}
