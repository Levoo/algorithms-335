/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 2, Horners Algorithm problem #3
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> coef;
vector<int> power;
// x is coef, y is power, z is clone of max power that decrements
int a, x, y,z, max = 0, total = 0;

int main() {
	cout << "To Compute the value of f(a)" << endl;
	do {	//Loops to get input for coefficient and power vector
		cout << "Enter the coefficient and the power of each term(0 0) to stop:";
		cin >> x >> y;
		//Checks if exit code is inputted
		if (x == 0 && y == 0) { break; }
		if (y > max) {
			max = y;	//Gets the max power as user inputs
			z = y -1;
		}
		while ((y-1) != z) {	//Makes sure the input is sequencial
			coef.push_back(0);	//If not then puts in a buffer
			power.push_back(1);
			--z;
		}
		coef.push_back(x);
		power.push_back(y);
		--z;
	} while ((x != 0) || (y != 0));
	cout << "Enter the value of a:";
	cin >> a;
	//Does Horners Algorithm
	total = coef[0];
	for (int i = 1; i <= max; ++i) {
		total = (a * total) + coef[i];
	}
	cout << "f(a) = " << total << endl;
	system("pause");
}
