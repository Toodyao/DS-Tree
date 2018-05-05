#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::TN *BinarySearchTree::find_min_recursion(TN *node) {
	if (node == nullptr)
		return nullptr;
	else if (node->left_child() == nullptr)
		return node;
	else
		return find_min_recursion(node->left_child());
}

BinarySearchTree::TN *BinarySearchTree::find_max_recursion(TN *node) {
	if (node == nullptr)
		return nullptr;
	else if (node->right_child() == nullptr)
		return node;
	else
		return find_min_recursion(node->right_child());
}

void BinarySearchTree::insert(int n) {

}

void BinarySearchTree::del(int n) {

}

BinarySearchTree::TN *BinarySearchTree::find_min() {
	// Recursively find
	// return find_min_recursion(nullptr);

	// Iteratively find
	TN * temp = root;
	while (temp->left_child())
		temp = temp->left_child();
	return temp;
}

BinarySearchTree::TN *BinarySearchTree::find_max() {
	// Recursively find
	// return find_max_recursion(nullptr);

	// Iteratively find
	TN * temp = root;
	while (temp->right_child())
		temp = temp->right_child();
	return temp;
}

