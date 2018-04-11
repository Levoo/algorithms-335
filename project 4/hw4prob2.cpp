/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 4, problem #2
*/
#include<iostream>
#include <algorithm>
using namespace std;

struct node{	//node for the list
	int data = -1;
	node *next = nullptr;
};
class list{	//the list
public:
	int size = 0;
	node *head;	//pointer to head element in list
	list(){	//initialize the list empty
		head = nullptr;
	}
	void addnode(int value){	//adds on back to preserve order
		node *temp = new node;
		node *mover = head;
		temp->data = value;
		if (head == nullptr){
			head = temp;
			temp = nullptr;
		}
		else {
			while (mover->next != nullptr) {
				mover = mover->next;
			}
			mover->next = temp;
		}
		size++;
	}
	void print() {	//prints the list
		node *temp = head;
		for (int i = 0; i < size; ++i) {
			cout << temp->data;
			temp = temp->next;
			cout << "->";
		}
		cout  <<"NULL" << endl;
	}
};

int main() {
	int arry1[5] = { 90, 45, 29, 68, 17};
	int arry2[4] = { 89, 90, 17, 29 };
	list set1,set2,inter,minus;
	sort(arry1,	arry1 + 5);	//orders arry1
	sort(arry2, arry2 + 4);	//orders arry2
	for (int i = 0; i < 5;++i) { set1.addnode(arry1[i]);}//populates set1 with ordered arry1
	for (int i = 0; i < 4;++i) { set2.addnode(arry2[i]);}//populates set2 with ordered arry2
	//vvFORMATINGvv
	cout << "setA->";
	set1.print();
	cout << "setB->";
	set2.print();
	//Function that finds common elements and inserts into new list
	//acts like a nested for loop for the lists 
	node* tmp = set1.head;
	while (tmp != nullptr) {
		node* tmp2 = set2.head;
		while (tmp2 != nullptr) {
			if (tmp->data == tmp2->data) {
				inter.addnode(tmp->data);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	//vvFORMATINGvv
	cout << "setA|B->";
	inter.print();
	//Function that finds set1 - set2
	//acts like a nested for loop for the lists 
	tmp = set1.head;
	bool found = false;
	while (tmp != nullptr) {
		node* tmp2 = set2.head;
		while (tmp2 != nullptr) {
			if (tmp->data == tmp2->data) {
				found = true;
			}
			tmp2 = tmp2->next;
		}
		if (found == false) {
			minus.addnode(tmp->data);
		}
		found = false;
		tmp = tmp->next;
	}
	//vvFORMATINGvv
	cout << "setAMB->";
	minus.print();

	system("pause");
}
