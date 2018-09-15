#ifndef DS_TREE_BINARY_TREE_HPP
#define DS_TREE_BINARY_TREE_HPP

#include "tree_node.hpp"
#include <iostream>
#include <queue>

template<typename T>
class BinaryTree {
protected:
	TreeNode<T>* root_node;
	int max(int a, int b);
public:
	BinaryTree();
	explicit BinaryTree(TreeNode<T>* root);

	virtual ~BinaryTree();

	inline TreeNode<T>* root();
	inline T data(TreeNode<T>* node);
	void set_data(T d);

	TreeNode<T>* left_child_pointer();
	TreeNode<T>* right_child_pointer();
	TreeNode<T>& left_child();
	TreeNode<T>& right_child();
	TreeNode<T>& add_left(TreeNode<T>* t);
	TreeNode<T>& add_right(TreeNode<T>* t);
	TreeNode<T>& add_left(T d);
	TreeNode<T>& add_right(T d);

	void pre_order();
	void in_order();
	void post_order();
	void level_order();

	void pre_order_recursion(TreeNode<T>* t);
	void in_order_recursion(TreeNode<T>* t);
	void post_order_recursion(TreeNode<T>* t);

	int get_tree_height(TreeNode<T>*);

	void delete_subtree(TreeNode<T>* t);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root_node = new TreeNode<T>;
}

template<typename T>
BinaryTree<T>::BinaryTree(TreeNode<T>* root) {
	root_node = root;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	delete_subtree(root_node);
}

template<typename T>
int BinaryTree<T>::max(const int a, const int b) {
	return a > b ? a : b;
}

template<typename T>
TreeNode<T>* BinaryTree<T>::root() {
	return root_node;
}

template<typename T>
T BinaryTree<T>::data(TreeNode<T>* node) {
	return node->data();
}

template<typename T>
void BinaryTree<T>::pre_order() {
	pre_order_recursion(root_node);
}

template<typename T>
void BinaryTree<T>::in_order() {
	in_order_recursion(root_node);
}

template<typename T>
void BinaryTree<T>::post_order() {
	post_order_recursion(root_node);
}

template<typename T>
void BinaryTree<T>::pre_order_recursion(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		std::cout << t->data() << " ";
		pre_order_recursion(t->left_child_pointer());
		pre_order_recursion(t->right_child_pointer());
	}

}

template<typename T>
void BinaryTree<T>::in_order_recursion(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		in_order_recursion(t->left_child_pointer());
		std::cout << t->data() << " ";
		in_order_recursion(t->right_child_pointer());
	}
}

template<typename T>
void BinaryTree<T>::post_order_recursion(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		post_order_recursion(t->left_child_pointer());
		post_order_recursion(t->right_child_pointer());
		std::cout << t->data() << " ";
	}
}

template<typename T>
void BinaryTree<T>::level_order() {
	std::queue<TreeNode<T>*> q;
	q.push(root_node);
	while (!q.empty()) {
		TreeNode<T>* temp = q.front();
		q.pop();
		if (temp == nullptr)
			continue;
		std::cout << temp->data() << " ";
		q.push(temp->left_child_pointer());
		q.push(temp->right_child_pointer());
	}
	std::cout << std::endl;
}

template<typename T>
int BinaryTree<T>::get_tree_height(TreeNode<T>* root) {
	if (root == nullptr)
		return 0;
	return max(get_tree_height(root->left_child_pointer()) + 1, get_tree_height(root->right_child_pointer()) + 1);
}

template<typename T>
void BinaryTree<T>::delete_subtree(TreeNode<T>* t) { // post order delete
	if (t != nullptr) {
		delete_subtree(t->left_child_pointer());
		delete_subtree(t->right_child_pointer());
//		std::cout << "deleted " << t->data() << std::endl;
		delete t;
		return;
	}
}

template<typename T>
TreeNode<T>* BinaryTree<T>::left_child_pointer() {
	return root_node->lchild;
}

template<typename T>
TreeNode<T>* BinaryTree<T>::right_child_pointer() {
	return root_node->rchild;
}

template<typename T>
TreeNode<T>& BinaryTree<T>::left_child() {
	return root_node->left_child();
}

template<typename T>
TreeNode<T>& BinaryTree<T>::right_child() {
	return root_node->right_child();
}

template<typename T>
TreeNode<T>& BinaryTree<T>::add_left(TreeNode<T>* t) {
	root_node->lchild = t;
	return *t;
}

template<typename T>
TreeNode<T>& BinaryTree<T>::add_right(TreeNode<T>* t) {
	root_node->rchild = t;
	return *t;
}

template<typename T>
TreeNode<T>& BinaryTree<T>::add_left(T d) {
	root_node->lchild = new TreeNode<int>(d);
	return root_node->left_child();
}

template<typename T>
TreeNode<T>& BinaryTree<T>::add_right(T d) {
	root_node->rchild = new TreeNode<int>(d);
	return root_node->right_child();
}

template<typename T>
void BinaryTree<T>::set_data(T d) {
	root_node->_data = d;
}


#endif //DS_TREE_BINARY_TREE_HPP
