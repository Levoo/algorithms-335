/*
	Author: Cuevas Fernando
	        Rodriguez Michael
	Class: Algorithms - 335, TUE/THUR
	Program: Question 7 Remove adjacent chars
	Assignment: 3
*/

#include <iostream>
#include <string>
#include <vector>

void mrClean(std::string); // Mr. Clean is a brand name and mascot fully owned by Procter & Gamble, 
						   // used as an all-purpose cleaner and melamine foam cleaner --More at Wikipedia 

int main() {
	std::string uWord;
	std::cout << "Enter a string: ";
	std::cin >> uWord;

	mrClean(uWord);

	return 0;
}

void mrClean(std::string str) {
	std::string temp;
	std::vector <std::string> steps;
	steps.push_back(str); // push in the og word
	int limit;
	bool clean = false;
	while (!clean) { // keep checkeing string until all adjacent stuff is removed
		limit = str.size(); // limit chanages as string gets smaller 
		clean = true; // assume this run of while loop will be the last once since we are assuming it has been cleaned 
		for (int i = 0; i < limit; i++) { // loop through string
			if (str[i] != str[i + 1]) { // if position i and i + 1 are not equal then add position i to new string 
				temp += str[i];
			}else if(str[i] == str[i + 1]){ // if they are equal skip i and i + 1, by addin another 1 to i
				clean = false;              // let the while loop know we need to go agaian
				i += 1;
			}
		}
		str = temp; // set the string equal to temp
		steps.push_back(str); // push the state of the string to the vector so we have a list of steps 
		temp.clear(); // clear the temp so we can start again if need be 
		if (str.size() == 2 && str[0] != str[1]) break; // added this b/c my algorithm will check one more time 
														// in the case of MISSISSIPPE, it will get to MI after one run and then run one more time with MI
														// so we check to stop that
	}
	std::cout << "After removing all same adjacent characters: ";
	for (int i = 0; i < steps.size(); ++i) { // display steps 
		std::cout << steps[i];
		if(i != steps.size() - 1) std::cout << " -> "; // only display the arrow until we reach the last step
	}
	std::cout << std::endl;
}

