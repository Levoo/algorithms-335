#include <iostream>
#include <string>
#include <list>
#include <algorithm>

void printList(std::string, std::list<int>);
void createSet(std::list<int> & set_a, std::list<int> & set_b);
void setUnion(std::list<int>  set_a, std::list<int>  set_b, std::list<int>&);
void setDiff(std::list<int>  set_a, std::list<int>  set_b, std::list<int>&);

int main() {
	std::list<int> lls_a;
	std::list<int> lls_b;
	std::list<int> list_union;
	std::list<int> list_diff;

	createSet(lls_a, lls_b);
	printList("setA -> ", lls_a);
	printList("setB -> ", lls_b);
	setUnion(lls_a, lls_b, list_union);
	printList("set A|B -> ", list_union);
	setDiff(lls_a, lls_b, list_diff);
	printList("set A-B -> ", list_diff);
	
	return 0;
}

void createSet(std::list<int> & set_a, std::list<int> & set_b) {
	int prepA[5] = { 90, 45, 29, 68, 17 };
	int prepB[4] = { 89, 90, 17,29 };
	std::sort(prepA, prepA + 5);
	std::sort(prepB, prepB + 4);
	for (int i = 0; i < (sizeof(prepA)/sizeof(*prepA)); i++)
		set_a.push_back(prepA[i]);
	
	for (int i = 0; i < (sizeof(prepB) / sizeof(*prepB)); i++)
		set_b.push_back(prepB[i]);
}

void setUnion(std::list<int>  set_a, std::list<int>  set_b, std::list<int>& uni) {
	std::list<int>::iterator  a_iter = set_a.begin(), b_iter = set_b.begin();
	while (a_iter != set_a.end()) {
		while (b_iter != set_b.end()) {
			if (*a_iter == *b_iter) {
				uni.push_back(*a_iter);
			}
			++b_iter;
		}
		++a_iter;
		b_iter = set_b.begin();
	}
	
}

void setDiff(std::list<int>  set_a, std::list<int>  set_b, std::list<int>& diff) {
	std::list<int>::iterator  a_iter = set_a.begin(), b_iter = set_b.begin();
	bool unique = true;
	while (a_iter != set_a.end()) {
		while (b_iter != set_b.end()) {
			if (*a_iter == *b_iter) {
				unique = false;
			}
			++b_iter;
		}
		if (unique) {
			diff.push_back(*a_iter);
		}
		unique = true;
		++a_iter;
		b_iter = set_b.begin();
	}
}

void printList(std::string msg, std::list<int> ll) {
	std::cout << "\n\t" << msg;
	for (auto it = ll.begin(); it != ll.end(); ++it) {
		std::cout << *it << " -> ";
	}
	std::cout << "NULL" << std::endl;
}
