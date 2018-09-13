#include "my_vector.hpp"
#include <iostream>
#include <vector>
#include "binary_tree_better.hpp"
// using namespace std;

int main()
{
	BinaryTree<int> b;
	b.set_data(0);
	b.add_left(1);
	b.add_right(2);
	b.get_left()->add_left(3);
	b.level_order();
	b.in_order(&b);


	return 0;
}

