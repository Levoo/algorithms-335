
/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 4, problem #1
*/
#include <iostream>
#include <string>
#include <list>

void printList(std::string, std::list<int>);
void insertionSort(std::list<int>&);

int main() {
	int temp;
	std::list<int> ll_int;
	std::list<int> sorted_ll_int;
	std::cout << "Enter some positive integer numbers with -1 at the end: "; // 89 45 68 90 29 34 17 -1
	while (std::cin >> temp) {
		if (temp == -1) break;
		ll_int.push_back(temp);
	}

	printList("Original linked list: ", ll_int);
	insertionSort(ll_int);
	printList("Sorted linked list: ", ll_int);
	return 0;
}

void insertionSort(std::list<int> & ll) { 
	int tmp;
	std::list<int>::iterator new_min, min; //for loops that iterate over list
	for (std::list<int>::iterator i = ll.begin(); i != ll.end(); ) {
			min = i;		// assumer the first value of list is lowest
			new_min = i;    // new min will have the new min if it finds it later on in the list
		for (std::list<int>::iterator j = ++i; j != ll.end(); ++j) {
			if (*j < *new_min) {
				new_min = j;
			}
		}
		tmp = *min; // simple swap
		*min = *new_min;
		*new_min = tmp;
	}

}

void printList(std::string msg, std::list<int> ll) {
	std::cout << "\n\t" << msg;
	for (auto it = ll.begin(); it != ll.end(); ++it) {
		std::cout << *it << " -> ";
	}
	std::cout << "NULL" << std::endl;
}
