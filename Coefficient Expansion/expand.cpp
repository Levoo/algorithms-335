#include <iostream>
#include <vector>
#include <cmath> // take off 
#define NTH_LIMIT 7

int factorial(int num);
int expandDong(int n, int k);

int main() {
	int nth = 0; //set up nth and k for expand dong 
	std::cout << "Enter the nth value: ";
	std::cin >> nth;
	while (nth > NTH_LIMIT) { // error checking 
		std::cout << "\nInvalid nth value, must be <= 7\n";
		std::cout << "Enter the nth value: ";
		std::cin >> nth;
	}
	int k = 0;
	std::vector<int> coef_list; //vector of leading coefficients 
	for (int i = 0; i <= nth; i++) {
		coef_list.push_back(expandDong(nth, i)); // call expand to get the stuff
	}
	for (int i = 0; i < (int) coef_list.size(); i++) { // print out results 
		std::cout << coef_list[i] << " , ";
	}

	return 0;
}

int expandDong(int n, int k) { tried to do recursive but ehh :/ 
	return (factorial(n) / (factorial(k) * factorial(n - k)));
}

int factorial(int num) {  //factorial of n, recursive
	if (num > 1) return num * factorial(num - 1);
	else return 1;
}
