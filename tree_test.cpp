//#include "my_vector.hpp"
#include <iostream>
#include <vector>
#include "binary_tree.hpp"
// using namespace std;

int main()
{
	BinaryTree<int> b;
	b.set_data(0);
	b.add_left(1).add_left(3).add_left(4);
	b.add_right(2);
	b.level_order();
	b.in_order();


	return 0;
}

