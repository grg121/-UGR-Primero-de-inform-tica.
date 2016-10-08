#include<iostream>
using namespace std;

bool LeeOpcion2Alternativas(){
    char eleccion ;
    do {
        cin >> eleccion ;
        if (eleccion > 'a' && eleccion > 'z')
            eleccion = eleccion - 'a' - 'A';
        }while(eleccion != 'S' && eleccion != 'N');
        bool si ;
        si = eleccion == 'S' ;
        return si ;
        }
int main (){

    bool es_autonomo, es_pensionista, es_soltero;
    double renta_bruta, renta_neta;
    const double LIMITE_RENTA = 20000;
    double retencion_inicial, retencion_final;

    cout << "¿Se trata de un autonomo? (S/N)    ";
    es_autonomo = LeeOpcion2Alternativas() ;
    cout << "¿Es pensionista? (S/N)  ";
    es_pensionista = LeeOpcion2Alternativas() ;
    cout << "¿Es soltero? (S/N)   ";
    es_soltero = LeeOpcion2Alternativas() ;

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

