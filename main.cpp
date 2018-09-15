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
	// freopen("input.txt", "r", stdin);

	string infix_exp, suffix_exp;
	string prefix_exp = "+ + 11 * 22 3 * + * 44 55 66 77";
	cout << "input prefix: " << prefix_exp << endl;
	stack<char> s;
	for (int i = prefix_exp.size() - 1; i >= 0; i--)
		s.push(prefix_exp[i]);
	infix_exp.clear();
	prefix_to_infix(s, infix_exp);
	// cout << infix_exp << endl;
	suffix_exp.clear();
	suffix_exp = infix_to_suffix(infix_exp);
	cout << "corresponding suffix: " << suffix_exp;
	TreeNode<string>* exp_tree_root = suffix_to_exp_tree(suffix_exp);
	ExpressTree<string> et(exp_tree_root);
	cout << "\nexpression tree: ";
	et.print_like_tree();
	cout << endl;
	cout << "prefix: ";
	et.pre_order_recursion(et.root());
	cout << endl;
	cout << "infix: ";
	et.in_order(et.root());
	cout << endl;
	cout << "suffix:";
	et.post_order_recursion(et.root());
	cout << endl;

	cout << "-----------------------" << endl;


	//getline(cin, infix_exp);
	infix_exp = "(11+22*3) + ((44*55 + 66)*77)";
	//infix_exp = "(3 + 4) * 5 - 6 ";
	cout << "input infix: ";
	cout << infix_exp << endl;
	suffix_exp = infix_to_suffix(infix_exp);
	cout << "corresponding suffix: " << suffix_exp << endl;
	exp_tree_root = suffix_to_exp_tree(suffix_exp);
//	BinaryTree<string> bt(exp_tree_root);
//	bt.level_order();
	et.reconstruct(exp_tree_root);
	cout << "\nexpression tree: ";
	et.print_like_tree();
	cout << endl;
	cout << "prefix: ";
	et.pre_order_recursion(et.root());
	cout << endl;
	cout << "infix: ";
	et.in_order(et.root());
	cout << endl;
	cout << "suffix: ";
	et.post_order_recursion(et.root());
	cout << endl;



	cout << "\n-----BST TEST------\n";
	int n;
	BinarySearchTree bst;
	while (cin >> n) {
		bst.insert(n);
	}
	cout << "level order: " << endl;
	bst.level_order();
	cout << "pre order: " << endl;
	bst.pre_order_recursion(bst.root());
	cout << "\nin order: " << endl;
	bst.in_order_recursion(bst.root());
	cout << "\npost order: " << endl;
	bst.post_order_recursion(bst.root());
	cout << endl;


	system("pause");
	return 0;
}
