/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 2, Prime number problem #4
*/

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std; //ewww

bool isPrime(int n) { // determine of number is prime 
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
	map<int, int> freq;
	vector<int> freq_count;
	vector<int> primes;
	int list[15];
	cout << "List: ";
	for (int i = 0; i < 15; ++i) { // generate the list of numbers 
		list[i] = rand() % 21 + 10;
		//if (list[i] > 30) list[i] -= 10;
		cout << list[i] << " ";
	}
	cout << endl << "Primes: "; // get the primes 
	for (int i = 0; i < 15; ++i) {
		if (isPrime(list[i])) {
			cout << list[i] << " ";
			primes.push_back(list[i]);
		}
	}
	std::cout << std::endl;
	int max = 0;
	for (int i = 0; i < (int) primes.size(); i++) { // get prime freq
		freq[primes[i]] += 1;
		if (freq[primes[i]] > max) max = freq[primes[i]];
	}
	for (auto element : freq) { // print the freq of only the highest prime
		if (element.second == max)
			cout << "Freq of " << element.first << ": " << element.second << endl;
	}

	system("pause");  // why? jk i get it 
}
