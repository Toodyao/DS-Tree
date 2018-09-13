#ifndef DS_TREE_HEAP_HPP
#define DS_TREE_HEAP_HPP

#include <iostream>
#include <vector>
#include "compare.hpp"

using std::vector;

template <typename T>
class heap {
private:
	vector<T> v;
	Compare<T> *cmp;
	int heap_size;
	void percolate_down(int i);

public:
//	heap()
	explicit heap(int n, Compare<T> *cmp_t = new MyLess<T>);
	explicit heap(vector<T> a, Compare<T> *cmp_t = new MyLess<T>);
	~heap();
	bool empty();
	int size();
	T top();
	void push(T x);
	void pop();

};

template<typename T>
heap<T>::heap(int n, Compare<T> *cmp_t) {
	heap_size = 0;
	v.resize((unsigned int)n);
	cmp = cmp_t;
}

template<typename T>
heap<T>::heap(vector<T> a, Compare<T> *cmp_t) {
	// create heap using existing array
	int n = (int)a.size();
	v.resize((unsigned int)n);
	heap_size = n;
	cmp = cmp_t;

	// copy array
	for (int i = 0; i < n; i++) {
		v[i] = a[i];
	}

	for (int i = (n/2)-1; i >= 0; i--) {
		percolate_down(i);
	}

}

template<typename T>
heap<T>::~heap() {
	delete cmp;
}

template<typename T>
bool heap<T>::empty() {
	return (bool)heap_size;
}

template<typename T>
int heap<T>::size() {
	return heap_size;
}

template<typename T>
T heap<T>::top() {
	return v[0];
}

template<typename T>
void heap<T>::push(T x) {
	if (heap_size > v.size())
		std::cout << "heap full" << std::endl;
	int i = heap_size; // add to the last
	while (i > 0 && (*cmp)(x, v[(i-1)/2])) { // swap up
		v[i] = v[(i-1)/2];
		i = (i-1)/2;
	}
	v[i] = x;
	heap_size++;
}

template<typename T>
void heap<T>::pop() {
	// a little difference with percolate_down()
	int n = heap_size;
	int x = v[n-1]; // store the last element
	v[0]  = v[n-1]; // promote the last element to the top
	int parent, child;
	for (parent = 0; parent * 2 + 1 <= n - 1; parent = child) {
		child = parent*2+1;      // default left child
		if (child + 1 <= n - 1             // if has right child
			&& (*cmp)(v[child+1], v[child])) // select the largest child
			child++;

		// ... && v[child] < v[child+1]) -> max_heap
		// if (x >= v[child]) -> max_heap
		if ((*cmp)(x, v[child]) || v[child] == x) // found the proper place
			break;
		else
			v[parent] = v[child];  // swap down
	}
	v[parent] = x;
	v.pop_back();
	heap_size--;
}

template<typename T>
void heap<T>::percolate_down(int i) {
	int n = heap_size;
	int x = v[i]; // store current element
//	v[i] = v[n-1];
	int parent, child;
	for (parent = i; parent * 2 + 1 <= n - 1; parent = child) {
		child = parent*2+1;
		if (child + 1 <= n - 1
			&& (*cmp)(v[child+1], v[child]))  // using Compare
			child++;
		if ((*cmp)(x, v[child]) || v[child] == x) // using Compare
			break;
		else
			v[parent] = v[child];
	}
	v[parent] = x;
}

#endif //DS_TREE_HEAP_HPP
