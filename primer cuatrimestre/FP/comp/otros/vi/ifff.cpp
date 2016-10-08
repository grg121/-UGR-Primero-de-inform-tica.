#include<iostream>
#include<cmath>
using namespace std;
int main (){
	int edad;
	cout << "introduce tu edad: ";
	cin >> edad;
	if ( edad >= 0 && edad <= 100)
	     cout << "true";
	if (!(edad >= 0 && edad <= 100))
	     cout << "false";
}
