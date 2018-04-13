#include <iostream>
#include "my_stack.hpp"
using namespace std;

int main() {
	Mystack<int> s;
	s.push(1);
	s.print();

	return 0;
}