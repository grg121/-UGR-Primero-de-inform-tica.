#include<iostream>
using namespace std;
int main (){
    int i,j;
    for(j = 8 ; j >= 0 ; j--){
        for (i = 1 ; i <=9 ; i++){
            if (i > j && i-j != 0)
            cout << i-j ;
            else
            cout << " ";
        }

        for (i = 8; i >0 ; i--){
            if(i > j && i-j != 0)
                cout << i-j ;
            else
                cout << " " ;}
        cout << endl ;}
        }



