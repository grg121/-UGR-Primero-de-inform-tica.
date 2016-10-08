#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <string>
#include <cstring>
#include<segmento.h>
using namespace std;


  class Vector{
  private:
    Segmento10 *inicio ;
  public:
    Vector() ;

    ~Vector();

    void Get_vector() ;

    void add(char elemento) ;

    void add(string cadena) ; 






  }
