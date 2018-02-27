/* INFO */

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std; //lel(no)

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

	void insert(treeNode* bt, std::string newVal) {
		if (bt_head == nullptr) {//initializes head of bst
			bt_head = new treeNode;
			bt_head->name = newVal;
			return;
		}
		else { // inserts alphabetically!
			if (newVal[0] <= bt->name[0]) {
				if (bt->left == nullptr) { //checks if there is no val in next node
					treeNode *tmp = new treeNode;//populates and links if none
					tmp->name = newVal;
					bt->left = tmp;
					tmp = nullptr;
				}
				else { insert(bt->left, newVal); }//traverse if a node exists
			}
			else{
				if (bt->right == nullptr) { //checks if there is no val in next node
					treeNode *tmp = new treeNode;//populates and links if none
					tmp->name = newVal;
					bt->right = tmp;
					tmp = nullptr;
				}
				else { insert(bt->right, newVal); }//traverse if a node exists
			}
			
		}
	}
	void preorder(treeNode* bt) {
		if (bt != nullptr) {
			std::cout << bt->name << " ";//dont display bst as list
			preorder(bt->left);
			preorder(bt->right);
		}
	}
	void inorder(treeNode*bt) {//part b
		if (bt != nullptr) {
			inorder(bt->left);
			std::cout << bt->name << " ";
			inorder(bt->right);
		}
	}
	void dipside(treeNode *bt,int sp) {//part c
		if (bt != nullptr) {
			dipside(bt->right,sp+=5);
			cout << setw(sp) << bt->name << endl;
			dipside(bt->left,sp);
		}
	}
	int height(treeNode *bt) {
		if (bt == nullptr){
			return 0;
		}
		else {
			return  1 + max(height(bt->left), height(bt->right));
		}
	}
};

int main() {
	bst tree;
	std::string months[12] = { "Jan", "Feb", "Mar" , "Apr" ,
		"May" , "Jun" , "Jul" , "Aug" ,
		"Sep" , "Oct" , "Nov" , "Dec" };
	for (int i = 0; i < 12; i++) {	//populates bst
		tree.insert(tree.bt_head, months[i]);
	}
	cout << "Part b: " << endl;
	tree.inorder(tree.bt_head);
	cout << "\n\nPart c:\n";
	tree.dipside(tree.bt_head,0);
	cout << "\n\nPart d:\n";
	cout << "Height= " << tree.height(tree.bt_head) << endl;
	system("pause");
}
