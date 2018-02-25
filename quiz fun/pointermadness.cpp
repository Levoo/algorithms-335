#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define SIZE 7

//________________NODE and LIST________________
struct node {
	int data;
	node *next = nullptr;
};
class list {
private:
	int size = 0;
public:
	node *head = nullptr;
	void push(int n) {	//basic push function
		node* tmp = new node;
		tmp->data = n;
		if (head == nullptr) {
			head = tmp;
		}
		else {
			tmp->next = head;
			head = tmp;
		}
		tmp = nullptr;
		size++;
	}
	void printstak() {	//basic print function
		node *tmp = head;
		for (int i = 0; i < size; ++i) {
			cout << tmp->data << "->";
			tmp = tmp->next;
		}
		tmp = nullptr;
		cout << "NULL" << endl;
	}
};//________________       END      ________________

void split(node* head, node **n1, node **n2) {	//splits the list given in half
	node* slow = head;
	node* fast = head->next;

	while (fast != nullptr) {//stops when end of list is found
		fast = fast->next;	//moves forward pointer ahead
		if (fast != nullptr) {	//if fast exists advance both pointers
			slow = slow->next;	
			fast = fast->next;
		}
	}
	*n1 = head; // n1 will be the first half of the list given
	*n2 = slow->next; // n2 will be middle node rounded up (second half of list given)
	slow->next = nullptr;	//no dangles
}

node* merge(node* n1, node* n2) {	//merges two sorted *lists* (will just be two elements until end)
	node* mergedlist = nullptr;

	if (n1 == nullptr) { return n2;}	//stops the recursion further down
	else if (n2 == nullptr) { return n1;}

	if (n1->data <= n2->data) {
		mergedlist = n1;
		mergedlist->next = merge(n1->next, n2);
	}
	else {
		mergedlist = n2;
		mergedlist->next = merge(n1, n2->next);
	}
	return mergedlist;
}

void mergesort(node **source) {
	node* head = *source;
	node* n1 = nullptr; 
	node* n2 = nullptr;

	//stops the splitting process
	if (head == nullptr || head->next == nullptr) {return; }
	split(head, &n1, &n2);//splits the list into 2 parts n1 and n2
	mergesort(&n1);		//sorts the first part (n1) into another half 
	mergesort(&n2);		//sorts the second part (n2) into another half 
	*source = merge(n1, n2);	//merges the two sorted halfs to create one sorted list
}

int main() {
	srand(time(NULL));
	list stak;
	//populates the stack
	for (int i = 0; i < SIZE; ++i) { stak.push(rand() % 100);}
	stak.printstak();	
	mergesort(&stak.head);
	stak.printstak();
	system("pause");
}

