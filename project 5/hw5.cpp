/* INFO */

#include <iostream>
#include <string>
using namespace std; //lel

struct treeNode {
	std::string name;
	treeNode* left = nullptr, *right = nullptr;
};

struct queueNode {
	std::string name;
	queueNode* next;
};

class bst {
public:
	treeNode* bt_head = nullptr;
	bst() { bt_head = nullptr; }
	treeNode* getHead() { return bt_head; }

	void insert(treeNode* bt ,std::string newVal) {
		if (bt_head == nullptr) {//initializes head of bst
			bt_head = new treeNode;
			bt_head->name = newVal;
			return;
		}
		else { // insert alphabetiaclly????
			if (newVal <= bt->name) { 
				if (bt->left == nullptr) { //checks if there is no val in next node
					treeNode *tmp = new treeNode;//populates and links if none
					tmp->name = newVal;
					bt->left = tmp;
					tmp = nullptr;
				}
				else{ insert(bt->left, newVal);}//traverse if a node exists
			}
			if (newVal > bt->name) {
				if (bt->right == nullptr) { //checks if there is no val in next node
					treeNode *tmp = new treeNode;//populates and links if none
					tmp->name = newVal;
					bt->right = tmp;
					tmp = nullptr;
				}
				else{ insert(bt->right, newVal);}//traverse if a node exists
			}
		}
	}
	void preorder(treeNode* bt) {
		if (bt != nullptr) {
			std::cout << bt->name << " -> ";
			preorder(bt->left);
			preorder(bt->right);
		}
	}
};

int main() {
	bst tree;
	treeNode* root = tree.getHead();
	std::string months[12] = { "Jan", "Feb", "Mar" , "Apr" ,
		"May" , "Jun" , "Jul" , "Aug" ,
		"Sep" , "Oct" , "Nov" , "Dec" };
	for (int i = 0; i < 12; i++) {
		tree.insert(tree.bt_head,months[i]);
	}

	tree.preorder(tree.bt_head);

	system("pause");
}
