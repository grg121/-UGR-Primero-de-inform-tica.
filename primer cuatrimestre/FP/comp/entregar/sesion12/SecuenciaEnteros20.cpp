#include<iostream>
using namespace std;

class SecuenciaEnteros{

    private:

        static const int WIDTH = 50;
        int vector_privado[WIDTH];
        int total_utilizados;

    public:

        SecuenciaEnteros()
            :total_utilizados(0){}

        int GetTotalUtilizados(){
            return total_utilizados;
        }

        int GetWIDTH(){
            return WIDTH;
        }

        void Add(int numero){
            if(total_utilizados < WIDTH){
                total_utilizados++;
                vector_privado[total_utilizados] = numero;
            }
        }

        int Elemento(int posicion){
            int elemento = vector_privado[posicion];
            return elemento;
            }

        void Elimina(int posicion){
            if(posicion > 0 && posicion < total_utilizados){
                for (int i = posicion ; i < total_utilizados ; i++){
                    vector_privado[i] = vector_privado[i+1];
                }
                total_utilizados--;
            }

        }

        int ContarSecuenciasAscendentes(){
            int contador = 0;
            for (int i = 1 ; i < total_utilizados ; i++){
                if ( vector_privado[i] < vector_privado[i-1])
                    contador++;
            }
        return contador;
        }

    };

int main(){


 SecuenciaEnteros secuencia;

 cout << "Manejamos una cadena de enteros cuyo máximo son: " << secuencia.GetWIDTH() << " numeros.\n ";


 cout << "Introduce una secuencia de enteros (que no supere el limite ya mencionado). Para finalizar introduzca #. \n";

 int entero = cin.get();

  while( secuencia.GetTotalUtilizados() < secuencia.GetWIDTH()  && entero != '#'){
     secuencia.Add(entero);
     entero = cin.get();
     }

    cout << "\nEl número de secuencias ascendetes es: " << secuencia.ContarSecuenciasAscendentes();





}
