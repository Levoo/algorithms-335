#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

bool isPrime(int n) {
	bool prime = true;
	for (int i = 2; i < n; ++i) {
		if (n%i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int main() {
	srand(time(NULL));
	vector<int> primes;
	int list[10];
	cout << "List: ";
	for (int i = 0; i < 10; ++i) {
		list[i] = rand() % 30 + 10;
		if (list[i] > 30) list[i] -= 10;
		cout << list[i] << " ";
	}
	cout << endl << "Primes: ";
	for (int i = 0; i < 10; ++i) {
		if (isPrime(list[i])) {
			cout << list[i] << " ";
			primes.push_back(list[i]);
		}
	}
	


	system("pause");
}