#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	map<int, int> freq;
	vector<int> primes;
	int list[10];
	cout << "List: ";
	for (int i = 0; i < 10; ++i) {
		list[i] = rand() % 30 + 10;
		if (list[i] > 30) list[i] -= 10;
		cout << list[i] << " ";
	}
	cout << endl << "Primes: "; // got a case where if lets say 23 comes out twice, it will display 23 twice, should we fix?
	for (int i = 0; i < 10; ++i) {
		if (isPrime(list[i])) {
			cout << list[i] << " ";
			primes.push_back(list[i]);
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < 10; i++) { // add to map
		freq[list[i]] += 1;
	}
	for (auto element : freq) { // range based for loop, basiclly take each element in the map and use it should be O(n) still
						  // since you can also do auto i = map.begin(); i < size of map; ++
		if(isPrime(element.first)) // only print frequency if prime a sper part c of question 4
			cout << "Freq of " << element.first << " is " << element.second << endl; // access the unique key and the value 
																				 // currently have it display all idk if you wanna display everything above 1
																				 // or if alll occur once, display all of them 
	}

	system("pause");  // why? jk i get it 
}
