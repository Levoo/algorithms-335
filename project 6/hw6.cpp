/* stuff */
#include <iostream>
#include <string>
#include<iomanip>
using namespace std; // for the boi


struct node {
	int weight; // for use to automate the bt creation
	int data;
	node * left, *right;
};
struct node2 {
	string data;
	node * left, *right;
};

class binaryTree {
public:
	node * root = nullptr;
	node * root2 = nullptr;
	
	void createBT() { // man impleementation of bt found on paper
		btInsert(root, 1, 4);
		btInsert(root, 9, 5);
		btInsert(root, 0, 6);
		btInsert(root, 2, 2);
		btInsert(root, 5, 1);
		btInsert(root, 0, 3);
	}

	void btInsert(node* bt, int newVal, int weight) {
		if (root == nullptr) {//initializes head of bst
			root = new node;
			root = newNode(newVal, weight);
			return;
		}
		else {
			if (weight <= bt->weight) {
				if (bt->left == nullptr) { //checks if there is no val in next node
										   //populates and links if none
					bt->left = newNode(newVal, weight);
				}
				else { btInsert(bt->left, newVal, weight); }//traverse if a node exists
			}
			else {
				if (bt->right == nullptr) { //checks if there is no val in next node
											//populates and links if none
					bt->right = newNode(newVal, weight);
				}
				else { btInsert(bt->right, newVal, weight); }//traverse if a node exists
			}
		}
	}
	//helper function for insert, mass is a flag variable so that we can reuse the newnode function for q2
	node* newNode(int newVal, int mass) {
		node*  tmp = new node;
		tmp->data = newVal;

		tmp->weight = mass;
		tmp->left = nullptr;
		tmp->right = nullptr;
		return tmp;
	}

	bool isBST(node* bt) {
		if (bt == nullptr) return true;
		if(bt->left != nullptr){ // 3 cases if bothL and R have value if only L has value if R has value only if only root has value
			if(bt->right != nullptr){
				if (bt->left->data <= bt->data <= bt->right->data) {
					 isBST(bt->left);
					 isBST(bt->right);
				}
			}
		}
		

		return false;
	}
	
	int maxNode(node* bt, int max) {
		if (bt == nullptr) return max; //return once you have the largest one

		if (max <= bt->data) max = bt->data; // if greater change
		maxNode(bt->left, max); // else check left and right subtrees for max
		maxNode(bt->right, max);

	}

	void dipside(node *bt, int sp) {//part c
		if (bt != nullptr) {
			dipside(bt->right, sp += 5);
			cout << setw(sp) << bt->data << endl;
			dipside(bt->left, sp);
		}
	}

	template<typename t2> // be able to call this with both int and string 
	void preorder(t2* bt) {
		if (bt != nullptr) {
			std::cout << bt->data << " ";//dont display bst as list
			preorder(bt->left);
			preorder(bt->right);
		}
	}
};

int main() {
	binaryTree bt, bst;
	//bt.createBT();
	//bst.createBT();
	bt.btInsert(bt.root, 5, 5);
	bt.btInsert(bt.root, 4, 4);
	bt.btInsert(bt.root, 3, 3);
	bt.btInsert(bt.root, 6, 6);
	bt.btInsert(bt.root, 7, 7);
	bt.preorder(bt.root);
	cout << "\n";
	cout << bt.maxNode(bt.root, 0) << endl;
	cout << "\n";
	bst.dipside(bst.root, 0);
	bool isIt = bst.isBST(bst.root);
	cout << isIt << endl;
	system("pause"); // micheal scott
}
