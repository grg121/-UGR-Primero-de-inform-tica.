#include<iostream>
#include<cmath>
using namespace std;

double SumaHasta(int tope, double a1, double razon){
    double suma  = 0 ;
    double valor = a1 ;
    for (int i = 0 ; i < tope ; i++){
        suma  += valor  ;
        valor *= razon  ; }
    return suma ;
}

char LeerOpcion(){
    char opcion ;
    do {
    cin >> opcion;
    if (opcion >= 'a' && opcion <= 'z')
        opcion = opcion - ('a' - 'A');
    }while(opcion != 'S' && opcion != 'M' && opcion != 'I' && opcion != 'A');
    return opcion ;
}

double ProductoHasta(int tope, double a1, double razon){
    double valor = a1 ;
    for (int i = 1; i < tope ; i++)
        valor *= razon ;
    double producto = sqrt(pow(a1*valor,tope)) ;
    return producto;}

double SumaHastaInfinito(double a1, double razon){
    double producto = a1/(1-razon);
    return producto ;
}


int main (){

    double resultado ;
    int tope ;
    double a1, razon ;
    int salida = 0 ;
    do{
    salida = 0 ;
    cout << "\nIntroduce un valor inicial para la progresión geometrica:\n";
    cin >> a1 ;
    cout << "\nIntroduce un valor para la razón de cambio de la progresión:\n" ;
    cin >> razon ;
    cout << "¿Qué desea calcular?\n"
         << "\nS. Suma los primeros k valores de la progresión."
         << "\nM. Multiplica los primeros k valores de la progresion. "
         << "\nI. Calcula la suma de los valores de la progresión hasta infinito. \n(Para valores de la razón: -1 < razon < 1)"
         << "\nA. introduce de nuevo valores para el cálculo. \n\n" ;
    char opcion = LeerOpcion() ;


    if (opcion == 'I')
        resultado = SumaHastaInfinito(a1, razon);
    else if (opcion == 'A')
        salida = 1 ;
    else{
        salida = 0 ;
        cout << "\nIntroduce un tope para la progresión:\n" ;
        cin >> tope ;

        if (opcion == 'S')
            resultado = SumaHasta(tope, a1, razon);
        else if (opcion == 'M')
            resultado = ProductoHasta(tope, a1, razon);

        }
        }while(salida == 1 );
        cout << endl << resultado ;
    }// Por Francisco Navarro Morales 1ºF
