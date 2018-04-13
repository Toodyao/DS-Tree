#ifndef DS_TREE_BINARY_TREE_HPP
#define DS_TREE_BINARY_TREE_HPP

#include "tree_node.hpp"
#include <iostream>

template <typename T>
class BinaryTree : public TreeNode<T> {
private:
	TreeNode<T> *root_node;
public:
	BinaryTree();
	~BinaryTree();

	inline TreeNode<T> *root();
	inline T data(TreeNode<T> * node);

	void pre_order(TreeNode<T>* t);
	void in_order(TreeNode<T>* t);
	void post_order(TreeNode<T>* t);

	void delete_subtree(TreeNode<T> *t);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root_node = new TreeNode<T>;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	delete_subtree(root_node);
}

template<typename T>
TreeNode<T> * BinaryTree<T>::root() {
	return root_node;
}

template<typename T>
T BinaryTree<T>::data(TreeNode<T> *node) {
	return node->get_data();
}

template<typename T>
void BinaryTree<T>::pre_order(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		std::cout << t->get_data() << std::endl;
		pre_order(t->left_child());
		pre_order(t->right_child());
	}

}

template<typename T>
void BinaryTree<T>::in_order(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		in_order(t->left_child());
		std::cout << t->get_data() << std::endl;
		in_order(t->right_child());
	}
}

template<typename T>
void BinaryTree<T>::post_order(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		post_order(t->left_child());
		post_order(t->right_child());
		std::cout << t->get_data() << std::endl;
	}
}

template<typename T>
void BinaryTree<T>::delete_subtree(TreeNode<T> *t) { // post order delete
	if (t != nullptr) {
		delete_subtree(t->left_child());
		delete_subtree(t->right_child());
//		std::cout << "deleted " << t->get_data() << std::endl;
		delete t;
		return;
	}
}


#endif //DS_TREE_BINARY_TREE_HPP
