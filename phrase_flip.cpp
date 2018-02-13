/*
	Author: Cuevas Fernando
	        Rodriguez Michael
	Class: Algorithms - 335, TUE/THUR
	Program: Question 5 Brute force phrase flip
	Assignment: 3
*/
#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> spatula(std::string); // Yeah, she workin' with the spatula, I know she love flippin' shit -- Drake

int main(){
	std::string uPhrase;
	std::vector <std::string> strList;
	
	std::cout << "Enter a sentence: ";
	std::cin >> uPhrase;
	
	strList = spatula(uPhrase);
	

    return 0;
}


std::vector <std::string> spatula(std::string phrase) {
	std::string temp;
	std::vector <std::string> temp_list;
	for (int i = 0; i < phrase.size() - 1; ++i) {
		if (phrase[i] == ' ') {
			temp_list.push_back(temp); // once we reach a space put the whole string into the vector 
			    					   //so we get a vector of strings
			temp.clear();              // clear the string so that it is empty
		}
		temp += phrase[i];
	}
	int index = temp_list.size() - 1;
	for (int i = index; i >= 0; --i) {
		temp_list[index - i] = temp_list[index];
	}

	return temp_list;
}
