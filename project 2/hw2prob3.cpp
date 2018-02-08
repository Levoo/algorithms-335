#include <iostream>
#include <vector>
using namespace std;

vector<int> coef;
vector<int> power;
int a, x, y, max = 0, total = 0;


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
	total =coef[0]* a;
	for (int i = 1;i<=max; ++i) {
		
		total = (a * total) + coef[i];
		cout << ">> RUN: " << i << endl;
		cout << "Total: " << total << endl;
		cout << "a: " << a << endl;
		cout << "coef: " << coef[i] << endl;
	}
	cout << "f(a) = " << total;


	system("pause");
}
