/*
Authors:
Fernando Cuevas
Michael Rodriguez
Class:   CPSC 335 - 12884, Algorithms, Tue/Thur
Project: Assignment 6, more Binary Search Tree
*/
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
		btInsert(root, 10, 6);
		btInsert(root, 2, 2);
		btInsert(root, 5, 1);
		btInsert(root, 20, 3);
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
			t1 = new node2;
			t1 = newBSTNode(newVal); // this is the reason for some reason works with t1
			return;			// but when using node2* bt insertions are not going through 
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
		if (bt->left != nullptr && maxNode(bt->left, bt->data)) { // 3 cases if bothL and R have value if only L has value if R has value only if only root has value
			return false;
		}
		if (bt->right != nullptr && maxNode(bt->right, bt->data)) {
			return false;
		}
		if (!isBST(bt->left) && !isBST(bt->right)) {
			return false;
		}
		return true;
	}
	// fix max
	int maxNode(node* bt, int max) {
		if (bt == nullptr) return 0;
		else maxx(bt->data, maxNode(bt->left, max), maxNode(bt->right, max));
	}

	int maxx(int a, int b, int c) {
		return (a > b &&  a> c) ? a : ((b > c) ? b : c);
	}

	bool same(node2* bt1, node2* bt2) {
		if (bt1 == nullptr && t2 == nullptr) return true;
		else if (bt1 == nullptr || bt2 == nullptr) return false;

		else 
			return same(bt1->left, bt2->left) && same(bt1->right, bt2->right);
	}

	template<typename t>
	void dipside(t *bt, int sp) {
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
		if (bt != nullptr) {

			inorder(bt->left);
			cout << bt->data << " ";
			inorder(bt->right);
		}
	}
};

int main() {
	binaryTree bt, bst, rbst;
	
	// question 1
	cout << "Problem 1 a, b, c:\n";
	
	cout << "Part 1.a and 1.b\n";
	bt.createBT(); //part 1.a 
	bt.dipside(bt.root, 0);
	cout << "\nPre-order: ";
	bt.preorder(bt.root); //part 1.b
	
	cout << "\nPart 1.c";
	bool isIt = bt.isBST(bt.root); // part 1.c
	if(isIt)
		cout << "\nIs BST: True\n";
	else
		 cout << "\nIs BST: False";

	cout << "\nPart 1.d";
	cout << "\nMax: " << bt.maxNode(bt.root, 0) << endl; // part 1.d
	cout << "\n";

	// question 2
	cout << "Problem 2 a, b, c:\n";
	std::string months[12] = { "Jan", "Feb", "Mar" , "Apr" ,
		"May" , "Jun" , "Jul" , "Aug" ,
		"Sep" , "Oct" , "Nov" , "Dec" };
	int j = 12;
	for (int i = 0; i < 12; i++) {	//populates bst part 2.a / 2.b
		bst.bstInsert(bst.t1, months[i]);
		rbst.bstInsert(rbst.t1, months[--j]);
	}
	cout << "Part 2.a\n";
	cout << "Regular insertion:\n";
	bst.dipside(bst.t1, 0);
	cout << "\n-------------------------------\n";
	cout << "Reverse insertion:\n";
	rbst.dipside(rbst.t1, 0);
	
	cout << "\nPart 2.c:\n"; //part 2.c
	cout << "t1 in-order: ";  
	bst.inorder(bst.t1);
	cout << "\nt2 in-order: ";
	rbst.inorder(rbst.t1);
	if (bst.same(bst.t1, rbst.t1) == true) cout << "\nAre same tree:  Same inorder and Similar shape \n";
	else cout << "\nAre same tree: Similar inorder but not similar shape\n";
					  // question 3
	cout << "Problem 3:\n"; // just copy from here and above to have updateed file
		string x, y;
	long long num1pt1 = 0, num1pt2 =0, num2pt1=0, num2pt2=0;
	cout << "Problem 3:\n"; // no idea on how to approch this, will ask prof tomorrow
	cout << "Enter a large number       : ";
	cin >> x;
	if (x.size() > 12) {
		char buffer[19];
		x.copy(buffer, x.size() - 12, 0);
		buffer[x.size() - 12] = '\0';
		x.erase(0, x.size() - 12);
		num1pt1 = stoll(buffer);
	}
	num1pt2 = stoll(x);

	cout << "Enter another large number : ";
	cin >> y;
	if (y.size() > 12) {
		char buffer[19];
		y.copy(buffer, y.size() - 12, 0);
		buffer[y.size() - 12] = '\0';
		y.erase(0, y.size() - 12);
		num2pt1 = stoll(buffer);
	}
	num2pt2 = stoll(y);
	cout << num1pt1 << num1pt2 << endl;
	cout << "+" << num2pt1 << num2pt2 << endl;
	num1pt1 += num2pt1;
	num1pt2 += num2pt2;
	x = to_string(num1pt2);
	if (x.size() > 12) {
		x.erase(0, 1);
		num1pt2 = stoll(x);
		num1pt1 += 1;
	}
	cout << "--------------------" << endl;
	cout << num1pt1 << num1pt2 << endl;
	system("pause");
}
