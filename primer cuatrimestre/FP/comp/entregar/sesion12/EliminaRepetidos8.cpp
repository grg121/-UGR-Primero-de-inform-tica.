#include<iostream>
using namespace std;

bool EsMayuscula(char letra){
    bool Mayuscula = letra >= 'A' && letra <= 'Z' ;
    return Mayuscula ; }

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



    string ToString(){
        string cadena;
        for (int i=0 ; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];
            return cadena;
    }

    string ToInvertedString(){
        string anedac;
        for (int i = total_utilizados -1 ; i >= 0; i--)
            anedac = anedac + vector_privado[i];
            return anedac;
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
            if (EsMayuscula(vector_privado[k])){
            mayusculas++;}
        }
    return mayusculas;
    }


     void Elimina(int posicion){
        if(posicion >= 0 && posicion < total_utilizados){
            int tope = total_utilizados-1;
            for(int i = posicion ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];
            total_utilizados--;
            }
    }

    //DOS FUNCIONES NO OPTIMIZADAS.


    void EliminaMayusculas(){
        for (int i = total_utilizados - 1 ; i >= 0 ; i--){
            if (EsMayuscula(vector_privado[i]))
                Elimina(i);
        }
    }

    void EliminaRepetidos(){
        char borrar;
        for(int i=0 ; i < total_utilizados ; i++){
            borrar = vector_privado[i];
            for(int k = total_utilizados - 1 ; k > i ; k--){
                if (vector_privado[k] == borrar)
                    Elimina(k);
            }

        }
    }

// OPTIMIZAMOS LA FUNCIÓN PARA ELIMINAR REPETIDOS.

void DeleteRepeated(){
    int contador = 0 ;
    int lectura = 0, escritura = 0 ;
    bool vector_repetidos[total_utilizados] ;
    for (int i = 0 ; i < total_utilizados ; i++)
        vector_privado[i] = false ;
    for(int i = 0 ; i < total_utilizados ; i++){
        for(int j = i+1 ; j < total_utilizados ; j++ ){
            if(vector_privado[j] == vector_privado[i])
                vector_repetidos[j] = true ;
        }
    }
    while(lectura < total_utilizados){
        if(vector_repetidos[lectura] = false){
            vector_privado[escritura] = vector_privado[lectura];
            escritura++;
        }
        else{contador++ ;};
        lectura++;
    }total_utilizados -= contador ;
        }
};

int main(){

    //definimos un objeto de la clase SecuenciaCaracteres

 SecuenciaCaracteres secuencia;

 cout << "Manejamos una cadena de carácteres cuyo máximo son: " << secuencia.getWidth() << " caracteres.\n ";


 cout << "Introduce una secuencia de carácteres (que no supere el limite ya mencionado). Para finalizar introduzca #. \n";

 char caracter = cin.get();

  while( secuencia.GetTotalUtilizados() < secuencia.getWidth()  && caracter != '#'){
     secuencia.Add(caracter);
     caracter = cin.get();
     }

     string cadena = secuencia.ToString();

 cout << "\nLa secuencia de carácteres introducida ha sido: \n"
      << cadena << "   Con " << secuencia.GetTotalUtilizados() << "/" << secuencia.getWidth() << " caracteres utilizados.\n";

 cout << "\nA continuacion, se borrarán todos los carácteres repetidos. \n";

 secuencia.DeleteRepeated();

 cadena = secuencia.ToString();

 cout << "\nLa cadena sin caracteres repetidos es: ";

 cout << cadena;




 }
