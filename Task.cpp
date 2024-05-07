#include "Task.h"

int main() {
	Tree<int> tree;
	tree.insert(tree.root(), 1);
	tree.insert(tree.root(), 3);
	tree.insert(tree.root(), 5);
	tree.insert(tree.root(), 2);
	erase_leaf(tree, tree.root());
	tree.print(tree.root());
}

void erase_leaf(Tree<int>& tree, Node<int>*& node) {
	if (node == nullptr)
		return;

	if (node->_right == nullptr && node->_left == nullptr) {
		tree.erase(node->_data);
		return;
	}

	erase_leaf(tree, node->_left);
	erase_leaf(tree, node->_right);
}
