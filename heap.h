#ifndef DS_SORT_HEAP_H
#define DS_SORT_HEAP_H

#include <iostream>
#include <vector>
#include "compare.hpp"

using std::vector;

class Heap {
private:
	vector<int> v;
	int heap_size;
	Compare<int> *cmp;
	void percolate_down(int i);
public:
//	Heap()
	Heap(int n, Compare<int> *cmp_t = new MyLess<int>);
	Heap(vector<int> a, Compare<int> *cmp_t = new MyLess<int>);
//	Heap();
	bool empty();
	int size();
	int top();
	void push(int x);
	void pop();

};


#endif //DS_SORT_HEAP_H
