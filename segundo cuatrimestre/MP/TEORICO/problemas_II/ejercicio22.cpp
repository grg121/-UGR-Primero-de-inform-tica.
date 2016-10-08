#include<iostream>
using namespace std;

class VectorSD{
  double *info ;
  int util ;
  int reservado ;

public:

  VectorSD(int n_reserva){
    Set_reservado(n_reserva) ;
    start_info(n_reserva) ;
    Set_util(0) ;
  }

  VectorSD(){
    Set_reservado(0) ;
    start_info(0) ;
    Set_util(0) ;
  }

  int Get_util(){
    return util ;
  }

  void start_info(int lenght){
    info = new double[lenght] ;
  }

  void delete_info(){
    delete info ;
  }

  int Get_reservado(){
    return reservado ;
  }

  double* Get_info(){
    return info ;
  }

  void Set_util(int imput){
    util = imput ;
  }

  void Set_reservado(int imput){
    reservado = imput ;
  }

  void Apunta_a(double *pointer){
    info = pointer ;
  }


  void Add(double elemento){
    if (util = reservado - 1){
      int aux_reserv = reservado ;
      reservado = reservado * 2 ;

      double *aux ;

      aux = info ;

      info = new double[reservado] ;

      for(int i = 0 ; i <= util ; i++){
        info[i] = aux[i] ;
      }

      delete [] aux ;
    }

    info[util] = elemento ;
    util++;
}

  void Copy(VectorSD destino){
    delete [] destino.info ;
    destino.reservado = util ;
    destino.info = new double [destino.reservado] ;
    for ( int i = 0 ; i <= util ; i++){
      destino.info[i] = info[i] ;
    }

  }

  void Mostrar(){

    for( int i = 0 ; i <= util ; i++, info++){
      cout << *info << " " << endl  ;
    }
  }
};



int main(){

  VectorSD nuevo;

  for(int i = 0 ; i <= 9 ; i++){
    nuevo.Add(0.76 * i) ;
  }

  cout << "Datos introducidos. \n \n \n" ;

  cout << nuevo.Get_util() << endl;

  cout << nuevo.Get_reservado() ;

  nuevo.Set_util(0) ;

  cout << endl << nuevo.Get_util() ;


}
