#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
#include <string>
#include "binary_tree.hpp"
#include "express_tree.hpp"
#include "expression_calculate.h"
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
	string infix_exp, suffix_exp;
	//getline(cin, infix_exp);
	infix_exp = "(11+22*3) + ((44*55 + 66)*77)";
	suffix_exp = infix_to_suffix(infix_exp);
	cout << suffix_exp << endl;
	TreeNode<string>* exp_tree_root = suffix_to_exp_tree(suffix_exp);
	BinaryTree<string> bt(exp_tree_root);
	bt.level_order();
	ExpressTree<string> et(exp_tree_root);
	et.print_like_tree();

//	cout << bt.get_tree_height(exp_tree_root) << endl;




	return 0;
}