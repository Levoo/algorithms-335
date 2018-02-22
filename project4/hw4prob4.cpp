#include<iostream>
using namespace std;

struct node{	//node for the list
	int data = -1;
	node *next = nullptr;
};
class list{	//the list
public:
	bool empty = false;
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
		empty = true;
		for (int i = 0; i < 7; ++i) {	//I use 7 to mimic stack size
			if (temp->data != 0) {
				empty = false;
			}
			cout << temp->data;
			temp = temp->next;
			cout << "->";
		}
		cout  <<"NULL" << endl;
	}
	void processedcheese() {	//Its a gouda function
		node *temp = head;
		for (int i = 0; i < 7; ++i) {	//I use 7 to mimic stack size
			temp->data -= 3;	// This is the amount processed per pass
			if (temp->data < 0) {	//makes sure the value doesnt go below 0
				temp->data = 0;
			}
			temp = temp->next;	//advances through the list
		}
	}
};

int main() {
	int arry[7] = { 5,6,4,8,2,7,6 };	//int array for stack
	int i = 1;
	list que;	//so
	for (int i = 0; i < 7; ++i) {	
		que.push(arry[i]);	//initializes the list with the given array
	}
	cout << "Start:  ";
	que.print();	//initial order print

	while (que.empty == false) {
		cout << "Round " << i << ": ";
		que.processedcheese(); //A function that mimics processing on the queue
		que.print();
		++i;
	}
	cout << "Round " << i << ": NULL" << endl;
	system("pause");
}