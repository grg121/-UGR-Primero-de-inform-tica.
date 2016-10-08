#include<iostream>
using namespace std;

  int LIMITE_HORAS_NORMALES  = 40 ;
  double AUMENTO_HORAS_EXTRA = 0.5;

class NominasEmpresa{

    private:

            double pago_por_hora;
            double salario_mensual;

        public:

            int HorasNormales(int horas_totales){
                int horas_normales;
                if (horas_totales  > LIMITE_HORAS_NORMALES)
                    horas_normales = LIMITE_HORAS_NORMALES;
                return horas_normales ;
                }

            int HorasExtra(int horas_totales = 0){
                int horas_extra;
                if (horas_totales > LIMITE_HORAS_NORMALES)
                    horas_extra = horas_totales - LIMITE_HORAS_NORMALES;
                return horas_extra;
                }
            NominasEmpresa (double paga){
                salario_mensual = 0  ;
                pago_por_hora = paga ;
                }

            void CalculoSueldo(int horas_trabajadas){
                double horas_normales = HorasNormales(horas_trabajadas);
                double horas_extra    = HorasExtra (horas_trabajadas);
                double sueldo_extra = pago_por_hora + pago_por_hora * AUMENTO_HORAS_EXTRA;
                double sueldo = pago_por_hora * horas_normales + horas_extra * sueldo_extra;
                salario_mensual = sueldo ;

                }

            void MuestraSalarioMensual(){
                cout << salario_mensual;
            }
    };

int main (){

    NominasEmpresa Juan(5);

    // supongamos que Juan ha trabajado 65 horas

    Juan.CalculoSueldo(65);

    cout << "El salario de Juan será de: ";

    Juan.MuestraSalarioMensual();

    cout << " euros. \n";



    }
