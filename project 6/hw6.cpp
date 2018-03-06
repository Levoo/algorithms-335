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
	node2 * left, *right;
};

class binaryTree {
public:
	node * root = nullptr; // for binary tree question 1
	node2 * t1 = nullptr; // the rest are for question 2
	node2 * t2 = nullptr;

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
			root = newBTNode(newVal, weight);
			return;
		}
		else {
			if (weight <= bt->weight) {
				if (bt->left == nullptr) { //checks if there is no val in next node
										   //populates and links if none
					bt->left = newBTNode(newVal, weight);
				}
				else { btInsert(bt->left, newVal, weight); }//traverse if a node exists
			}
			else {
				if (bt->right == nullptr) { //checks if there is no val in next node
											//populates and links if none
					bt->right = newBTNode(newVal, weight);
				}
				else { btInsert(bt->right, newVal, weight); }//traverse if a node exists
			}
		}
	}

	void bstInsert(node2* bt, std::string newVal) {
		if (bt == nullptr) {//initializes head of bst
			bt = newBSTNode(newVal);
			return;
		}
		else {
			if (newVal[0] <= bt->data[0]) {
				if (bt->left == nullptr) { //checks if there is no val in next node
										   //populates and links if none
					bt->left = newBSTNode(newVal);
				}
				else { bstInsert(bt->left, newVal); }//traverse if a node exists
			}
			else {
				if (bt->right == nullptr) { //checks if there is no val in next node
											//populates and links if none
					bt->right = newBSTNode(newVal);
				}
				else { bstInsert(bt->right, newVal); }//traverse if a node exists
			}
		}
	}
	//helper function for insert, mass is a flag variable so that we can reuse the newnode function for q2
	node* newBTNode(int newVal, int mass) {
		node*  tmp = new node;
		tmp->data = newVal;

		tmp->weight = mass;
		tmp->left = nullptr;
		tmp->right = nullptr;
		return tmp;
	}
	
	node2* newBSTNode(std::string newVal) {
		node2*  tmp = new node2;
		tmp->data = newVal;
		tmp->left = nullptr;
		tmp->right = nullptr;
		return tmp;
	}

	bool isBST(node* bt) {
		if (bt == nullptr) return true;
		if (bt->left != nullptr) { // 3 cases if bothL and R have value if only L has value if R has value only if only root has value
			if (bt->right != nullptr) {
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

	void dipside(node *bt, int sp) {
		if (bt != nullptr) {
			dipside(bt->right, sp += 5);
			cout << setw(sp) << bt->data << endl;
			dipside(bt->left, sp);
		}
	}

	template<typename t> // be able to call this with both int and string 
	void preorder(t* bt) {
		if (bt != nullptr) {
			std::cout << bt->data << " ";//dont display bst as list
			preorder(bt->left);
			preorder(bt->right);
		}
	}

	void inorder(node2* bt) {
		if (bt == nullptr) return;

		inorder(bt->left);
		inorder(bt->right);
		cout << bt->data << " ";
	}
};

int main() {
	binaryTree bt, bst;
	// question 1
	cout << "Problem 1 a, b, c:\n";
	bt.createBT(); //part 1.a 
	cout << "Pre-order: ";
	bt.preorder(bt.root); //part 1.b
	bool isIt = bt.isBST(bt.root); // part 1.c
	cout << "\nIs BST: " << isIt << endl;
	cout << "\nMax: ";
	cout << bt.maxNode(bt.root, 0) << endl; // part 1.d
	cout << "\n";
	// question 2
	cout << "Problem 2 a, b, c:\n";
	std::string months[12] = { "Jan", "Feb", "Mar" , "Apr" ,
		"May" , "Jun" , "Jul" , "Aug" ,
		"Sep" , "Oct" , "Nov" , "Dec" };
	int j = 11;
	for (int i = 0; i < 12; i++) {	//populates bst part 2.a currently not working
		bst.bstInsert(bst.t1, months[i]);
		bst.bstInsert(bst.t2, months[j--]);
	}
	cout << "t1 in-order: ";  // part b
	bst.inorder(bst.t1); 
	cout << "\nt2 in-order: ";
	bst.inorder(bst.t2);
	cout << "part c"; // probably need to construct the tree or something
	// question 3
	cout << "Problem 3:\n"; // no idea on how to approch this, will ask prof tomorrow
	/...
	system("pause"); // micheal scott
}
