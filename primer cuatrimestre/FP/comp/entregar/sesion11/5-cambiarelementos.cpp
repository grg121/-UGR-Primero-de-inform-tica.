#include<iostream>
using namespace std;

class SecuenciaCaracteres {

    private:
        static const int WIDTH = 50;
        char vector_privado [WIDTH];
        int total_utilizados;

    public:

    SecuenciaCaracteres()
        :total_utilizados(0){
    }

    int GetTotalUtilizados(){
        return total_utilizados;
    }

    int getWidth(){
        return WIDTH;
    }

    void Add(char nuevo){
        if(total_utilizados < WIDTH){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    char Elemento(int indice){
        return vector_privado[indice];
    }

    void Elimina(int posicion){
        if(posicion >= 0 && posicion < total_utilizados){
            int tope = total_utilizados-1;
            for(int i = posicion ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];
            total_utilizados--;
            }
    }

    string ToString(){
        string cadena;
        for (int i=0 ; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];
            return cadena;
    }

    void Cambiar(int elemento1, int elemento2){
        char aux = vector_privado[elemento1];
        vector_privado[elemento1] = vector_privado[elemento2];
        vector_privado[elemento2] = aux;
        }

        void Invert(){
            int i = 0 ;
            int j = total_utilizados - 1;
        while ( i < total_utilizados/2 ){
            Cambiar(i, j);
            i++;
            j--;
        }
        }

    bool EsPalindromo(){
        int i = 0 ;
        int j = total_utilizados - 1;
        bool es_palindromo = vector_privado[i] == vector_privado[j];
        int contador = 1 ;
        while (es_palindromo && contador <= total_utilizados/2){
        j-- ;
        i++ ;
        contador ++ ;
        es_palindromo = vector_privado[i] == vector_privado[j] ;
        }
        }

    int CuentaMayusculas(){
        int mayusculas = 0;
        for (int k = 0 ; k < total_utilizados ; k++){
            if (vector_privado[k] >= 'A' && vector_privado[k] <= 'Z')
            mayusculas++;
            }
            return mayusculas;

    }

};

int main(){

    //definimos un objeto de la clase SecuenciaCaracteres

 SecuenciaCaracteres secuencia;

 cout << "Manejamos una cadena de carácteres cuyo máximo son: " << secuencia.getWidth() << " caracteres.\n ";

    // Pedimos al usuario que introduzca los carácteres que desee.

 cout << "Introduce una secuencia de carácteres (que no supere el limite ya mencionado). Para finalizar introduzca #. \n";

 char caracter = cin.get();

  while( secuencia.GetTotalUtilizados() < secuencia.getWidth()  && caracter != '#'){
     secuencia.Add(caracter);
     caracter = cin.get();
     }

     string cadena = secuencia.ToString();

 cout << "\nLa secuencia de carácteres introducida ha sido: \n"
      << cadena << "   Con " << secuencia.GetTotalUtilizados() << "/" << secuencia.getWidth() << " caracteres utilizados.\n";

    secuencia.Invert();

    cadena = secuencia.ToString();

cout << "\nSi le damos la vuelta a la cadena obtenemos: \n" << cadena ;





 }
