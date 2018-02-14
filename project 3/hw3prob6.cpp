#include<iostream>
using namespace std;

void mixer(char word[], int start ,int length) {	//the mixer
	if (start == length) {	//completed string of length 4
		printf(" %c %c %c %c\n", word[0], word[1], word[2], word[3]);
	}	//printf is amazing
	else{
		for (int i = start; i <= length; i++){	//given a start point
			swap((word[start]), (word[i]));	//swaps starting point with other letter
			mixer(word, start + 1, length);	//moves the starting point forward 1 letter and mixes the remaining letters
											//goes until there are no remaining letters to mix then prints
			swap((word[start]), (word[i]));	//backtracks 
		}
	}
}

int main() {
	char word[] = "WORK";	//initial word
	int length = strlen(word); //stores the length of the word
	cout << "This is the list of permuations of word WORK\n"; //displays the intro text
	mixer(word,0,length-1);	//calls the mixer
	system("pause");
}