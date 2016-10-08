#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char * argv[]){
  if(argc==3){
    ifstream orig(argv[1]) ;
    if(!orig){
      cerr << "Imposible abrir " << argv[1] << endl ;
      return 1 ;
    }
    ofstream dest(argv[2]) ;
    if(!dest){
      cerr << "Imposible abrir " << argv[2] << endl ;
      return 1 ; 
    }
    char c ;
    while(orig.get(c))
      dest.put(c) ;
    if(!orig.eof()||!dest){
        cerr << "La copia no ha tenido exito " << endl ;
        return 1 ;
    }
  } return 0 ;
}
