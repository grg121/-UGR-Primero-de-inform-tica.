#include<iostream>
using namespace std;

class TableroBuscaMinas{

    private:

    static const int TAM = 30 ;
    bool datos[TAM][TAM] ;
    int fil, col ; //filas y columnas. contandose la numero 0.

    public:
    TableroBuscaMinas(int filas, int columnas)
        :fil(filas), col(columnas){
            for(int i = 0 ; i < fil ; i++)
                for(int j = 0 ; j < col ; j++){
                    datos[i][j] = false ;
                    }
        }

    TableroBuscaMinas()
        :TableroBuscaMinas(10,10){}

    int GetFil(){
        return fil ;
    }

    bool dentro(int fila, int columna){  //comprueba que la casilla está dentro del tablero
        bool dentro = fila >= 0 && fila < fil && columna >= 0 && columna < col;
        return dentro ;
        }

    int GetCol(){
        return col;
    }

    void PlantaMina(int fila, int columna){
        if (dentro(fila, columna))
            datos[fila][columna] = true ;
    }

    bool Minado(int fila, int columna){ // COMPRUEBA SI HAY MINA EN UNA CASILLA
        if(dentro(fila, columna) && datos[fila][columna])
            return true ;
        else
            return false ;

    }

    int Prueba(int fila, int columna){
        if(datos[fila][columna])
            return -1 ;
        else{
            int minas = 0 ;
            for(int i = fila - 1 ; i <= fila + 1 ; i++)
                for (int j = columna - 1 ; j <= columna + 1 ; j++)
                    if(dentro(i, j) && datos[i][j])
                        minas++ ;
            return minas ;
            }
        }
};

int main(){

TableroBuscaMinas tablero ; // Por defecto se crea una matriz 10x10

cout << "introduce las coordenadas (x,y) empezando por 0 donde colocal una mina, separadas por un espacio. Para finalizar introduce -1\n";

int x,y ;


cin >> x ;
if(x != -1)
    do{
    cin >> y;
    if(x >= 0 && y >= 0 && x < tablero.GetFil() && y < tablero.GetCol() )
        tablero.PlantaMina(x,y) ;
    cin >> x;
    }while(x != -1) ;

cout << "Introduce las coordenadas de la casilla que quieres probar: ";

cin >> x ;
cin >> y ;

cout << "\n " << tablero.Prueba(x, y);

cout << "\n\n -1 significa que hay una mina en esa casilla, cualquier otro número indica el número de minas en las casillas adyacentes. ";


















}
