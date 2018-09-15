#ifndef DS_TREE_BINARY_SEARCH_TREE_H
#define DS_TREE_BINARY_SEARCH_TREE_H

#include "binary_tree.hpp"

class BinarySearchTree : public BinaryTree<int> {
private:
	typedef TreeNode<int> TN;
//	TN *root_node;
	TN* find_min_recursion(TN* node);
	TN* find_max_recursion(TN* node);

	TN* insert_recursion(int n, TN* node);
	TN* del_recursion(int n, TN* node);
public:
	BinarySearchTree();
	void insert(int n);
	void del(int n);
	TN* find_min();
	TN* find_max();

};


#endif //DS_TREE_BINARY_SEARCH_TREE_H
