#include <iostream>
#include <cstdio>
#include "binary_tree.hpp"
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	BinaryTree<int> t;
	string s;

	TreeNode<int> temp(2);
	TreeNode<int> temp2(3);
	t.root()->set_data(1);
	t.root()->add_left(&temp);
	t.root()->add_right(&temp2);
	temp.add_right(5);
	t.post_order(t.root());
//	t.delete_subtree(t.root());


	return 0;
}