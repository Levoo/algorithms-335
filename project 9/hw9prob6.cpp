/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 9, problem #9
*/
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std; //no comment

int main() {
	srand(time(NULL));
	int n;
	int** arry;
	cout << "Enter the array size (n value) of a two dimensional array:";
	cin >> n;

	//make 2d dynamic array
	arry = new int*[n];
	for (int i = 0; i < n; ++i) {
		arry[i] = new int[n];
	}
	cout << "This is the original array:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//Random number
			arry[i][j] = rand() % 30 + 1;
			cout << setw(4) << arry[i][j];
		}
		cout << endl;
	}
	cout << "This is the data in a spiral order" << endl;
	//First row
	for (int i = 0; i < n; ++i) {
		cout << setw(3) << arry[0][i];
	}
	//Last col
	for (int i = 1; i < n; ++i) {
		cout << setw(3) << arry[i][n - 1];
	}
	//Bottom row
	for (int i = n - 2; i >= 0; --i) {
		cout << setw(3) << arry[n - 1][i];
	}
	//First col
	for (int i = n - 2; i > 0; --i) {
		cout << setw(3) << arry[i][0];
	}
	//middle for 3 and top middle for 4
	for (int i = 1; i < n - 1; ++i) {
		cout << setw(3) << arry[1][i];
	}
	//remaining middle of arry 4x4
	if(n==4){
		for (int i = n-2; i > 0; --i) {
			cout << setw(3) << arry[2][i];
		}
	}
	cout << endl;
	
	system("pause");
}