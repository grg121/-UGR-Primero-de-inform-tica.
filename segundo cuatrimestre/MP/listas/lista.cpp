#include<iostream>
#include<fstream>
#include<assert.h>
#include<iomanip>
using namespace std;


// ESTRUCTURA LIFO Last In First Out

struct CeldaPila{
  char elemento ;
  CeldaPila *siguiente;
} ;


class Pila {
private:
  CeldaPila *primera ;
  friend ostream &operator<<(ostream &s, const Pila &p) ;

public:
//Constructor por defecto
  Pila() ;
//Constructor de copia
  Pila(const Pila & p) ;
//Destructor
  ~Pila();
//Operador de asignación
  Pila& operator= (const Pila &p) ;

//Funciones básicas
  bool vacia() const ;
  void poner(char c) ;
  void quitar() ;
  char tope() const ;

//Otras funciones
  char sacar() ; // devuelve el elemento del tope y lo quita.
} ;

Pila::Pila(){
  primera = NULL ;
}

Pila::Pila(const Pila & p){
  if(p.primera != NULL){
    this->primera = new CeldaPila ;
    this->primera->elemento = p.primera->elemento ;
    this->primera->siguiente = NULL ;

    CeldaPila *read = p.primera->siguiente ;
    CeldaPila *write = this->primera->siguiente ;

    while(read != NULL){
        write = new CeldaPila ;
        write->elemento = read->elemento ;
        write->siguiente = NULL ;
        write = write->siguiente ;
        read  = read->siguiente  ;
    }


  }
}

Pila::~Pila(){
  if(this->primera != NULL){
    CeldaPila *borrar = this->primera ;
    CeldaPila *aux = NULL ;

    while(borrar->siguiente != NULL){
      aux = borrar->siguiente ;
      delete borrar ;
      borrar = aux ;
    } delete borrar ;
  }
}

Pila &Pila::operator=(const Pila &p){
  if(this->primera != p.primera){
    Pila copia(p) ;
    CeldaPila * aux ;
    aux = this->primera ;
    this->primera = copia.primera ;
    copia.primera = aux ;
    return *this ;
  }
}

char Pila::sacar(){
  char c = tope() ;
  quitar() ;
  return c ;
}

bool Pila::vacia() const { return primera == 0 ; }

char Pila::tope() const {
  assert(primera != 0) ;
  return primera->elemento ;
}

void Pila::poner(char c){
  CeldaPila *nueva = new CeldaPila ;
  nueva->elemento = c ;
  nueva->siguiente = this->primera ;
  this->primera = nueva  ;
}

void Pila::quitar(){
  if( primera != 0){
  CeldaPila * aux = primera ;
  primera = primera->siguiente ;
  delete aux  ;
}
}

ostream &operator<<(ostream &s, const Pila &p){
  if(p.primera != NULL){
    CeldaPila *aux = p.primera ;
    s.width(30) ;
    s.fill(' ') ;
    s.setf(ios::right,ios::adjustfield) ;
    s << " [" << aux->elemento << "] \n" ;
    aux = aux->siguiente ;
    while(aux != NULL){
      s.width(30) ;
      s.fill(' ') ;
      s.setf(ios::right,ios::adjustfield) ;
      s << " [" << aux->elemento << "]\n" ;
      aux = aux->siguiente ;
    }

    return s ;

  }

}


int main(){
  Pila p ;

  char a ;

  char dato ;

  while(dato != '#'){
  cin >> dato ;
  if(dato != 'q')
    p.poner(dato) ;
  else  a = p.sacar() ;

 for(int i = 0 ; i<24 ; i++)
    cout << "\n" ;
  cout << p ;

  if(dato == 'q')
    cout << setw(10) << right <<setfill('*') << a << endl ;
  }





}
