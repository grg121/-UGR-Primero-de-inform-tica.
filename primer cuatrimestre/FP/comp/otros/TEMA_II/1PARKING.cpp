/*1. (Parking Madrid)
La tabla para el cálculo del precio a pagar en los parkings de Madrid para el 2015 es
la siguiente:
Desde el minuto 0 al 30: 0.0412 euros cada minuto
Desde el minuto 31 al 90: 0.0370 euros cada minuto
Desde el minuto 91 al 660: 0.0493 euros cada minuto
Desde el minuto 661 hasta máximo 24 horas: 31.55 euros
Dado un tiempo de entrada y un tiempo de salida, construya un programa que calcule
la tarifa final en euros a cobrar. Ejemplo: si el tiempo de permanencia es de 32 minutos,
los primeros 30 minutos se facturan a 0.0412 el minuto y los 2 restantes a 0.0370.
Finalidad: Utilización del condicional simple. Dificultad Baja.*/

#include<iostream>
using namespace std;
int main (){

/*El primer bloque de ordenes tiene por objetivo recibir la entrada del día (con su mes y año) de la introduccion y retirada del vehiculo en el parking.
Primero se pide estos datos al usuario. Entonces se convierte el año y los meses a dias y se suman en una nueva variable que será el total de dias transcurridos. */

int dia_in, mes_in, year_in,
    dia_out, mes_out, year_out;

cout << "Introduce el día de entrada del vehículo en el parking señalando día, mes y año de la forma: \"31/12/1997\" : ";
cin >> dia_in
    >> mes_in
    >> year_in;

cout << "Introduce el día en que se retira el vehículo del parking señalando día, mes y año de la forma: \"01/01/1998\" : ";
cin >> dia_out
    >> mes_out
    >> year_out;

int long total_dias, total_meses, total_years;

    if (dia_in < dia_out)
        total_dias = dia_out  - dia_in ;
    else
        total_dias = 31 - dia_in + dia_out - 1 ;
    if (mes_in < mes_out)
        total_meses = mes_out - mes_in - 1 ;
    else
        total_meses = 12 - mes_in + mes_out - 1 ;
    if (year_in > year_out)
        cout << "Error en la introduccion del año de salida. \n \n \n \n" ;
    else
        total_years = year_out - year_in - 1 ;



int diferencia_days = total_years * 365 + total_meses * 30 + total_dias;
int diferencia_days_a_minutos = diferencia_days * 24 * 60 ;

/* A continuación se repite el proceso con las horas. Esta vez se pide horas, minutos y segundos y se pasará todo a minutos. Ademas se le sumaran las horas que corresponda por los dias totales
 calculados previamente.  */

int hora_in, minuto_in, segundo_in,
    hora_out, minuto_out, segundo_out;

cout << "Introduce la hora de entrada del vehículo en el parking (hora, minutos, segundos) separados por espacios. Ejemplo: 23 13 32 : ";
cin >> hora_in
    >> minuto_in
    >> segundo_in ;

cout << "Introduce la hora de retirada del vehículo en el parking (hora, minutos, segundos) separados por espacios. Ejemplo: 08 31 20 : ";
cin >> hora_out
    >> minuto_out
    >> segundo_out ;

int total_horas, total_minutos, total_segundos;
    if (hora_in > hora_out)
        total_horas = 24 - hora_in + hora_out;
    else
        total_horas = hora_out - hora_in;
    if (minuto_in > minuto_out)
        total_minutos = 60 - minuto_in + minuto_out;
    else
        total_minutos = minuto_out - minuto_in ;
    if (segundo_in > segundo_out)
        total_segundos = 60 - segundo_in + segundo_out;
    else
        total_segundos = segundo_out - segundo_in;


/* time expresará la diferencia total de tiempo transcurrido en minutos. */

int time = total_horas * 60 + total_minutos + diferencia_days_a_minutos + total_segundos / 60 ;

int time_horas = time / 60 ;

cout << "El tiempo transcurrido en minutos ha sido de: " << time << "\nQue son aproximadamente: " << time_horas << " horas.";

const double precio_0_30=0.0412, precio_31_90=0.0370, precio_91_660=0.0439, precio_por_dia=31.55;
const double
    tarifa_30 = precio_0_30 * 30,
    tarifa_90 = tarifa_30 + precio_31_90 * 59,
    tarifa_660 = tarifa_90 + precio_91_660 * 569,
    tarifa_24h = tarifa_660 + precio_por_dia;
double factura;
if (time < 30)
    factura = precio_0_30 * time;
    else if (time < 90)
        factura = tarifa_30 + precio_31_90 * (time - 30);
    else if (time < 660)
        factura = tarifa_90 + precio_91_660 * (time - 90);
    else if (time < 1440)
        factura = tarifa_24h ;
    else {
    int dias_de_mas = (time - 24 * 60 )/24;
        factura = tarifa_24h + dias_de_mas * precio_por_dia ;}
cout << "\nLa factura será de "<< factura << " Euros por " << time << " minutos.";

} //Por Francisco Navarro Morales grg121@correo.ugr.es
