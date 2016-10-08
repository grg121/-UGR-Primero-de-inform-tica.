#include<polinomio.h>

  Polinomio::Polinomio(int grado_maximo){
    this->max_grado = grado_maximo;
    this->coef = new float[max_grado+1] ;
    // inicializar a nulo
    for(int i=0 ; i < this->max_grado ; i++){
      this->coef[i] = 0 ;
    this->grado = 0 ;
    }
  }

  Polinomio::Polinomio(const Polinomio &original){
    int i ;
    this->grado = original.grado ; 
    this->max_grado = original.max_grado ;
    this->coef = new float[this->max_grado+1] ;

    for( i=0; i <= this->max_grado ; i++){
      this->coef[i] = original.coef[i] ;
    this->grado = original.grado ;
    }
  }

  Polinomio::~Polinomio(){
    delete [] this->coef ;
  }

  Polinomio& Polinomio::operator=(const Polinomio& original){
    if(&original != this){
      delete [] this->coef;

      this->grado = original.grado ;
      this->max_grado = original.max_grado ;
      this->coef = new float[this->max_grado+1] ;
      for(int i=0 ; i <= this->max_grado ; i++){
        this->coef[i] = original.coef[i] ;
      }
    } return *this ;
  }

  float Polinomio::Coeficiente(int i) const{
    float salida = -1 ;
    if(i >= 0 && i < this->max_grado+1)
      salida = this->coef[i] ;

    return salida ;
  }

  void Polinomio::AsignarCoeficiente(int i, float c){
    if(i >= 0 && i < this->max_grado+1)
      this->coef[i] = c ;
  }
