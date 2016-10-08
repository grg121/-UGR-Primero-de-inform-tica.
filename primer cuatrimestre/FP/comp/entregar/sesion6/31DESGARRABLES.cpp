#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int entero, divisor = 0,
     izquierda, derecha;

    bool is_torn ;

    cout << "Insert a whole number. \n"
         << "(This program is going to calculate if it is a torn number.) \n "
         << "A number n is a torn number if it can be chopped into two parts which, \n when added together and squared, are equal to the original number. \n";

    cin >> entero ;

    do {
    divisor   = divisor + 10     ;
    izquierda = entero / divisor ;
    derecha   = entero % divisor ;

    is_torn = pow(izquierda + derecha, 2) == entero ;

    }while (! is_torn && divisor < entero);

    if ( is_torn)
        cout << entero << " is a torn number; "
             << "("      << izquierda << " + " << derecha
             << ")^2 = " << entero ;
    else
        cout << entero << " ins't a torn number.";

    }
