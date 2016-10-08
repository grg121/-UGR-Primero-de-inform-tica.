#include<iostream>
#include<ctime>
using namespace std;

const int MY_MAX_RAND = 50;

time_t t;

srand ((int) time(&t));

int v[100] ;

for (int i=0; i<1000; i++)
v[i] = (int)(1.0*(MY_MAX_RAND+MY_MAX_RAND+1)*rand()/
(RAND_MAX+1.0) - MY_MAX_RAND );

// escribe en pantalla el vector ;

for(int i=0 ; i<100 ; i++){
  cout << v[i] ;
} ;
