/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 4, problem #3
*/
#include<iostream>
using namespace std;

struct node{	//node for the list
	int data = -1;
	node *next = nullptr;
};
class list{	//the list
public:
	node *head;	//pointer to head (top) element in list
	list(){	//initialize the list empty
		head = nullptr;
	}
	void push(int value){	//uses push to mimic a stack
		node *temp = new node;
		node *hold = head;

		temp->data = value;
		if (head == nullptr){
			head = temp;
			temp = nullptr;
		}
		else{
			temp->next = head;
			head = temp;
			temp = nullptr;
		}
	}
	void print() {	//prints the list(stack)
		node *temp = head;
		for (int i = 0; i < 7; ++i) {	//I use 7 to mimic stack size
			cout << temp->data;
			temp = temp->next;
			if (temp == nullptr) {
				break;
			}
			cout << "->";
		}
		cout  << endl;
	}

	//A function to reverse the linked list in pairs
	void switcharoo() {
		node* one, *two, temp1;
		one = head;	//initializes to 1st element in stack
		two = head->next;	//initializes to 2nd element in stack
		for (int i = 0; i < 3; ++i) {	//I use 3 here to mimic half the stack size rounded down
			temp1 = *two;	//creates a copy of two to retain the value
			two->data = one->data;	//Basic swapping of data
			one->data = temp1.data;	//cont
			one = one->next->next;	//moves pointer forward 2 spots in the array
			two = two->next->next;	// ^^^^^
		}
	}
};

int main() {
	int arry[7] = { 89,45,68,90,2,34,17 };	//int array for stack
	list stak;
	for (int i = 0; i < 7; ++i) {	
		stak.push(arry[i]);	//initializes the stack with the given array
	}
	stak.print();	//initial order print
	stak.switcharoo(); //A function to reverse the linked list in pairs
	stak.print();	//rearranged print
	system("pause");
}
