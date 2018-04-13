#ifndef DS_TREE_BINARY_TREE_HPP
#define DS_TREE_BINARY_TREE_HPP

#include "tree_node.hpp"
#include <string>
#include <cctype>
#include <cmath>

template <typename T>
class BinaryTree : public TreeNode<T> {
private:
	TreeNode<T> *root_ptr;
public:
	BinaryTree();
	~BinaryTree();

	TreeNode<T> build_tree_from_string(std::string s);
	void build_tree(TreeNode<T> *node, const std::string s, const size_t i);

	inline TreeNode<T> *root();
	inline T data(TreeNode<T> * node);

	double read_number(const std::string &s, size_t &i);
//	double read_number(const std::string &s, size_t i);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root_ptr = new TreeNode<T>;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {

}

template<typename T>
TreeNode<T> BinaryTree<T>::build_tree_from_string(std::string s) {
	TreeNode<T> *temp;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			continue;
		else if (std::isdigit(s[i])) {
			double temp_num = read_number(s, i);
			root_ptr->data = temp_num;
			build_tree(root_ptr->left_child(), s, i);
			build_tree(root_ptr->right_child(), s, i);
		}
	}
}

template<typename T>
void BinaryTree<T>::build_tree(TreeNode<T> *node, const std::string s, size_t i) {
	if (s[i] != '#') {
		double temp_num = read_number(s, i);
		node->data = data;
		build_tree(root_ptr->left_child(), s, i);
		build_tree(root_ptr->right_child(), s, i);
	} else {
		node = nullptr;
	}
}

template<typename T>
TreeNode<T> * BinaryTree<T>::root() {
	return root_ptr;
}

template<typename T>
T BinaryTree<T>::data(TreeNode<T> *node) {
	return node->data;
}

template<typename T>
double BinaryTree<T>::read_number(const std::string &s, size_t &i) {
	double ans = 0;
	while (isdigit(s[i])) {
		ans = ans * 10 + s[i] - '0';
		i++;
	}
	if (s[i] == '.') {
		int point = 0;
		i++;
		while (isdigit(s[i])) {
			ans = ans * 10 + s[i] - '0';
			i++;
			point++; // remember point pos
		}
		ans /= pow(10, point);
	}
	i--;
	return ans;
}

//template<typename T>
//double BinaryTree<T>::read_number(const std::string &s, size_t i) {
//	double ans = 0;
//	while (isdigit(s[i])) {
//		ans = ans * 10 + s[i] - '0';
//		i++;
//	}
//	if (s[i] == '.') {
//		int point = 0;
//		i++;
//		while (isdigit(s[i])) {
//			ans = ans * 10 + s[i] - '0';
//			i++;
//			point++; // remember point pos
//		}
//		ans /= pow(10, point);
//	}
//	// i--;
//	return ans;
//}


#endif //DS_TREE_BINARY_TREE_HPP
