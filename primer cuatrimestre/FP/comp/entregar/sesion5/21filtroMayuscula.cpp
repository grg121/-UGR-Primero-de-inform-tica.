#include<iostream>
using namespace std;

int main (){

    char caracter;
    cout << "Insert a capital letter: " ;
    do {
    cin >> caracter ;
    }while (caracter < 'A' || caracter > 'Z');
    cout << "OK. You have intrude the capital letter: " << caracter;


}
