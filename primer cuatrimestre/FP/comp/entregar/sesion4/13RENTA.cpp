/*

Los datos a leer son:
• Si la persona es un trabajador autónomo o no
• Si es pensionista o no
• Estado civil
• Renta bruta (total de ingresos obtenidos)
• Retención inicial a aplicar.


La retención inicial se va a modificar ahora atendiendo al siguiente criterio:
• Se baja 3 puntos la retención fiscal a los autónomos, es decir, si la retención
inicial era de un 15 %, por ejemplo, la retención final a aplicar será de un 12 %
(por lo que la renta neta final será mayor)
• Para los no autónomos:
– Se sube un punto la retención fiscal a todos los pensionistas, es decir, si la
retención inicial era de un 13 %, por ejemplo, la retención final a aplicar será
de un 14 % (por lo que la renta neta final será menor)
– Al resto de trabajadores (no autónomo y no pensionista) se le aplica a todos
una primera subida lineal de dos puntos en la retención inicial.
Una vez hecha esta subida, se le aplica (sobre el resultado anterior) las si-
guientes subidas adicionales, dependiendo de su estado civil y niveles de
ingresos:
◦ Se sube otros dos puntos la retención fiscal si la renta bruta es menor de
20.000 euros
◦ Se sube otros 2.5 puntos la retención fiscal a los casados con renta bruta
superior a 20.000 euros
◦ Se sube otros tres puntos la retención fiscal a los solteros con renta bruta
superior a 20.000 euros

Una vez calculada la retención final, la aplica sobre la renta bruta para así
obtener la renta final del trabajador.*/




#include<iostream>
using namespace std;
int main(){
    bool es_autonomo, es_pensionista, es_soltero;
    double renta_bruta, renta_neta;
    const double LIMITE_RENTA = 20000;
    double retencion_inicial, retencion_final;
    char autonomo, pensionista, soltero;
    cout << "¿Se trata de un autonomo? (Y/N)    ";
    cin >> autonomo ;
    cout << "¿Es pensionista? (Y/N)  ";
    cin >> pensionista;
    cout << "¿Es soltero? (Y/N)   ";
    cin >> soltero ;
    autonomo = toupper(autonomo);
    pensionista = toupper(pensionista);
    soltero = toupper(soltero);
    es_autonomo = autonomo == 'Y';
    es_pensionista = pensionista == 'Y';
    es_soltero = soltero == 'Y';
    cout << "Introduce la renta bruta: " ;
    cin >> renta_bruta;
    cout << "introduce la retencion inicial a aplicar: ";
    cin >> retencion_inicial;
    bool supera_limite = renta_bruta > LIMITE_RENTA;
    if (es_autonomo)
        retencion_final = retencion_inicial - 3 ;
    else if (es_pensionista)
        retencion_final = retencion_inicial + 1 ;
    else{
        retencion_final = retencion_inicial + 2 ;
        if (!supera_limite)
            retencion_final = retencion_final + 2 ; // (Dos puntos sumados a los dos anteriores)
        else if (!es_soltero)
            retencion_final = retencion_final + 2.5 ;
             else
                retencion_final = retencion_final + 3 ;
                }
    cout << "retencion final: " << retencion_final;
    renta_neta = renta_bruta - renta_bruta * retencion_final / 100;
    cout << "\nLa renta neta será: " << renta_neta ;
}


