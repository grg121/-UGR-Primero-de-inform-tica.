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
                return false ;
            else
                if(cadena[total_utilizados] != otra.Get(total_utilizados) || cadena[0] != otra.Get(0))
                    return false ;
                else {

                SecuenciaDeCaracteres caracteres ;
                int ll = 1 ;
                bool pertenece = true ;
                while(ll < total_utilizados - 1 && pertenece) {
                    ll++ ;
                    int k = 0 ;
                    while (cadena[ll] != caracteres.Get(k))
                        k++ ;
                    if(k = total_utilizados){
                        caracteres.Add(cadena[ll]) ;
                        if(cuentaCaracter(cadena[ll]) != otra.cuentaCaracter(cadena[ll]))
                            pertenece = false ;
                    }
                    }
                    }

                    return true ;

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
