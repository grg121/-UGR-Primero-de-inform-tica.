#include<iostream>
using namespace std;

class Login{
    private:
        int num_caracteres_a_coger;
    public:
        Login(int numero_caracteres_a_coger)
            :num_caracteres_a_coger(numero_caracteres_a_coger){}

        string Codifica(string nombre_completo){
            string name = "" ;
            int contador = 0 ;
            int width = nombre_completo.size();

            for (int i=0 ; i <= width ; i++){

                    if(nombre_completo[i] != ' '){
                        if(contador<num_caracteres_a_coger){
                        contador++;
                        name.push_back(tolower(nombre_completo[i]));
                    }
                    }
                    else
                        contador = 0 ;

            }

            return name ;
        }

        int GetNumCar(){
        int numero = num_caracteres_a_coger;
        return numero;
        }
    } ;

int main(){

    int num_car ;

    cout << "Introduce el número de carácteres a emplear\n";
    cin >> num_car;


   Login nombre(num_car);

   cout << "\nIntroduce tu nombre y apellidos, seguidos del terminador ''#''\n\n " ;

   char caracter ;
   string cadena ;
   caracter = cin.get();

     while(caracter != '#'){
     cadena.push_back(caracter);
     caracter = cin.get();
     }

     cout << "\nLa cadena introducida ha sido: \n\n" << cadena ;

     string username = nombre.Codifica(cadena);

     cout << "\nEl username sugerido es: " << username ;






    }
