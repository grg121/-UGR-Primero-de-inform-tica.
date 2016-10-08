#include<iostream>
using namespace std;



class Cuadrado{

    private:

        //Las coordenadas se refieren al vertice inferior izquierdo.
        double lado,
               coordenada_x,
               coordenada_y ;

    public:

        Cuadrado(double l, double x, double y){
            lado = l;
            coordenada_x = x;
            coordenada_y = y;
        }

        Cuadrado(double l){
            lado = l;
            coordenada_x = 0 ;
            coordenada_y = 0 ;
            }

        double CalcularArea(){
            double area = lado * lado ;
            return area ;
        }

        double CalcularPerimetro(){
            double perimetro = 4 * lado;
            return perimetro;
        }

        bool EsMayorQue(Cuadrado c){
            bool es_mayor = lado > c.lado;
            return es_mayor;
        }

        };

int main (){

    double x, y, l;
    cout << "\nIntroduce las coordenadas 'x' e 'y' del vertice inferior izquierdo: \n ";
    cin >> x >> y ;
    cout << "\nIntroduce la longitud del lado: \n" ;
    cin >> l ;



    }
