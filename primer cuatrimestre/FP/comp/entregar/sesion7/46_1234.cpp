#include<iostream>
using namespace std;
int main () {
    for (int j = 1 ; j < 7 ; j++){
        for (int i = j ; i != j + 6 ; i++)
            cout << i << " " ;
        cout << endl ;
    }
}
