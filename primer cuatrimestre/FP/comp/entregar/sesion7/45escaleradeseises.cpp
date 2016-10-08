#include<iostream>
using namespace std;
    int main(){
    int valor_inicial ;
    cout << "Introduce el valor inicial para la serie: ";
    cin >> valor_inicial ;

    cout << "Resultado del primer ejemplo (Ejercicio 43): " << endl;


        for (int j = valor_inicial ; j < valor_inicial + 7 ; j++){
            for (int i = valor_inicial ; i < valor_inicial + 7 ; i++){
                if (i >= j)
                    cout << i << " " ;
            }
            cout << endl ;
        }

    cout << "\nResultado del segundo ejemplo (Ejercicio 44): \n" << endl;

     for (int j = valor_inicial ; j < valor_inicial + 7 ; j++){
        for (int i = j ; i != j + 6 ; i++)
            cout << i << " " ;
        cout << endl ;
    }
}
