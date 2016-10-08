#include<iostream>
#include<cmath>
using namespace std;
const double PI =  3.1415926535,
             bo = 0.2316419,
             b1 = 0.319381530,
             b2 = -0.356563782,
             b3 = 1.781477937,
             b4 = -1.821255978,
             b5 = 1.330274429 ;

    class FuncionGaussiana{
        private:
            double esperanza, desviacion;


        public:

        FuncionGaussiana(double esp, double desv){
            esperanza  = esp  ;
            desviacion = desv ;
        }

        double GaussianaDe(double x){
            double cuadrado = pow((x-esperanza)/desviacion,2) ;
            double numerador = exp(-cuadrado/2);
            double denominador = desviacion * sqrt(2*PI);
            double y = numerador/denominador ;
            return y ;}


        double AreaHasta(double x){
            double t = 1/1+bo*x ;
            double producto = b1*t+b2*pow(t,2)+b3*pow(t,3)+b4*pow(t,4)+b5*pow(t,5) ;
            double gaussiana = GaussianaDe(x) ;
            double area = 1 - gaussiana * producto ;
            return area ;
        }

        };

    int main () {
            double x, esperanza, desviacion ;
            int n ;

            cout << "\nIntroduce un valor para la esperanza de la funcion: " ;
            cin >> esperanza ;

            cout << "\nIntroduce un valor para la desviación de la funcin: " ;
            cin >> desviacion ;

            FuncionGaussiana funcion (esperanza, desviacion);

            cout << "Introduce el numero de valores para el que se quiere calcular la funcion gaussiana: " ;
            cin >> n;

            for (int i = 0 ; i < n ; i++){

            cout << "\nIntroduce un valor para x: " ;
            cin >> x ;

            double y = funcion.GaussianaDe(x) ;

            cout << "\nPara x = " << x << ", y = " << y << endl ;
            }

            cout << "Ahora vamos a calcular el area que cubre la función desde menos infinito hasta x: ";

            cout << "Introduce un valor para x: ";
            cin >> x ;

            double area = funcion.AreaHasta(x);

            cout << "El area que cubre la funcion desde menos infinito hasta x es: " << area ;


        }

