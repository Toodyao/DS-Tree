#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {
	root_node = nullptr;
}


void BinarySearchTree::insert(int n) {
	root_node = insert_recursion(n, root_node);
}
void BinarySearchTree::del(int n) {
	del_recursion(n, root_node);
}

BinarySearchTree::TN *BinarySearchTree::insert_recursion(int n, BinarySearchTree::TN *node) {
	if (node == nullptr) {
		node = new TN(n);
		// Same as:
		// temp->set_data(n);
		// temp->add_left(nullptr);
		// temp->add_right(nullptr);
	} else if (n < node->data()) {
		node->add_left(insert_recursion(n, node->left_child_pointer()));
		// Same as:
		// node->left_child_pointer() = insert_recursion(n, node->left_child_pointer());
	} else if (n > node->data()) {
		node->add_right(insert_recursion(n, node->right_child_pointer()));
	}
	return node;
}

BinarySearchTree::TN *BinarySearchTree::del_recursion(int n, BinarySearchTree::TN *node) {
	return nullptr;
}

BinarySearchTree::TN *BinarySearchTree::find_min_recursion(TN *node) {
	if (node == nullptr)
		return nullptr;
	else if (node->left_child_pointer() == nullptr)
		return node;
	else
		return find_min_recursion(node->left_child_pointer());
}

BinarySearchTree::TN *BinarySearchTree::find_max_recursion(TN *node) {
	if (node == nullptr)
		return nullptr;
	else if (node->right_child_pointer() == nullptr)
		return node;
	else
		return find_max_recursion(node->right_child_pointer());
}

BinarySearchTree::TN *BinarySearchTree::find_min() {
	// Recursively find
	// return find_min_recursion(nullptr);

	// Iteratively find
	TN * temp = root_node;
	while (temp->left_child_pointer())
		temp = temp->left_child_pointer();
	return temp;
}

BinarySearchTree::TN *BinarySearchTree::find_max() {
	// Recursively find
	// return find_max_recursion(nullptr);

	// Iteratively find
	TN * temp = root_node;
	while (temp->right_child_pointer())
		temp = temp->right_child_pointer();
	return temp;
}

