#include<iostream>
using namespace std;
int main (){
   for (int j = 1; j < 10 ; j++){
         for ( int i = 9 ; i > 0 ; i--){
               if ( j >= i)
                  cout << i ;
               else
                  cout << " " ;
         }
         cout << endl;
   }


}
