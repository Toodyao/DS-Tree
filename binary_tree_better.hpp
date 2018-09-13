#ifndef DS_TREE_BINARY_TREE_BETTER_H
#define DS_TREE_BINARY_TREE_BETTER_H

#include "tree_node.hpp"
#include <iostream>
#include <queue>

template <typename T>
class BinaryTree : public TreeNode<T> {
protected:
	// TreeNode<T> *root_node;
	int max(int a, int b);
public:
	BinaryTree();
	explicit BinaryTree(TreeNode<T> * root);

	virtual ~BinaryTree();

//	inline TreeNode<T> *root();
	inline T data(TreeNode<T> * node);

	void pre_order(TreeNode<T>* t);
	void in_order(TreeNode<T>* t);
	void post_order(TreeNode<T>* t);
	void level_order();

	int get_tree_height(TreeNode<T> *);

	void delete_subtree(TreeNode<T> *t);

	TreeNode<T>* get_left() {
		return this->lchild;
	}
	TreeNode<T>* get_right() {
		return this->rchild;
	}

	void add_left(TreeNode<T> *t) {
		this->lchild = t;
	}
	void add_right(TreeNode<T> *t) {
		this->rchild = t;
	}
	void add_left(T d) {
		this->lchild = new TreeNode<int>(d);
	}
	void add_right(T d) {
		this->rchild = new TreeNode<int>(d);
	}
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	 // root_node = new TreeNode<T>;
}

template<typename T>
BinaryTree<T>::BinaryTree(TreeNode<T> *root) {
//	 root_node = root;
	this->_data  = root->get_data();
	this->lchild = root->left_child();
	this->rchild = root->right_child();
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	delete_subtree(get_left());
	delete_subtree(get_right());
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
T BinaryTree<T>::data(TreeNode<T> *node) {
	return node->get_data();
}

template<typename T>
void BinaryTree<T>::pre_order(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		std::cout << t->get_data() << " ";
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
		std::cout << t->get_data() << " ";
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
		std::cout << t->get_data() << " ";
	}
}

template<typename T>
void BinaryTree<T>::level_order() {
	std::queue<TreeNode<T>* > q;
	q.push(this);
	while (!q.empty()) {
		TreeNode<T>* temp = q.front();
		q.pop();
		if (temp == nullptr)
			continue;
		std::cout << temp->get_data() << " ";
		q.push(temp->left_child());
		q.push(temp->right_child());
	}
	std::cout << std::endl;
}

template<typename T>
int BinaryTree<T>::get_tree_height(TreeNode<T> *root) {
	if (root == nullptr)
		return 0;
	return max(get_tree_height(root->left_child())+1, get_tree_height(root->right_child())+1);
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


#endif //DS_TREE_BINARY_TREE_BETTER_H
