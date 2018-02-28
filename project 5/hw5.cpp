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
			else {
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
	void dipside(treeNode *bt, int sp) {//part c
		if (bt != nullptr) {
			dipside(bt->right, sp += 5);
			cout << setw(sp) << bt->name << endl;
			dipside(bt->left, sp);
		}
	}
	int height(treeNode *bt) {//part d & e
		if (bt == nullptr) { return 0; }
		else {
			return  1 + max(height(bt->left), height(bt->right));
		}
	}
	int nodes(treeNode *bt) {//part f
		if (bt == nullptr) { return 0; }
		else {
			return  1 + nodes(bt->left) + nodes(bt->right);
		}
	}
	void descendants(treeNode *bt, string newVal) {//part g
		if (bt != nullptr) {
			if (bt->name == newVal) {
				if (bt->left != nullptr) { preorder(bt->left); }
				if (bt->right != nullptr) { preorder(bt->right); }
				return;
			}
			descendants(bt->left, newVal);
			descendants(bt->right, newVal);
		}
	}
	bool ancestordotcom(treeNode *bt, string key) { // part h
		if (bt == nullptr) return false;
		if (bt->name == key) return true;

		if (ancestordotcom(bt->left, key) || ancestordotcom(bt->right, key)) {
			cout << bt->name << " ";
			return true;
		}
		return false;
	}
	//part i
	treeNode* blackmirror(treeNode * bt) {
		treeNode* tmp = new treeNode;
		if (bt == nullptr) return nullptr;
		tmp->name = bt->name;
		
		tmp->left = blackmirror(bt->right);
		tmp->right = blackmirror(bt->left);

		return tmp;
	}
	//part j
	void lvlcmp(treeNode* og, treeNode* cmp, int lvl, int sp) {
		if (og == nullptr) return;
		if (lvl == 1) {
			cout << setw(sp) << "O.G: " << og->name << " <-> " << "MIRROR:" << cmp->name << " ";
		}
		else if (lvl > 1) {
			lvlcmp(og->left, cmp->right, lvl-1, sp);
			lvlcmp(og->right, cmp->left, lvl-1, sp);
		}
	}
	void printlvls(treeNode* og, treeNode* cmp) {
		if (height(og) != height(cmp)) { cout << "Not same height trees!!"; return; }
		int tHeight = height(og);
		for (int i = 1; i <= tHeight; i++) {
			int sp = tHeight - i;
			lvlcmp(og, cmp, i, sp);
			std::cout << std::endl;
		}
	}
};

int main() {
	bst tree, mirror_edge;
	std::string months[12] = { "Jan", "Feb", "Mar" , "Apr" ,
		"May" , "Jun" , "Jul" , "Aug" ,
		"Sep" , "Oct" , "Nov" , "Dec" };
	for (int i = 0; i < 12; i++) {	//populates bst
		tree.insert(tree.bt_head, months[i]);
	}
	cout << "Part b:\n";	//part b
	tree.inorder(tree.bt_head);
	cout << "\n\nPart c:\n";//part c
	tree.dipside(tree.bt_head, 0);
	cout << "\nPart d:\n";//part d
	cout << "Height= " << tree.height(tree.bt_head);
	cout << "\n\nPart e:\n";//part e
	cout << "Left subtree height= " << tree.height(tree.bt_head->left);
	cout << "\nRight subtree height= " << tree.height(tree.bt_head->right);
	cout << "\n\nPart f:\n";//part f
	cout << "Left subtree nodes= " << tree.nodes(tree.bt_head->left);
	cout << "\nRight subtree nodes= " << tree.nodes(tree.bt_head->right);
	cout << "\n\nPart g:\n";//part g
	tree.descendants(tree.bt_head, "Mar");
	cout << "\n\nPart h:\n";//part h
	tree.ancestordotcom(tree.bt_head, "Sep");
	cout << "\n\nPart i:\n";
	mirror_edge.bt_head = tree.blackmirror(tree.bt_head);
	mirror_edge.dipside(mirror_edge.bt_head, 0);
	cout << "\n\nPart j:\n";
	tree.printlvls(tree.bt_head, mirror_edge.bt_head);
	system("pause");
}
