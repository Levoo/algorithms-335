
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

int get_index(std::vector<std::string> sentence, std::string key) {
	std::string tmp;
	int location = 0;
	for (int i = 0; i < sentence.size(); i++) {
		std::string word = sentence[i];
		if (key.length() <=word.length()) {
			int limit = word.length() - key.length();
			if (limit == 0) limit = 1; // this case the are same size so just check
			for (int i = 0; i < limit; i++) {
				std::string tword = word.substr(i, key.length());
				//std::cout << "Checking sub word: " << tword << "\n";

				if (tword == key) {
					std::cout << "Found" << "\n";
					return location;
				}
			}
			location += word.length()+1; // if it goes through the whole thing then add to see where its at
		}
	}
	return -1;
}


int main() {
	std::string u_choice = "y";
	std::string sen;
	std::string kword;
	do {
		std::cout << "Enter a sentence: ";
		std::getline(std::cin, sen);
		std::cout << "Enter a word: ";
		std::getline(std::cin, kword);

		std::vector<std::string> result; //split string with sstreem
		std::istringstream iss(sen);
		for (std::string s; iss >> s;)
			result.push_back(s);
		
		std::cout << "\tThe initial index of " << kword << " " << get_index(result, kword) << "\n";

		std::cout << "CONTINUE(y/n)? ";
		std::getline(std::cin,  u_choice);
	} while (u_choice != "n");
}
