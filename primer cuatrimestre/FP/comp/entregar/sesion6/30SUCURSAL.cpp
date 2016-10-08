#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
    int sucursal;
    char producto;
    int cantidad;

    /*Variables que contendrán la cantidad de productos vendidos por sucursal */

    int s1pA = 0, s1pB = 0, s1pC = 0,
        s2pA = 0, s2pB = 0, s2pC = 0,
        s3pA = 0, s3pB = 0, s3pC = 0 ;

    cout << "Debe introducir un código de ventas."
         << "\n Debe hacerlo de la forma: "
         << "\n 1 c 10"
         << "\n 1 b 15"
         << "\n 3 c 3"
         << "\n 2 a 42  ....etc /n"
         << "introduce el código a continuación: \n \n \n " ;

           cin >> sucursal;

    while (sucursal != -1){
          cin  >> producto
               >> cantidad;
        producto = toupper(producto);
        if (sucursal == 1){
            if (producto == 'A')
                s1pA = s1pA + cantidad;
            else if (producto == 'B')
                s1pB = (s1pB + cantidad);
            else if (producto == 'C')
                s1pC = (s1pC + cantidad);}
        else if (sucursal == 2){
                if (producto == 'A')
                s2pA = (s2pA + cantidad);
            else if (producto == 'B')
                s2pB = (s2pB + cantidad);
            else if (producto == 'C')
                s2pC = (s2pC + cantidad);}
        else if (sucursal == 3){
                if (producto == 'A')
                s3pA = (s3pA + cantidad);
            else if (producto == 'B')
                s3pB = (s3pB + cantidad);
            else if (producto == 'C')
                s3pC = (s3pC + cantidad);}
      cin >> sucursal;
            }



    int total_sucursal1 = 0, total_sucursal2 = 0, total_sucursal3 = 0;
    total_sucursal1 = s1pA + s1pB + s1pC ;
    total_sucursal2 = s2pA + s2pB + s2pC ;
    total_sucursal3 = s3pA + s3pB + s3pC ;


    cout << "\nLa sucursal 1 ha vendido:\n"
         << s1pA << " unidades del artículo A,\n"
         << s1pB << " unidades del articulo B, y\n"
         << s1pC << " unidades del artículo C. "
         << "\nEn total, la sucursal 1 ha vendido " << total_sucursal1 << " unidades. \n";

    cout << "\nLa sucursal 2 ha vendido:\n"
         << s2pA << " unidades del artículo A,\n"
         << s2pB << " unidades del articulo B, y\n"
         << s2pC << " unidades del artículo C."
         << "\nEn total, la sucursal 2 ha vendido " << total_sucursal2 << " unidades. \n";

    cout << "\nLa sucursal 3 ha vendido\n"
         << s3pA << " unidades del artículo A,\n"
         << s3pB << " unidades del articulo B, y\n"
         << s3pC << " unidades del artículo C."
         << "\nEn total, la sucursal 3 ha vendido " << total_sucursal3 << " unidades.";


}
