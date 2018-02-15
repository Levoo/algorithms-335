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

std::vector <std::string> spatula(std::string); // Yeah, she workin' with the spatula, I know she love flippin' shi -- Drake

int main(){
	std::string uPhrase;   // original phrase that user inputs
	std::vector <std::string> patty; // vector of reversed phrase
	
	std::cout << "Enter a sentence: "; // prompt user
	std::getline(std::cin, uPhrase);
	uPhrase += " "; // add an extra space to end of phrase so its easier to parse
	patty = spatula(uPhrase); 
	std::cout << "\nWords are reversed: ";
	for (int i = 0; i < patty.size(); ++i) // display revered phrase
		std::cout << patty[i] << " ";
	std::cout << "\n";
    return 0;
}


std::vector <std::string> spatula(std::string phrase) { // reverse phrase here 
	std::string temp; // have a temp string to hold the word, that will then be added to a vector w/o space
	std::vector <std::string> temp_list; // temp vector that has everything split by space
	std::vector <std::string> rev_list; // real reversed list
	for (int i = 0; i <= phrase.size(); ++i) { // split the phrase
		if (phrase[i] != ' ') { // if not space then add char to temp until word is complete 
			temp += phrase[i];
		}
		else {
			temp_list.push_back(temp); // once we reach a space put the whole string into the vector 
									   //so we get a vector of strings
			temp.clear();              // clear the string so that it is empty
		}
	}

	int index = temp_list.size() - 1;
	for (int i = index; i >= 0; i--) // flip the phrase
		rev_list.push_back(temp_list[i]); // go backwards and add the words to new list 

	return rev_list;
}
