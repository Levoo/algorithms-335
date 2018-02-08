#include <iostream>
#include <vector>
using namespace std;

vector<int> coef;
vector<int> power;
int a, x, y, max = 0;

void printresults() {	//prints the f(a)
	cout << "f("<< a << ") = ";
	for (int i = 1; i < max; ++i) {	//beginning "a(a(a(a(a(a......"
		cout << a << "(";
	}
	cout << coef[0] << "*" << a << "+" << coef[1];	//Middle part "ax + b)"
	for (int i = 2; i < coef.size() - 1; ++i) { //ending ")+c)+d)+e"
		cout << ")+" << coef[i];
	}
	cout << endl;
}

int main() {
	cout << "To Compute the value of f(a)" << endl;
	do {	//Loops to get input for coefficient and power vector
		cout << "Enter the coefficient and the power of each term(0 0) to stop:";
		cin >> x >> y;
		if (y >= max)max = y;	//Gets the max power as user inputs
		coef.push_back(x);
		power.push_back(y);
	} while ((x != 0) || (y != 0));
	cout << "Enter the value of a:";
	cin >> a;
	printresults();
	system("pause");
}
