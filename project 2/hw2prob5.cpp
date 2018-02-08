/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 2, Fibonachi problem #5
*/

#include <iostream>
#include <vector>

#define NTH_TERM_ROW 0
#define NTH_TERM_COL 1

std::vector<std::vector<int>> multiMatrix(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B);

int main() {
	int limit = 0;
	std::vector<std::vector<int>> fib  = { {0, 1}, {1, 1} };
	std::vector<std::vector<int>> nth = fib;

	
	std::cout << "What nth value of Fib would you like? ";
	std::cin >> limit;

	for (int i = 0; i < limit - 1 ; i++) // calculate the code
		nth = multiMatrix(fib, nth);
	std::cout << "---\n";
	std::cout << "Fibonacci matrix: \n";
	for (int i = 0; i < 2; i++) { // display
		for (int j = 0; j < 2; j++) {
			std::cout << nth[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << "F(" << limit << ") = " << nth[NTH_TERM_ROW][NTH_TERM_COL] << std::endl;
	
	return 0;
}

std::vector<std::vector<int>> multiMatrix(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
	std::vector<std::vector<int>> C = A;
		for (int i = 0; i < 2; ++i) { // multiply matracies 
			for (int j = 0; j < 2; ++j) {
				C[i][j] = 0;
				for (int k = 0; k < 2; ++k) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	/*	for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				std::cout << C[i][j] << " ";
			}
		}
		*/ // debug code
	return C;
}
