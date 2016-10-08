#ifndef _SEGMENTO_H_
#define _SEGMENTO_H_

#include <string>
#include <cstring>

using namespace std;

  class Segmento10{
  private:
    char *segmento[10] ;
    char *siguiente ;
    int util ;
  public:
    Segmento10();
    bool Add(char caracter);
    int Get_util() ;
    string Get_segmento();
    void point_to_next(char* &puntero) ;


  } ;
