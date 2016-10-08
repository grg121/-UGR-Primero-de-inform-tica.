	#include<iostream>
	using namespace std;

	class SecuenciaReal{
		private:
			const static int TAMANIO = 100;
			double v_privado[TAMANIO];
			int total_utilizados;

		public:
			SecuenciaReal()
			:total_utilizados(0){}

			void Aniade(int numero){
				if(total_utilizados<TAMANIO){
					v_privado[total_utilizados]=numero;
					total_utilizados++;
				}
			}
			int TotalUtilizados(){
				return total_utilizados;
			}
			float Elemento(int indice){
				return v_privado[indice];
			}
			SecuenciaReal Suma(SecuenciaReal sec){
				int tope,i,j,k;
				SecuenciaReal local;
				if(total_utilizados<sec.TotalUtilizados())
					tope=total_utilizados;
				else{
					tope=sec.TotalUtilizados();
				}

				for(i=0;i<tope;i++){
					local.Aniade(Elemento(i)+sec.Elemento(i));
				}

				if(total_utilizados<=sec.TotalUtilizados())
					for(j=tope;j<=sec.TotalUtilizados();j++){
						local.Aniade(sec.Elemento(j));
					}
				else{
					for(k=tope;k<total_utilizados;k++){
						local.Aniade(Elemento(k));
					}
				}
				return local;
			}
			void Muestra(){
				for(int i=0;i<total_utilizados;i++){
					cout<<" "<<v_privado[i];
				}
			}

	};
	int main(){
		double numero;
		int i;

		SecuenciaReal sec1;
		SecuenciaReal sec2;


		cin>>numero;
		while(numero!=0){
		 sec1.Aniade(numero);
		 cin>>numero;
		}

		cout << endl ;

		cin>>numero;
		while(numero!=0){
			sec2.Aniade(numero);
			cin>>numero;
		}

		SecuenciaReal sec3=(sec1.Suma(sec2));

	 sec3.Muestra();
	}


