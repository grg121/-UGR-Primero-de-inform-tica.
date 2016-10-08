#include<iostream>
using namespace std;

class Ventas {

    private:

        int identificador_sucursal1 ;
        int identificador_sucursal2 ;
        int identificador_sucursal3 ;

        int ventas_sucursal1  ;
        int ventas_sucursal2  ;
        int ventas_sucursal3  ;

    public:

        Ventas(int identificador1, int identificador2, int identificador3){
            identificador_sucursal1 = identificador1 ;
            identificador_sucursal2 = identificador2 ;
            identificador_sucursal3 = identificador3 ;
            ventas_sucursal1 = 0 ;
            ventas_sucursal2 = 0 ;
            ventas_sucursal3 = 0 ;
            }

       void ActualizarVentas(int unidades, int sucursal){
            if (sucursal = identificador_sucursal1)
                ventas_sucursal1 += unidades ;
            if (sucursal = identificador_sucursal2)
                ventas_sucursal2 += unidades ;
            if (sucursal = identificador_sucursal3)
                ventas_sucursal3 += unidades ;
            };

       int SucursalGanadora(){
            int winner = identificador_sucursal1 ;
            if (ventas_sucursal2 > ventas_sucursal1)
                winner = identificador_sucursal2;
            if (ventas_sucursal3 > winner)
                winner = identificador_sucursal3;
            return winner;


        }
        };


int main (){

    cout << "Para terminar de operar, introduce 0 como identificador de sucursal." ;
    int identificador_sucursal, cod_producto, unidades_vendidas;

    const int TERMINADOR = 0;
    Ventas ventas_empresa(123, 321, 456) ;

    cout << "\nIntroduce el identificador de la sucursal: " ;
    cin >> identificador_sucursal ;

    while (identificador_sucursal != TERMINADOR){
        cout << "\nIntroduce el código del producto vendido: " ;
        cin >> cod_producto      ;
        cout << "\nIntroduce el numero de unidades vendidas: " ;
        cin >> unidades_vendidas ;
    ventas_empresa.ActualizarVentas(unidades_vendidas, identificador_sucursal);
        cout << "\nIntroduce el identificador de la sucursal: " ;
        cin >> identificador_sucursal;
        }
    cout << "La sucursal con mayor numero de ventas es la sucursal de identificador: " << ventas_empresa.SucursalGanadora();
}
