/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 2, Airline problem #6
*/
#include<iostream>
#include<vector>
//Size of the array
#define SIZE 5
//Positions in the 2d array
#define LAX 1
#define PHX 4
using namespace std;

//Multiplies a set by a set and returns the result
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C = A;
	for (int i = 0; i < SIZE;++i) {
		for (int j = 0; j < SIZE; ++j) {
			C[i][j] = 0;
			for (int k = 0; k < SIZE; ++k) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

int main() {
	//Creates an adjacency matrix of flight paths in a 2d vector array of ints
	vector<vector <int>> matrix = { {0,0,0,1,0},{1,0,1,1,1},{0,1,0,0,1},{1,0,1,0,1},{0,0,1,1,0} };
	vector<vector<int>> matrix2 = matrix;
	matrix2 = multiply(matrix, matrix2);	//A*A	matrix2 = A^2
	matrix = multiply(matrix, matrix2);		//A*A^2	matrix = A^3
	matrix = multiply(matrix, matrix2);		//A^3*A^2 matrix = A^5
	cout << "Number of flight paths <=5 from LAX to PHX is:" << matrix[LAX][PHX] << endl; // output num of paths
	system("pause");
}
