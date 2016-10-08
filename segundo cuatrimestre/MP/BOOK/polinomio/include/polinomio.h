
  class Polinomio{
    private:
      float *coef;
      int grado ;
      int max_grado ;

  public:
      Polinomio(int grado_maximo = 10) ;
      Polinomio(const Polinomio &original) ;
      ~Polinomio();

      Polinomio& operator= (const Polinomio& original) ;

      void AsignarCoeficiente(int i, float c) ;
      int Grado() const { return grado; } // método inline.
      int GradoMaximo() const { return this->max_grado; } // método inline.
      float Coeficiente(int i) const ;



  } ;
