#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
#include <string>
#include "express_tree.hpp"
#include "expression_calculate.h"
#include "binary_search_tree.h"
using namespace std;

int main() {
	//freopen("../input.txt", "r", stdin);
	string infix_exp, suffix_exp;
	//getline(cin, infix_exp);
	infix_exp = "(11+22*3) + ((44*55 + 66)*77)";
	cout << "输入中缀：";
	cout << infix_exp << endl;
	suffix_exp = infix_to_suffix(infix_exp);
	cout << "对应后缀：" << suffix_exp << endl;
	TreeNode<string>* exp_tree_root = suffix_to_exp_tree(suffix_exp);
//	BinaryTree<string> bt(exp_tree_root);
//	bt.level_order();
	ExpressTree<string> et(exp_tree_root);
	cout << "\n表达树：" << endl;
	et.print_like_tree();
	cout << endl;
	cout << "前缀：";
	et.level_order();
	cout << "中缀：";
	et.in_order(et.root());
	cout << endl;
	cout << "后缀：";
	et.post_order(et.root());
	cout << endl;
	string prefix_exp = "+ + * 11 * + 77 22 3 * 66 44 55";
//	cout << "\n-----BST TEST------\n";
//	int n;
//	BinarySearchTree bst;
//	while (cin >> n) {
//		bst.insert(n);
//	}
//	cout << "level order:" << endl;
//	bst.level_order();
//	cout << "pre order:" << endl;
//	bst.pre_order(bst.root());
//	cout << "\nin order:" << endl;
//	bst.in_order(bst.root());
//	cout << "\npost order:" << endl;
//	bst.post_order(bst.root());

	system("pause");
	return 0;
}