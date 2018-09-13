#include <iostream>
#include <queue>
#include <vector>
#include "heap.hpp"
using namespace std;

int main() {
	int n = 10;
//	vector<int> v;
//	for (int i = 0; i < n; i++) {
//		v.push_back(i);
//	}
	heap<int> h(n, new MyGreater<int>);
	for (int i = 0; i < n; i++) {
		h.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << h.top() << endl;
		h.pop();
	}


	return 0;
}

