#include<iostream>
using namespace std;

double SalarioPor(int horas, double salario_por_hora){
    const double SALARIO_BASE_HORAS_EXTRA = salario_por_hora * 40 ;
    const double SALARIO_POR_HORAS_EXTRA       = salario_por_hora + 50 * salario_por_hora;
    double salario ;
    cout << horas ;
    if(horas > 40){
        int horas_extra = horas - 40 ;
            salario = SALARIO_BASE_HORAS_EXTRA + horas_extra * SALARIO_POR_HORAS_EXTRA ;
        }else
            salario = horas * salario_por_hora ;
            cout << "bad" ;

    return salario ;
}

int main () {
    double salario, salario_por_hora ;
    int horas ;
    cout << "Introduce las horas trabajadas: " ;
    cin >> horas ;
    cout << "Introduce el salario por hora: " ;
    cin >> salario_por_hora ;
    salario = SalarioPor(horas, salario_por_hora);
    cout << "El salario total es de: " << salario ;

    cout << "pepe" ;

}
