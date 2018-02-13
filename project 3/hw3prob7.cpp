///*
//	Author: Cuevas Fernando
//	        Rodriguez Michael
//	Class: Algorithms - 335, TUE/THUR
//	Program: Question 5 Brute force phrase flip
//	Assignment: 3
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//
//std::vector <std::string> spatula(std::string); // Yeah, she workin' with the spatula, I know she love flippin' shit -- Drake
//
//int main(){
//	std::string uPhrase;   // original phrase that user inputs
//	std::vector <std::string> patty; // vector of reversed phrase
//	
//	std::cout << "Enter a sentence: "; // prompt user
//	std::getline(std::cin, uPhrase);
//	uPhrase += " "; // add an extra space to end of phrase so its easier to parse
//	patty = spatula(uPhrase); 
//	std::cout << "\nWords are reversed: ";
//	for (int i = 0; i < patty.size(); ++i) // display revered phrase
//		std::cout << patty[i] << " ";
//	std::cout << "\n";
//    return 0;
//}
//
//
//std::vector <std::string> spatula(std::string phrase) { // reverse phrase here 
//	std::string temp; // have a temp string to hold the word, that will then be added to a vector w/o space
//	std::vector <std::string> temp_list; // temp vector that has everything split by space
//	std::vector <std::string> rev_list; // real reversed list
//	for (int i = 0; i <= phrase.size(); ++i) { // split the phrase
//		if (phrase[i] != ' ') { // if not space then add char to temp until word is complete 
//			temp += phrase[i];
//		}
//		else {
//			temp_list.push_back(temp); // once we reach a space put the whole string into the vector 
//									   //so we get a vector of strings
//			temp.clear();              // clear the string so that it is empty
//		}
//	}
//
//	int index = temp_list.size() - 1;
//	for (int i = index; i >= 0; i--) // flip the phrase
//		rev_list.push_back(temp_list[i]); // go backwards and add the words to new list 
//
//	return rev_list;
//}


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

