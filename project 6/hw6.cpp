/* stuff */
#include <iostream>
#include <string>
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
	node *  root = nullptr;
	node2 * root2;
	int key = 3; // for bt
	/*
		have root be weight 3
		have node 2 be weight 2, node 5 be weight 1
		have node 9 be weight 4, this will give us bt tree
	*/
	// make this function into a templete function for reuse on question 2, or make seprate insert function for number 1

	void btInsert(node* bt, int newVal) {
		if (root == nullptr) {//initializes head of bst
			root = new node;
			root = newNode(newVal);
			return;
		}
		else { 
			if (newVal <= bt->data) {
				if (bt->left == nullptr) { //checks if there is no val in next node
					//populates and links if none
					bt->left = newNode(newVal);
				}
				else { btInsert(bt->left, newVal); }//traverse if a node exists
			}
			else {
				if (bt->right == nullptr) { //checks if there is no val in next node
					//populates and links if none
					bt->right = newNode(newVal);
				}
				else { btInsert(bt->right, newVal); }//traverse if a node exists
			}
		}
	}
	
	node* newNode(int newVal) {
		node*  tmp = new node;
		tmp->data = newVal;
		tmp->left = nullptr;
		tmp->right = nullptr;
		return tmp;
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

int main(){
	binaryTree bt, bst;
	bt.btInsert(bt.root, 5);
	bt.btInsert(bt.root, 4);
	bt.btInsert(bt.root, 25);
	bt.preorder(bt.root);

	
	system("pause"); // micheal scott
}

