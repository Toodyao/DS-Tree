#ifndef DS_SORT_HEAP_H
#define DS_SORT_HEAP_H

#include <iostream>
#include <vector>
#include "compare.hpp"

using std::vector;

class heap {
private:
	vector<int> v;
	int heap_size;
	Compare<int> *cmp;
	void percolate_down(int i);
public:
//	heap()
	heap(int n, Compare<int> *cmp_t = new MyLess<int>);
	heap(vector<int> a, Compare<int> *cmp_t = new MyLess<int>);
//	~heap();
	bool empty();
	int size();
	int top();
	void push(int x);
	void pop();

};


#endif //DS_SORT_HEAP_H
