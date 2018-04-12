#include <iostream>
#include <ctime>
#include <random>
using namespace std; //mario?

int main() {
	int end = 9;
	//int a[10] = {25, 10, 22, 8, 17, 10, 13, 11, 6, 28};  // test
	int a[10];
	std::cout << "The origanal array is:\n\t";
	std::srand(time(0)); // seed so we get random number every time we call
	for (int i = 0; i < 10; i++) { // gen and store the rand numbers 
		a[i] = std::rand() % 30 + 1;
		std::cout << a[i] << " ";
	}
	std::cout << "\nThis is the array after a rearangment";
	for (int i = 0; i < 10; i++) { // go through array from begining 
		if (a[i] % 2 == 0 && a[i] != 0) { // if even then look for odd to swap with 
			for (int j = i; j < 10; j++) { // j = i so we linear search increase
				if ((a[j] % 2 == 1) && a[j] != 0) { // once odd is found swap
					int tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
					break;
				}
			}
		}
	}

	std::cout << "\n\t";
	for (auto x : a) { // print 
		std::cout << x << " ";
	}
	std::cout << "\n";
	return 0;
}
