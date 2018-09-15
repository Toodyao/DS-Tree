#ifndef DS_TREE_BINARY_TREE_BETTER_H
#define DS_TREE_BINARY_TREE_BETTER_H

#include "tree_node.hpp"
#include <iostream>
#include <queue>

template<typename T>
class BinaryTree : public TreeNode<T> {
protected:
	// TreeNode<T> *root_node;
	int max(int a, int b);

public:
	BinaryTree();

	explicit BinaryTree(TreeNode<T>* root);

	virtual ~BinaryTree();

//	inline TreeNode<T> *root();
	inline T data(TreeNode<T>* node);

	void pre_order_recursion(TreeNode<T>* t);

	void in_order_recursion(TreeNode<T>* t);

	void post_order_recursion(TreeNode<T>* t);

	void level_order();

	int get_tree_height(TreeNode<T>*);

	void delete_subtree(TreeNode<T>* t);

	TreeNode<T>* left_child_pointer() {
		return this->lchild;
	}

	TreeNode<T>* right_child_pointer() {
		return this->rchild;
	}

	TreeNode<T>& add_left(TreeNode<T>* t) {
		this->lchild = t;
	}

	TreeNode<T>& add_right(TreeNode<T>* t) {
		this->rchild = t;
	}

	TreeNode<T>& add_left(T d) {
		this->lchild = new TreeNode<int>(d);
	}

	TreeNode<T>& add_right(T d) {
		this->rchild = new TreeNode<int>(d);
	}
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	// root_node = new TreeNode<T>;
}

template<typename T>
BinaryTree<T>::BinaryTree(TreeNode<T>* root) {
//	 root_node = root;
	this->_data = root->data();
	this->lchild = root->left_child_pointer();
	this->rchild = root->right_child_pointer();
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	delete_subtree(left_child_pointer());
	delete_subtree(right_child_pointer());
}

template<typename T>
int BinaryTree<T>::max(const int a, const int b) {
	return a > b ? a : b;
}

//template<typename T>
//TreeNode<T> * BinaryTree<T>::root() {
//	return root_node;
//}

template<typename T>
T BinaryTree<T>::data(TreeNode<T>* node) {
	return node->data();
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
	q.push(this);
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


#endif //DS_TREE_BINARY_TREE_BETTER_H
