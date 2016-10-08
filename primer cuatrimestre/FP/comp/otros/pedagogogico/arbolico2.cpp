#include<iostream>
using namespace std;
int main (){
int i;
   for (int j = 8; j >= 0 ; j--){
         for (i = 1 ; i < 10 ; i++){
               if ( i >= j && i - j != 0)
                  cout << i - j ;
               else
                  cout << " " ;
         }

         for (i = 8 ; 1 > 0 ; i--){

                  cout << i - j ;

                  }
         cout << endl;
   }


}
