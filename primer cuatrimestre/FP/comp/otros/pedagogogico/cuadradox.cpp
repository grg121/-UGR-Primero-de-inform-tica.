#include<iostream>
using namespace std;
int main (){
   for (int j = 0; j < 10; j++){
      for (int i = 0; i < 10; i++){
      if(i == j || i+j == 9)
      cout << "0 " ;
      else
         cout << "x " ;
      }
   cout << endl ;}

}
