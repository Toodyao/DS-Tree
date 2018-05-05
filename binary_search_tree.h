#ifndef DS_TREE_BINARY_SEARCH_TREE_H
#define DS_TREE_BINARY_SEARCH_TREE_H

#include "tree_node.hpp"

class BinarySearchTree {
private:
	typedef TreeNode<int> TN;
	TN *root;
	BinarySearchTree::TN *find_min_recursion(TN *node);
	BinarySearchTree::TN *find_max_recursion(TN *node);
public:
	BinarySearchTree ();
	void insert(int n);
	void del(int n);
	BinarySearchTree::TN *find_min();
	BinarySearchTree::TN *find_max();

};


#endif //DS_TREE_BINARY_SEARCH_TREE_H
