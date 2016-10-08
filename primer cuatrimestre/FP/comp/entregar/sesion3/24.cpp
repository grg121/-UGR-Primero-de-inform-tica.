#include<iostream>
#include<cmath>
using namespace std;
int main () {
//A
    int chico, chico1, chico2;
    chico1 = 123456789;
    chico2 = 123456780;
    chico = chico1 * chico2; // el resultado sería 1.52e15 aproximadamente.
    cout << chico << endl; // devuelve 1425960444 (problema de desbordamiento)
//B
    long grande;
    grande = chico1 * chico2 ;
    cout << grande<< endl; // devuelve 1425960444 (también es un problema de desbordamiento)
//C
    double resultado, real1, real2;
    real1 = 123.1;
    real2 = 124.2;
    resultado = real1 * real2 ;// el resultado correcto es 15289.02
    cout << resultado<< endl; // devuelve 15284 (problema de redondeo)
//D
    real1 = 123456789.1;
    real2 = 123456789.2;
    resultado = real1 * real2 ;// el resultado correcto seria 1.524157879e16
    cout << resultado<< endl; // devuelve 1.52416e16 (No hay problemas, si se quieren más decimales se podría configurar el programa para ello)
//E
    double real, otro_real;
    real = 2e34;
    otro_real = real + 1;
    otro_real = otro_real - real; // deberia devolver 1
    cout << otro_real<< endl; // devuelve 0, es un problema de redondeo.
//F
   real = 1e+300;
   otro_real = 1e+200;
   otro_real = otro_real*real; // deberia devolver 1e+500
   cout << otro_real<< endl; // devuelve infinito. Problema de desbordamiento. (demasiadas cifras se "redondean" a infinito.
//G
  float float_chico;
  double double_grande;
  double_grande = 2e+150;
  float_chico = double_grande; // debería devolver 2e+150
  cout << float_chico<< endl ; // devuelve infinito. Problema de desbordamiento. (demasiadas cifras se "redondean" a infinito.
    }
