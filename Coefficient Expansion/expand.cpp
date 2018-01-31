/*
	Authors: Micheal Woodworth
			 Fernando Cuevas
	Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
	Project: Assignment 1, Coefficient expansion  for nth power (n <= 7)
*/

#include <iostream>
#include <vector>
#define NTH_LIMIT 7

int factorial(int num);
int expandDong(int n, int k);

int main() {
	int nth = 0; //set up and ask for input
	int SIZE = 0;
	std::cout << "Enter the nth value: ";
	std::cin >> nth;
	while (nth > NTH_LIMIT) { // error checking 
		std::cout << "\nInvalid nth value, must be <= 7\n";
		std::cout << "Enter the nth value: ";
		std::cin >> nth;
	}

	std::vector<int> coef_list; //vector of leading coefficients 
	for (int i = 0; i <= nth; i++) {
		coef_list.push_back(expandDong(nth, i)); // call expand to get coefficient and then add to vector
	}
	SIZE = (int)coef_list.size(); // store size of vector
	for (int i = 0; i < SIZE; i++) { // print out results 
		std::cout << coef_list[i] << "a^" << nth << "*" << "b^" << i;
		if (i != SIZE - 1) std::cout << " + "; // check to make sure we dont print a + at the very end...
		nth -= 1;
	}
	std::cout << std::endl; // add a new line for design 
	return 0;
}

int expandDong(int n, int k) { // called once ebry time in first for loop
		return (factorial(n) / (factorial(k) * factorial(n - k))); // return the C(n, k) for nth/k value
}

int factorial(int num) {  //factorial of n, recursive
	if (num > 1) return num * factorial(num - 1); // while > 1 keep multi until we reach 1
	else return 1;
}
