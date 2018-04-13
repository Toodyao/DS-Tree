#ifndef DS_TREE_TREE_NODE_HPP
#define DS_TREE_TREE_NODE_HPP

template <typename T>
class TreeNode {
private:
	T data;
	TreeNode<T> *lchild;
	TreeNode<T> *rchild;
	TreeNode<T> *parent;

public:
	TreeNode();
	explicit TreeNode(T d);
	TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r);
	TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r, TreeNode<T> *p);

//	inline TreeNode<T> *root();
	inline TreeNode<T> *left_child();
	inline TreeNode<T> *right_child();

	inline void add_left(TreeNode<T> *t);
	inline void add_right(TreeNode<T> *t);

	inline T get_data();
	inline void set_data(T d);
};

template<typename T>
TreeNode<T>::TreeNode() :
		lchild(nullptr), rchild(nullptr), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d) :
		data(d), lchild(nullptr), rchild(nullptr), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r) :
		data(d), lchild(l), rchild(r), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r, TreeNode<T> *p) :
		data(d), lchild(l), rchild(r), parent(p) { }

template<typename T>
TreeNode<T> * TreeNode<T>::left_child() {
	return lchild;
}

template<typename T>
TreeNode<T> * TreeNode<T>::right_child() {
	return rchild;
}

template<typename T>
T TreeNode<T>::get_data() {
	return data;
}

template<typename T>
void TreeNode<T>::set_data(T d) {
	d = data;
}

template<typename T>
void TreeNode<T>::add_left(TreeNode<T> *t) {
	lchild = t;
}

template<typename T>
void TreeNode<T>::add_right(TreeNode<T> *t) {
	rchild = t;
}


#endif //DS_TREE_TREE_NODE_HPP
