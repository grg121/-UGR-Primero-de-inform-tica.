#include<iostream>
using namespace std;

class SecuenciaCaracteres{

    private:
        static const int WIDTH = 50;
        char vector_privado [WIDTH];
        int total_utilizados;

    public:

      void Add(char nuevo){
        if(total_utilizados < WIDTH){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    string ToString(){
        string cadena;
        for (int i=0 ; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];
            return cadena;
    }};


int main(){
    SecuenciaCaracteres secuencia;
    cout << "Introduce un numero entero, seguido del terminador #: ";
    char caracter = cin.get();
     while(caracter != '#'){
     secuencia.Add(caracter);
     caracter = ' ';
     secuencia.Add(caracter);
     caracter = cin.get();
     }
    string cadena = secuencia.ToString();
    cout << cadena;


    }

