#include <iostream>
#include <cstdio>
#include "binary_tree.hpp"
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	BinaryTree<int> t;
	string s;

	TreeNode<int> temp(5);
	TreeNode<int> temp2(4);
	t.root()->set_data(1);
	t.root()->add_left(&temp);
	t.root()->add_right(&temp2);
	t.post_order(t.root());


	return 0;
}