
#include <iostream>
using namespace std;

int main(){
   // IV = INDICE_VARIACION

   const int MINIMO_UNIDADES_PARA_DESCUENTO = 100;
   const double MINIMO_VENTA_GRANDE_PARA_DESCUENTO = 700.0;
   const double IV_DESCUENTO_POR_UNIDADES_VENDIDAS = 1 - 0.03;
   const double IV_DESCUENTO_POR_VENTA_GRANDE = 1 - 0.02;
   double precio_unitario, total_venta;
   int unidades_vendidas;

   cout << "\nPrecio unitario: ";
   cin >> precio_unitario;
   cout << "\nUnidades vendidas: ";
   cin >> unidades_vendidas;

   if (unidades_vendidas >= MINIMO_UNIDADES_PARA_DESCUENTO){
      precio_unitario = precio_unitario *
                        IV_DESCUENTO_POR_UNIDADES_VENDIDAS;

   total_venta = precio_unitario * unidades_vendidas;

   if (total_venta >= MINIMO_VENTA_GRANDE_PARA_DESCUENTO)
      total_venta = total_venta *
                    IV_DESCUENTO_POR_VENTA_GRANDE;
}
   cout << "\nTotal venta: " << total_venta;
}
// Lo único que hay que hacer para conseguir el resultado buscado es anidar el segundo condicional con el primero. Para ello solo es necesario añadir unas llaves.
