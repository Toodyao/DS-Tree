#ifndef DS_SORT_COMPARE_H
#define DS_SORT_COMPARE_H

template <typename T>
class Compare {
public:
	virtual bool operator() (const T &x, const T &y)=0;
};

template <typename T>
class MyLess : public Compare<T>{
public:
	bool operator() (const T &x, const T &y) {
		return x < y;
	}
};

template <typename T>
class MyLessEqual : public Compare<T>{
public:
	bool operator() (const T &x, const T &y) {
		return x <= y;
	}
};

template <typename T>
class MyGreater : public Compare<T>{
public:
	bool operator() (const T &x, const T &y) {
		return x > y;
	}
};

template <typename T>
class MyGreaterEqual : public Compare<T>{
public:
	bool operator() (const T &x, const T &y) {
		return x >= y;
	}
};

#endif //DS_SORT_COMPARE_H
