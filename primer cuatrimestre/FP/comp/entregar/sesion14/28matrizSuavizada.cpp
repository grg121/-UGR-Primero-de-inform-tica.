#include<iostream>
#include<cmath>
using namespace std;

int main(){



// No veo lógico definir las matrices de 50x30 si van a tener el mismo número de filas que de columnas, pero OK.

const int FIL = 50;
const int COL = 30;

int   original[FIL][COL] ;
double  suavizada[FIL][COL] ;


// n es el número de filas y de columnas de las matrices original y suavizada.

int n = 0 ;

cout << "Vamos a trabajar sobre una matriz ''original'' que será una matriz simétrica. \nLuego tendrá n filas y n columnas."
     << "\nIntroduce el número de filas y de columnas de la matriz: " ;

cin >> n ;

cout << "A continuación, introducimos los valores de la matriz: " ;

// Este bucle se asegura de que la matriz es simétrica. Inicializa j con cada valor de i, para evitar que se pidan los valores de la columna que debe ser similar a la fila anteriormente introducida.
// Además, i se inicializa en 1 y luego se le resta 1 para no confundir al usuario con las posiciones que, para nosotros son [0][0] y para ellos [1][1].
// Tambien he introducido un condicional para asegurarme de que no se les dé otra vez el mismo valor a las posiciones que tienen i=j.

for(int i = 0 ; i < n ; i++){
    for(int j = i ; j < n ; j++){
        cout << "\nIntroduce un valor para A["<<i+1<<"]["<<j+1<<"]: ";
        cin >> original[i][j] ;
        if(i != j)
            original[j][i] = original[i][j];


       }

    }


cout << "\nLa matriz introducida, simétrica, es: \n";

for(int a = 0 ; a < n ; a++){
    cout << endl ;
    for(int b = 0 ; b < n ; b++){
    cout << " " << original[a][b];
    }
}

double suma ;


for(int i = 0 ; i < n ; i++)
    suavizada[i][i] = original[i][i];

for(int i = 0 ; i < n ; i++){
    for(int j = i+1 ; j < n ; j++){
        double media = 0 ;
        for(int k = j ; k < n ; k++){
            media += original[i][k] ;
        }
        media = media/(n-j) ;
        suavizada[i][j] = media ;
        suavizada[j][i] = media ;
        }}



cout << "\nLa matriz suavizada es: \n " ;

for(int a = 0 ; a < n ; a++){
    cout << endl ;
    for(int b = 0 ; b < n ; b++){
    cout << " " << suavizada[a][b];
    }
}



}
