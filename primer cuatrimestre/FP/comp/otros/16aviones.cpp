#include<iostream>
using namespace std;
int main (){
    const int PRECIO_INICIAL     = 150 ,
              REBAJA_PROMOCIONAL = 15  ;
    const double    PORCENTAJE_A = 0.03,
                    PORCENTAJE_B = 0.04,
                    PORCENTAJE_C = 0.05;
    double descuento = 0;
    double distancia_km ;
    double precio_final ;
    bool cliente_previo ;
    char respuesta ;

    cout << "Introduzca la distancia en kilometros del destino: " ;
    cin  >> distancia_km ;
    cout << "¿Es un cliente previo? s/n";
    do{
    cin >> respuesta ;
    respuesta = toupper(respuesta);
    }while (respuesta != 'S' && respuesta != 'N') ;

    cliente_previo = respuesta == 'S' ;


    precio_final = PRECIO_INICIAL - REBAJA_PROMOCIONAL ;

    if(distancia_km > 200)
        precio_final = precio_final + (distancia_km - 200) * 0.10 ;

    if (cliente_previo)
        descuento = PORCENTAJE_C ;

    if (distancia_km > 600 && distancia_km < 1100)
        descuento = descuento + PORCENTAJE_A  ;
    else if (distancia_km > 1100)
        descuento = descuento + PORCENTAJE_B  ;

    precio_final = precio_final - descuento * precio_final ;

    cout << "El precio del billete asciende a " << precio_final << " euros; \n habiéndose realizado una rebaja promocional de " << REBAJA_PROMOCIONAL << " euros, \n"
         << "y un descuento final del " << descuento << "% "  ;



}
