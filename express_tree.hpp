#ifndef DS_TREE_EXPRESS_TREE_HPP
#define DS_TREE_EXPRESS_TREE_HPP

#include "binary_tree.hpp"
#include "expression_calculate.h"

template<typename T>
class ExpressTree : public BinaryTree<T> {
private:
	TreeNode<T> *&exp_tree_node = BinaryTree<T>::root_node;
public:
	ExpressTree();
	explicit ExpressTree(TreeNode<T> * root);
	explicit ExpressTree(BinaryTree<T> * root);
	~ExpressTree();

	void reconstruct(TreeNode<T> * root) {
		exp_tree_node = root;
	}

	void print_like_tree();

	std::queue<std::pair<TreeNode<T> *, int>> to_full_binary_tree(TreeNode<T> *root);

	void in_order(TreeNode<T>* t);
};

template<typename T>
ExpressTree<T>::ExpressTree() {
	exp_tree_node = new TreeNode<T>;
}

template<typename T>
ExpressTree<T>::ExpressTree(TreeNode<T> *root) {
	exp_tree_node = root;
}

template<typename T>
ExpressTree<T>::ExpressTree(BinaryTree<T> *root) {
	exp_tree_node = root;
}

template<typename T>
ExpressTree<T>::~ExpressTree() {

}

template<typename T>
void ExpressTree<T>::print_like_tree() {
	typedef std::pair<TreeNode<T>*, int> P; // the int value stores current tree height
	std::queue<P> q = to_full_binary_tree(exp_tree_node);
	int height = BinaryTree<T>::get_tree_height(exp_tree_node);
	int mid_pos = ((1 << height - 1) - 1);
	int newline = 0;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();

		if (temp.second != newline) { // start a new line
			std::cout << std::endl << std::endl;
			// fill up with spaces
			for (int i = 0; i < mid_pos/(1<<newline); i++)
				std::cout << " ";
			newline = temp.second;
		}

		if (temp.first == nullptr)
			std::cout << " "; // use "#" if you want to print a full binary tree with null node
		else
			std::cout << temp.first->data();

		// spaces between nodes in same level
		for (int i = 0; i < mid_pos/(1<<(newline-2)); i++)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template<typename T>
std::queue<std::pair<TreeNode<T> *, int> > ExpressTree<T>::to_full_binary_tree(TreeNode<T> *root) {
	typedef TreeNode<T>* TN;
	typedef std::pair<TN, int> P; // the int value stores current tree height
	std::queue<P> ans, q;
	int height = BinaryTree<T>::get_tree_height(exp_tree_node);
	q.push(P(exp_tree_node, 1)); // tree height starts at 1
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		ans.push(temp);
		if (temp.second >= height) {
			continue;
		}
		if (temp.first == nullptr) {
			// memory leak (maybe)
			// use "#" if you want to print a full binary tree with null node
			q.push(P(new TreeNode<std::string> (" "), temp.second+1));
			q.push(P(new TreeNode<std::string> (" "), temp.second+1));
			continue;
		}
		q.push(P(temp.first->left_child_pointer(),  temp.second+1));
		q.push(P(temp.first->right_child_pointer(), temp.second+1));
	}
	return ans;
}


template<typename T>
void ExpressTree<T>::in_order(TreeNode<T>* t) {
	if (t == nullptr)
		return;
	else {
		bool brackets_flag = false; // whether to print brackets
		char op1 = t->data()[0];
		char op2 = 0;
		if (t->left_child_pointer() != nullptr)
			op2 = t->left_child_pointer()->data()[0];
		if (is_op(op1) && (priority(op1) > priority(op2)))
			brackets_flag = true;

		if (brackets_flag)
			std::cout << "(";
		in_order(t->left_child_pointer());
		if (brackets_flag)
			std::cout << ")";
		std::cout << t->data() << " ";
		in_order(t->right_child_pointer());
	}
}

#endif //DS_TREE_EXPRESS_TREE_HPP
