#include <iostream>
using namespace std;

    bool DatoCorrecto(int dato){
        bool es_correcto = dato >= 0 && dato <= 10;
        return es_correcto ;
        }

    bool NotaSuspenso(double nota){
        bool suspenso = nota < 5;
        return suspenso;
    }

class AlumnoFP{

    private:

    string nombre,
           apellido,
           DNI;

// los porcentajes de las distintas partes consideradas: 70 % teoría,//
// 5 % parcial 1, 15 % parcial 2 y 10 % participación.
    double  teoria,
            parcial1,
            parcial2,
            participacion;

    bool EsCorrecto(double teoria, double parcial1, double parcial2, double participacion){
        bool es_correcto = DatoCorrecto(teoria) && DatoCorrecto(parcial1) && DatoCorrecto(parcial2) && DatoCorrecto(participacion);
        return es_correcto;
        }


    public:

    AlumnoFP(string set_nombre, string set_apellido, string set_DNI, double set_teoria, double set_parcial1, double set_parcial2, double set_participacion){
        nombre   = set_nombre  ;
        apellido = set_apellido;
        DNI      = set_DNI     ;

        do{
        teoria   = set_teoria  ;
        parcial1 = set_parcial1;
        parcial2 = set_parcial2;
   participacion = set_participacion;
        }while(!EsCorrecto(teoria, parcial1, parcial2, participacion));
   }

    double NotaFinal(){
        double
               teoria_porcentaje   = teoria        * 0.7  ,
               parcial1_porcentaje = parcial1      * 0.05 ,
               parcial2_porcentaje = parcial2      * 0.15 ,
          participacion_porcentaje = participacion * 0.10 ,
               nota_final = teoria_porcentaje + parcial1_porcentaje + parcial2_porcentaje + participacion_porcentaje ;

               return nota_final;
               }

};

int main () {

    string nombre, apellido, dni;
    double teoria, parcial1, parcial2, participacion;

    cout << "Rellene el siguiente formulario con los datos del estudiante: \n\n\n" ;

    cout << "Nombre: " ;
        cin  >> nombre ;

    cout << endl
           << "Primer apellido: ";
        cin  >> apellido ;

    cout << endl
           << "DNI: ";
         cin >> dni;

    cout << endl
           << "(Los siguientes datos toman valores entre 0 y 10)\n\n"
           << "Nota de teoria: ";
         cin >> teoria;

    cout << endl
           << "Nota del primer parcial: " ;
         cin >> parcial1;

    cout << endl
           << "Nota del segundo parcial: ";
         cin >> parcial2;

    cout << endl
           << "Nota de participacion en clase: ";
         cin >> participacion ;

    AlumnoFP alumno (nombre, apellido, dni, teoria, parcial1, parcial2, participacion);

         if (NotaSuspenso(teoria))
            cout << "\nHa suspendido el examen de teoría con un: " << teoria ;
         if (NotaSuspenso(parcial1))
            cout << "\nHa suspendido el primer parcial con un: " << parcial1;
         if (NotaSuspenso(parcial2))
            cout << "\nHa suspendido el segundo parcial con un: " << parcial2;
         if (NotaSuspenso(participacion))
            cout << "\nTiene una mala nota en participacion. Un: " << participacion ;

    cout << "\nLa nota final del alumno es: " << alumno.NotaFinal();


}
