#ifndef DS_TREE_BINARY_TREE_HPP
#define DS_TREE_BINARY_TREE_HPP

#include "tree_node.hpp"

template <typename T>
class BinaryTree : public TreeNode<T> {
private:
	TreeNode<T> *root_ptr;
public:
	BinaryTree();
	~BinaryTree();

	TreeNode<T> * root(TreeNode<T> * node);
	TreeNode<T> * left_child(TreeNode<T> * node);
	TreeNode<T> * right_child(TreeNode<T> * node);
	T data(TreeNode<T> * node);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root_ptr = nullptr;
}


#endif //DS_TREE_BINARY_TREE_HPP
