#include<iostream>
using namespace std;



// Mi clase "Secuencia de Carácteres"

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

        int cuentaCaracter(char caracter){
            int contador = 0 ;
            for (int i = 0 ; i < total_utilizados ; i++)
                if(cadena[i] = caracter)
                    contador++;
            return contador;
                }



        bool similar (SecuenciaDeCaracteres otra){
            bool es_similar = true ;

            if(total_utilizados != otra.GetTotalUtil())
                es_similar = false ;
            else
                if(cadena[total_utilizados-1] != otra.Get(total_utilizados-1) || cadena[0] != otra.Get(0))
                    es_similar = false ;

                else {

                SecuenciaDeCaracteres caracteres ;
                int ll = 1 ;
                while(ll < total_utilizados - 1) {
                    ll++ ;
                    int k = 0 ;
                    while (cadena[ll] != caracteres.Get(k) && k < total_utilizados -1){
                        k++ ;
                    } if(k = total_utilizados - 1){ // si esto se cumple, el caracter no está registrado, se registra.
                        caracteres.Add(cadena[ll]) ;
                    // Ahora comprobamos que las dos palabras tengan el mismo número de veces este caracter, sólo si este no estaba registrado ya.
                        if(cuentaCaracter(cadena[ll]) != otra.cuentaCaracter(cadena[ll]))
                            es_similar = false ;
                        }
                }
            }
            return es_similar ;
    }


};



int main(){

SecuenciaDeCaracteres sec1, sec2 ;

cout << "Introduce una palabra. Señala el final de la misma con #: \n" ;
char letra ;

cin >> letra ;
while(letra != '#'){
    sec1.Add(letra);
    cin >> letra ;
}

string cadena1 = sec1.ToString() ;

cout << "Has introducido:  " << cadena1 << " ; introduce otra palabra: \n" ;
cin >> letra ;
while(letra != '#'){
    sec2.Add(letra);
    cin >> letra ;
}

string cadena2 = sec2.ToString() ;

cout << "Has introducido:  " << cadena2 << " ; Comprobemos si son palabras ''similares'' \n\n" ;


if(sec1.similar(sec2))
    cout << "son similares" ;
else
    cout << "No son similares." ;
}
