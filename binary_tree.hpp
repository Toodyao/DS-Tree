#ifndef DS_TREE_BINARY_TREE_HPP
#define DS_TREE_BINARY_TREE_HPP

#include "tree_node.hpp"
#include <iostream>
#include <queue>

template <typename T>
class BinaryTree : public TreeNode<T> {
private:
	TreeNode<T> *root_node;
	std::queue<std::pair<TreeNode<T> *, int> >  to_full_binary_tree(TreeNode<T>* root);
	int max(int a, int b);
public:
	BinaryTree();
	explicit BinaryTree(TreeNode<T> * root);
	~BinaryTree();

	inline TreeNode<T> *root();
	inline T data(TreeNode<T> * node);

	void pre_order(TreeNode<T>* t);
	void in_order(TreeNode<T>* t);
	void post_order(TreeNode<T>* t);
	void level_order();
	void print_like_tree();

	int get_tree_height(TreeNode<T> *);

	void delete_subtree(TreeNode<T> *t);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root_node = new TreeNode<T>;
}

template<typename T>
BinaryTree<T>::BinaryTree(TreeNode<T> *root) {
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
void BinaryTree<T>::level_order() {
	std::queue<TreeNode<T>* > q;
	q.push(root_node);
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

template<typename T>
void BinaryTree<T>::print_like_tree() {
	typedef std::pair<TreeNode<T>*, int> P; // the int value stores current tree height
	std::queue<P> q = to_full_binary_tree(root_node);
	int newline = 0;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		if (temp.second != newline) {
			std::cout << std::endl;
			newline = temp.second;
		}
		if (temp.first == nullptr)
			std::cout << "#" << " ";
		else
			std::cout << temp.first->get_data() << " ";

	}
}

template<typename T>
std::queue<std::pair<TreeNode<T> *, int> > BinaryTree<T>::to_full_binary_tree(TreeNode<T> *root) {
	typedef TreeNode<T>* TN;
	typedef std::pair<TN, int> P; // the int value stores current tree height
	std::queue<P> ans, q;
	int height = get_tree_height(root_node);
	q.push(P(root_node, 1)); // tree height starts at 1
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		ans.push(temp);
		if (temp.second >= height) {
			continue;
		}
		if (temp.first == nullptr) {
			q.push(P(new TreeNode<std::string> ("#"), temp.second+1));
			q.push(P(new TreeNode<std::string> ("#"), temp.second+1));
			continue;
		}
		q.push(P(temp.first->left_child(),  temp.second+1));
		q.push(P(temp.first->right_child(), temp.second+1));
	}
	return ans;
}


#endif //DS_TREE_BINARY_TREE_HPP
