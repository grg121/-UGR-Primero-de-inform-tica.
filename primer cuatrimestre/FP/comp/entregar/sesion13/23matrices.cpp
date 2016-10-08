#include <iostream>
using namespace std;

int main(){

/* Trabajaremos con cuatro matrices:

A, de n filas y m columnas;
At, de m filas y n columnas;
B, de m filas y z columnas;
C, de n filas y z columnas ;

tendrán un valor máximo de columna o fila de 50 (constante maxi), si se requiere mayor número de filas o columnas, basta con modificar el valor de maxi.

*/

int const maxi = 50;

int A[maxi][maxi],
    B[maxi][maxi],
    C[maxi][maxi],
    At[maxi][maxi];

int n, m, z ;

cout << "\nIntroduce el número de filas de la matriz A: " ;
cin >> n ;
cout << "\nIntroduce el número de columnas de la matriz A: ";
cin >> m ;

//lectura de la matriz A:

cout << "\nLectura de la matriz A: \n";

for(int i=1 ; i <= n ; i++)
    for(int j=1 ; j<=m ; j++){
        cout << "Ingresa el valor para A["<<i<<"]["<<j<<"]: ";
        cin >> A[i][j];
        }

// mostramos la matriz A:

cout << "\n\n\n\nLa matriz introducida ha sido: \n" ;

for(int i=1 ; i <= n ; i++){
    cout << endl ;
    for(int j=1 ; j <= m ; j++)
        cout << " " << A[i][j];
    }

// a) Cálculo de la matriz transpuesta:


for(int i=1 ; i <= m ; i++)
    for(int j=1 ; j <= n ; j++)
        At[i][j] = A[j][i] ;

cout << "\nLa matriz transpuesta es: \n";

for (int i=1 ; i <= m ; i++){
    cout << endl ;
    for (int j=1 ; j <= n ; j++){
        cout << "  " ;
        cout <<  At[i][j];
    }
}


cout << endl << endl << endl << endl ;

cout << "\nA continuación vamos a multiplicar la matriz A por una matriz B, de " << m << " filas. "
     << "\nIntroduce el número de columnas de B: ";
cin >> z ;

//lectura de la matriz B:

cout << "\nLectura de la matriz B: \n";

for(int i=1 ; i <= m ; i++)
    for(int j=1 ; j<=z ; j++){
        cout << "Ingresa el valor para B["<<i<<"]["<<j<<"]: ";
        cin >> B[i][j];
        }

// mostramos las matrices a multiplicar

cout << "\n\n\n\nLas matrices introducidas han sido: \n" ;

cout << "\nA: \n" ;

for(int i=1 ; i <= n ; i++){
    cout << endl ;
    for(int j=1 ; j <= m ; j++)
        cout << " " << A[i][j];
    }


cout << "\nB: \n";

for(int i=1 ; i <= m ; i++){
    cout << endl ;
    for(int j=1 ; j <= n ; j++)
        cout << " " << B[i][j];
    }



//Calculamos C:


for(int i=1 ; i <= n ; i++){
    for (int j=1 ; j <= z ; j++){
        C[i][j] = 0 ;
        for (int k = 1 ; k <= n; k++){
        C[i][j] += A[i][z] * B[z][j];
        }
    }

}

//Mostramos C:

cout << "\nLa matriz C, que resulta de multiplicar A*B, es: \n";

for(int i=1 ; i <= n ; i++){
    cout << endl ;
    for(int j=1 ; j <= z ; j++)
        cout << " " << C[i][j];
    }

    }





