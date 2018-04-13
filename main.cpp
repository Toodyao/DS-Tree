#include <iostream>
#include <cstdio>
#include "binary_tree.hpp"
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	BinaryTree<double> t;
	string s;
	cin >> s;
	t.build_tree_from_string(s);


	return 0;
}