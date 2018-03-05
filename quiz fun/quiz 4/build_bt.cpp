/* my info */
#include <iostream>
#include <vector>
#include <iomanip>

struct node {
	int data;
	node * left, *right;
};

class bt { // binary tree base class
	public:

		node * bt_head;
		bt(int root) { 
			bt_head = new node; 
			bt_head->data = root;	
			bt_head->left = bt_head->right = nullptr;
		}
		// function that is called to create the tree
		void createTree(std::vector<int> post, std::vector<int> in, int treeRoot) {
			std::vector<int> leftTreeList, rightTreeList;
			std::vector<int>::iterator position = in.begin();
			for (position; *position != treeRoot; ++position) { // have left be {10, 5, 40}
				leftTreeList.push_back(*position);
			}
			position++; // currently at position 20 move to next position
			for (position; position != in.end(); ++position) { // have right be {30, 15}
				rightTreeList.push_back(*position);
			}

			bt_head->left = getSubTrees(leftTreeList, treeRoot);
			bt_head->right = getSubTrees(rightTreeList, treeRoot);

		}
		// function to get the subtree and then return it
		node * getSubTrees(std::vector<int> list, int r) {
			if (list.size() == 3) {
				int root = list[1];
				node * tmp = new node;
				tmp->data = root;
				tmp->left = newNode(list[0]);
				tmp->right = newNode(list[2]);
				return tmp;
			}
			else {
				int root = list[1];
				node * tmp = new node;
				tmp->data = root;
				tmp->left = newNode(list[0]);
				tmp->right = nullptr;
				return tmp;
			}
		}

		node * newNode(int val) {
			node * tmp = new node;
			tmp->data = val;
			tmp->left = nullptr;
			tmp->right = nullptr;
			return tmp;
		}

		void dipside(node *bt, int sp) {//part c
			if (bt != nullptr) {
				dipside(bt->right, sp += 5);
				std::cout << std::setw(sp) << bt->data << std::endl;
				dipside(bt->left, sp);
			}
		}
		
};

int main(){
	//traversel order given on paper
	std::vector<int> postorder = { 10, 40, 5, 30, 15, 20 }; 
	std::vector<int> inorder =   { 10, 5, 40, 20, 30, 15 };
	bt binary_tree(postorder.back());
	binary_tree.createTree(postorder, inorder, binary_tree.bt_head->data);
	binary_tree.dipside(binary_tree.bt_head, 0);
    return 0;
}

