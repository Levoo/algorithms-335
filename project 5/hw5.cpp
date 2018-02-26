/* INFO */

#include <iostream>
#include <string>
using namespace std; //lel

struct treeNode {
	std::string name;
	treeNode* left, * right;
};

struct queueNode {
	std::string name;
	queueNode* next;
};

class bst {
public:
	treeNode* bt_head;
	bst() { bt_head = nullptr; }
	treeNode* getHead() { return bt_head; }

	void insert(treeNode* bt, std::string newVal) {
		if (bt == nullptr) {
			bt = new treeNode;
			bt->name = newVal;
			bt->left = nullptr;
			bt->right = nullptr;
		}
		else { // insert alphabetiaclly????
			if (newVal <= bt->name) insert(bt->left, newVal);
			if (newVal >= bt->name)  insert(bt->right, newVal);
		}
	}
	void preorder(treeNode* bt) {
		if (bt) {
			std::cout << bt->name << " -> ";
			preorder(bt->left);
			preorder(bt->right);
		}
	}
};

int main(){
	bst tree;
	treeNode* root = tree.getHead();
	std::string months[12] = { "Jan", "Feb", "Mar" , "Apr" , 
							   "May" , "Jun" , "Jul" , "Aug" , 
							   "Sep" , "Oct" , "Nov" , "Dec" };
	for (int i = 0; i < 12; i++) {
		tree.insert(root, months[i]);
	}

	tree.preorder(root);

    return 0;
}

