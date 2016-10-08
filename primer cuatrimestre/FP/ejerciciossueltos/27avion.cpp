#include<iostream>
using namespace std;

  int IntroduceLetra(){

  char letra ;
  int _letra ;

    cin >> letra ;

    _letra = toupper(letra) ;

    int compara = 'A' ;
    int contador = 1 ;

    while(compara != _letra){
        contador++ ;
        compara++ ;
        }
    return contador ;

        }



class Avion{
    private:

    // en principio, suponemos que no habrá aviones de mayor tamaño.

        static const int FILAS = 20 ;
        static const int COLUMNAS = 10 ;
        char asientos[FILAS][COLUMNAS] ;

        // Las filas y columnas Reales del avión.

        const int RFIL ;
        const int RCOL ;

        bool asientoOK[FILAS][COLUMNAS] ;
        bool filaOK[FILAS] ;
        bool lleno;
        bool EXIT;


    public:

    Avion(int filas, int columnas)
        :RFIL(filas), RCOL(columnas){

        //inicializamos:

                            //Columna fija de números.

                    for(int i = 0 ; i < RFIL ; i++){
                        asientos[i][0] = '1' + i ;
                    }

                    // Columnas letras. Mayusculas empezando por A, nota: @ es el caracter previo a A en el codigo ASCII.

                    for(int i = 0 ; i < RFIL ; i++){
                        for(int j = 1 ; j < RCOL ; j++){
                        asientos[i][j] = '@' + j ;
                        }
                    }

        for(int i = 0 ; i < RFIL ; i++){
            for(int j = 0 ; j < RCOL ; j++){
                asientoOK[i][j] = false ;
            }
            filaOK[i] = false;
            }
        lleno = false ;
        EXIT = false;

    }

    // Métodos

    bool Getlleno(){
        return lleno;
    }


    void MostrarAsientos(){
    for (int i = 0 ; i < RFIL ; i++ ){
        cout << endl ;
        for (int j = 0 ; j < RCOL ; j++){
            cout << " " << asientos[i][j] << " " ;
        }
      if (filaOK[i])
                cout << " OK " ;
    }
}

 void AsignarAsiento(){

    int fila, columna ;

     cin >> fila ;

     if(fila < 0){
        EXIT = true ;
        }
    else{


     fila-- ;

    columna = IntroduceLetra() ;

    asientos[fila][columna] = 'X' ;
    asientoOK[fila][columna] = true ;
    filaOK[fila] = true ;
    lleno = true ;
    for(int j = 1 ; j < RCOL ; j++ ){
        if(asientoOK[fila][j] == false)
            filaOK[fila] = false ;
        if(filaOK[j] == false)
            lleno = false;
        }
        }
}

 void MuestraAsigna(){
    AsignarAsiento() ;

    cout << endl << endl ;

    MostrarAsientos() ;
}

bool _EXIT(){
    return EXIT ;
}

} ;



int main(){

Avion ejemplo(7, 5) ;


cout << "Bienvenido. Los asientos ocupados se marcan con una X.\n " ;

ejemplo.MostrarAsientos() ;

cout << "\nSelecciona un asiento libre introduciendo <<fila>> espacio <<letra>> y pulsando enter. \n Para finalizar introduzca -1: " ;



while (!ejemplo.Getlleno() && !ejemplo._EXIT() ){

cout << "\nAsigna un nuevo asiento: " ;


ejemplo.MuestraAsigna();

}


cout << "\nNo quedan asientos libres o se ha solicitado la suspensión de la asignación de asientos. " ;

}
