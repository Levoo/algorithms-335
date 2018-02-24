/*
	Author: Fernando
	Class: 
*/
#include <iostream>
#include <string>

struct node {
	int data;
	node *next = nullptr;
};

class linked_list {
public:
	int listSize = 0;
	node * list_head;
	linked_list() {
		list_head = nullptr;
	}

	void addData(int newValue){
		node* tmp = new node;  // create tmp node and use that to add to head
		tmp->data = newValue;
		if (list_head == nullptr) { // if head is equal to null add to head
			list_head = tmp;
			tmp = nullptr;
		}
		else {
			node* track = list_head; //else add to list
			while (track->next != nullptr) {
				track = track->next;
			}
			track->next = tmp;
		}
		listSize++;
	}

	void displayList(std::string msg){
		std::cout << "\t" << msg;
		node * traceList = list_head;
		for (int i = 0; i < listSize; i++) {
			std::cout << traceList->data << " ";
			traceList = traceList->next;
		}
		std::cout << " NULL" <<std::endl;
	}

	node * getHead() { return list_head; }
	
	void mergeSort(){
	    node * start = list_head;
		linked_list half1; //and
		linked_list half2;
		if (list_head == nullptr || listSize == 1) return;
		else 
			moses(start, half1, half2);

		sortList(half1); // sort each list
		sortList(half2);

		list_head = mergeList(half1.getHead(), half2.getHead()); // have head point to new list

	}

	//merge the two lists
	node * mergeList(node * h1, node * h2){
		node* ml = nullptr;
		if (h1 == nullptr) return h2;
		else if (h2 == nullptr) return h1;

		if (h1->data <= h2->data) {
			ml = h1;
			ml->next = mergeList(h1->next, h2);
		}
		else if (h2->data <= h1->data) {
			ml = h2;
			ml->next = mergeList(h2->next, h1);
		}
		return ml;
	}

	// sort a list
	void sortList(linked_list llist) {
		int tmp;
		node * ptr1, *ptr2, *track = nullptr;
		ptr1 = llist.getHead();
		ptr2 = llist.getHead();
		ptr2 = ptr2->next;
		while (ptr1 != nullptr) {
			track = ptr1;
			while (ptr2 != nullptr) {
				if (ptr2->data < track->data){
					track = ptr2;
				}
				ptr2 = ptr2->next;
			}
			tmp = ptr1->data;
			ptr1->data = track->data;
			track->data = tmp;
			
			ptr1 = ptr1->next;
			if(ptr1 != nullptr)
				ptr2 = ptr1->next;
		}
	}

	// split a list in half
	void moses(node* start, linked_list &a, linked_list &b) {
		int firstHalf = listSize / 2; // if even then will get half
									  // else since the value is int will
									  // get implicitly convereted to int
									  // so if odd 5 / 2  = 2.5 -> 2

		for (int i = 0; i < firstHalf; i++) { // 1st half 
			a.addData(start->data);
			start = start->next;
		}
		for (int i = firstHalf; i < listSize; i++) { // 2nd half
			b.addData(start->data);
			start = start->next;
		}
	}
};


int main(){
	linked_list ll, sortedList;
	ll.addData(23);
	ll.addData(18);
	ll.addData(99);
	ll.addData(7);
	ll.addData(30);
	ll.addData(5);
	ll.addData(20);

	ll.displayList("This is the original list: ");
	ll.mergeSort();
	ll.displayList("New? ");


    return 0;
}

