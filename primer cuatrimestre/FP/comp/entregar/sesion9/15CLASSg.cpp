#include<iostream>
using namespace std;

    // La clase recta representa una función cuya formula es: Ax + By + C = 0
    class Recta {
        private:
        double coeficiente_x,
               coeficiente_y,
               termino_independiente ;

        bool EsCorrecto(double coeficiente_x, double coeficiente_y, double termino_independiente){
            bool es_correcto = coeficiente_x != 0 && coeficiente_y != 0;
            return es_correcto ;
            }

        public:

        Recta(){
            do{
            cout << "Introduce los valores (A,B,C) de una recta con la forma: Ax + By + C = 0: ";
            double A, B, C ;
            cin >> A >> B >> C ;
            coeficiente_x = A ;
            coeficiente_y = B ;
            termino_independiente = C;
            }while(! EsCorrecto(coeficiente_x, coeficiente_y, termino_independiente));

            }

        double CalcularPendiente(){
            double pendiente = -coeficiente_x / coeficiente_y;
            return pendiente ;
        }
        double CalcularOrdenada(double x){
            double ordenada = (-coeficiente_x * x - termino_independiente)/coeficiente_y ;
            return ordenada ;
        }
        double CalcularAbcisas(double y){
            double abcisas = (-coeficiente_y * y - termino_independiente)/coeficiente_x;
            return abcisas;
        }


    } ;

    int main (){

        Recta una_recta, otra_recta ;

        double una_pendiente, otra_pendiente ;

        double x, y ;

        cout << "\nLas pendientes de la primera y segunda recta, respectivamente, son: "
             << una_recta.CalcularPendiente() << " y " << otra_recta.CalcularPendiente() ;

        cout << "\nA continuación vamos a calcular el valor que toma la ordenada en la primera recta para un valor de x...\n"
             << "Introduce un valor para x: " ;
        cin >> x ;

        cout << "\nEl valor de la ordenada para una abcisa de " << x << " es: " << una_recta.CalcularOrdenada(x) ;

        cout <<"\nA cotinuacion vamos a calcular el valor que toma abcisas en la primera recta para un valor de y..."
             << "Introduce un valor para y: ";
        cin >> y ;

        cout <<"\nEl valor de abcisas para una ordenada de: " << y << " es: " << una_recta.CalcularAbcisas(y) ;
}
