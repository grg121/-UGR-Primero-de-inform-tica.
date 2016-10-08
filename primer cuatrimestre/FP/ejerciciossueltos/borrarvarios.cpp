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
                vector_privado[total_utilizados] = numero;
                  total_utilizados++;
            }
        }

        int Elemento(int posicion){
            return vector_privado[posicion];

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


class SecuenciaDeCaracteres{
    private:
        static const int SIZE = 50 ;
        char cadena[SIZE];
        int total_utilizados;
    public:
        SecuenciaDeCaracteres()
            :total_utilizados(0){}
        int GetTotalUtil(){
            return total_utilizados;
        }
        int GetSize(){
            return SIZE;
        }
        void Add(char caracter){
            if (total_utilizados < SIZE){
                cadena[total_utilizados] = caracter;
                total_utilizados++ ;
            }
        }
        char Get(int indice){
            return cadena[indice];
        }
        void Elimina(int indice){
            if (indice >= 0 && indice < total_utilizados){
                for (int i = indice ; i < total_utilizados - 1 ; i++){
                    cadena[i] = cadena[i+1];
                }
                total_utilizados--;
            }
        }
        void Delete(){
            if(total_utilizados > 1){
                total_utilizados-- ;
                cadena[total_utilizados-1] = cadena[total_utilizados];
            }
        }

        string ToString(){
            string _cadena ;
            for(int i=0 ; i<total_utilizados ; i++){
                _cadena = _cadena + cadena[i] ;
            }
            return _cadena;
        }

        void EliminaVarios(SecuenciaEnteros _a_borrar){
            for(int i=0 ; i < _a_borrar.GetTotalUtilizados() ; i++){
            Elimina(_a_borrar.Elemento(i) - i) ;
            }
            }


};

int main(){

    SecuenciaDeCaracteres secuencia ;
    SecuenciaEnteros a_borrar ;


 cout << "introduce una secuencia de carcteres acabada en # : \n\n" ;

 char caracter = cin.get() ;

 while(caracter != '#'){
    secuencia.Add(caracter) ;
    caracter = cin.get() ;
    }

    string cadena = secuencia.ToString() ;

    cout << "original: " << cadena ;



cout << "\nA continuación, borraremos tantas posiciones como quieras\nPara finalizar introduce -1. \nIntroduce una posicion (empezando en 0) a borrar: " ;

    int numero ;

    cin >> numero ;

    while(numero != -1){
        if(numero < secuencia.GetTotalUtil())
            a_borrar.Add(numero) ;
        cin >> numero ;
    }

    secuencia.EliminaVarios(a_borrar) ;

    cadena = secuencia.ToString() ;

    cout << "\nfinal: " << cadena ;
}






