#include<iostream>
#include<assert.h>
#include<algorithm> /* SWAP */
using namespace std;


  class VectorD{
    private:
	float *datos ;
	int nelementos ; 

  public:
      //------------------------CONSTRUCTORES --------------------------
      VectorD(int n = 0);
      VectorD(const VectorD &original);

      //------------------------DESTRUCTOR-----------------------------
      ~VectorD();

      //-----------------------FUNCIONES PRINCIPALES--------------------
      int Size() const { return nelementos ; } 
      float Get(int i) const { return datos[i] ; }
      void Set(int i, float v){ 
		assert( 0 <= i && i< nelementos) ; 
		datos[i] = v ; 
      }
      void Resize(int n) ;
      VectorD& operator= (const VectorD &original) ;


} ; 

	

// CONSTRUCTORES 
	
	/*Por defecto */
	VectorD::VectorD(int n){
		nelementos = n ;
		if(nelementos > 0){
			datos = new float [nelementos] ;
			for(int i = 0 ; i < nelementos ; i++){
				datos[i] = 0 ;
		}
		} else datos = NULL ; 
	}

	/*De copia */
	VectorD::VectorD(const VectorD & original){
		nelementos = original.Size() ;
		if(nelementos > 0){
			datos = new float[nelementos] ; 
			for(int i = 0 ; i < nelementos ; i++){
				datos[i] = original.Get(i) ; 
			}
		} else datos = NULL ; 
	}

// DESTRUCTOR 
	
	VectorD::~VectorD(){
		if(nelementos > 0) delete [] datos ;
	}

// OPERADOR DE ASIGNACIÓN. 
	VectorD& VectorD::operator= (const VectorD & orig){
		VectorD aux(orig) ;
		
		swap(this, orig) ;

	}

// MÉTODOS BÁSICOS

 	/* Función de redimensionamiento */ 
 	void VectorD::Resize(int n){
		assert(n>=0) ;
		
		if(n != nelementos){
			if(n != 0){
				float * nuevos_datos ;
				nuevos_datos = new float[n] ; 
				int minimo = nelementos<n?nelementos:n ; 
				for(int i = 0 ; i < minimo ; i++){
					nuevos_datos[i] = datos[i] ;
				}
			}
			nelementos = n ;
			datos = nuevos_datos ; 
			
			}else{
	
			if(nelementos > 0) delete [] datos ; 
			nelementos = 0 ; 

	}



/*Asignar a la posición i el valor i para todas las posiciones */ 
  void CargarIndices(VectorD &v){
	for(int i=0 ; i < v.Size() ; i++){
		v.Set(i,i) ; 
	}

/*Devuelve el valor máximo de un vector */
  float Maximo(const VectorD &v){
	float max = 0 ;
	
	if(v.Size() != 0){
		for(int i=0 ; i < v.Size() ; i++){
			if(max<v.Get(i)
				max = v.Get(i); 
		}		
        }
  }

  int main(int argc, char argv[]){
	VectorD vec ;
	
	CargarIndices(vec) ;

	cout << "Máximo de " << vec.Size << " elementos: "
	     << Maximo(vec)  << endl ;

	vec.Resize(10) ;

	CargarIndices(vec) ; 
	
	cout << "Máximo de " << vec.Size << " elementos; " 
	     << Maximo(vec)  << endl ; 




	cout << endl << " USAMOS EL CONSTRUCTOR POR DEFECTO CON EL OPERADOR DE ASIGNACIÓN: " << endl ; 

	


	VectorD nuevo = vec ; 

	cout << "Máximo de " << nuevo.Size << " elementos; " 
	     << Maximo(nuevo)  << endl ; 


	

	return 0 ; 
	
}	









 
