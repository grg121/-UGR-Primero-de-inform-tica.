#include<iostream>
#include<cmath>
using namespace std;

    class ProgresionGeometrica{

    private:

        double inicio, razon;

    public:

        ProgresionGeometrica( double valor_de_inicio, double valor_razon ){
            inicio = valor_de_inicio ;
            razon  = valor_razon     ;
            }

        double TerminoNumero(int k){
            double termino_k = inicio;
            for (int i = 2 ; i <= k ; i++){
                termino_k *= k;
            }
        }

       double SumaHastaInfinito(){
            double producto = inicio/(1-razon);
            return producto ; }

        double ProductoHasta(int tope){
            double valor = inicio ;
            for (int i = 1; i < tope ; i++)
                valor *= razon ;
            double producto = sqrt(pow(inicio*valor,tope)) ;
            return producto;}


        double SumaHasta(int tope){
            double suma  = 0 ;
            double valor = inicio ;
            for (int i = 0 ; i < tope ; i++){
                suma  += valor  ;
                valor *= razon  ; }
            return suma ;
            }
        void ImprimeKvalores(int k){
            double termino_k = inicio ;
            for (int i = 1 ; i <=k ; i++){
                cout << termino_k << endl ;
            termino_k *= razon ;
                }

            }
    };

    int main (){
        double resultado ;
            int tope ;
            double inicio, razon ;
            cout << "\nIntroduce un valor inicial para la progresión geometrica:\n";
            cin >> inicio ;
            cout << "\nIntroduce un valor para la razón de cambio de la progresión:\n" ;
            cin >> razon ;


            ProgresionGeometrica progresion (inicio, razon);

            cout << "\nIntroduce un tope, k, para calcular los primeros k valores y la suma de estos: " ;
            cin  >> tope ;

            progresion.ImprimeKvalores(tope) ;

            cout << "La suma de los primeros k valores es: " << progresion.SumaHasta(tope) ;


        }



