#include<polinomio.h>
#include<iostream>
using namespace std;

int main(){


  Polinomio a, b(10) ;

  for(int i = 0 ; i <= a.GradoMaximo() ; i++){
  a.AsignarCoeficiente(i, i) ;
  b.AsignarCoeficiente(b.GradoMaximo() - i, i) ;
  }

  Polinomio c, d(a) ;

  c = b ;

  cout << "\n A: \n\t" ;
  for(int i = 0 ; i <= a.GradoMaximo() ; i++){
    cout << a.Coeficiente(i) << "  ";
  }

  cout << "\n B: \n\t" ;
  for(int i = 0 ; i <= b.GradoMaximo() ; i++){
    cout << b.Coeficiente(i) << "  " ;
  }

  cout << "\n C: \n\t" ;
  for(int i = 0 ; i <= c.GradoMaximo() ; i++){
    cout << c.Coeficiente(i) << "  " ;
  }

  cout << "\n D: \n\t" ;
  for(int i = 0 ; i <= d.GradoMaximo() ; i++){
    cout << d.Coeficiente(i) << "  " ;
  }

}
