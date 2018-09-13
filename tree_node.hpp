#ifndef DS_TREE_TREE_NODE_HPP
#define DS_TREE_TREE_NODE_HPP

template <typename T>
class TreeNode {
public:
	T _data;
	TreeNode<T> *lchild;
	TreeNode<T> *rchild;
	TreeNode<T> *parent;

	TreeNode();
	explicit TreeNode(T d);
	TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r);
	TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r, TreeNode<T> *p);

	virtual ~TreeNode();

//	inline TreeNode<T> *root();
	inline TreeNode<T> * left_child();
	inline TreeNode<T> * right_child();

	virtual inline void add_left(TreeNode<T> *t);
	virtual inline void add_right(TreeNode<T> *t);
	virtual inline void add_left(T d);
	virtual inline void add_right(T d);

	inline T get_data();
	inline void set_data(T d);
};

template<typename T>
TreeNode<T>::TreeNode() :
		lchild(nullptr), rchild(nullptr), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d) :
		_data(d), lchild(nullptr), rchild(nullptr), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r) :
		_data(d), lchild(l), rchild(r), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r, TreeNode<T> *p) :
		_data(d), lchild(l), rchild(r), parent(p) { }

template<typename T>
TreeNode<T>::~TreeNode() {
	// Nothing to do
}

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
	return _data;
}

template<typename T>
void TreeNode<T>::set_data(T d) {
	_data = d;
}

template<typename T>
void TreeNode<T>::add_left(TreeNode<T> *t) {
	lchild = t;
}

template<typename T>
void TreeNode<T>::add_right(TreeNode<T> *t) {
	rchild = t;
}

template<typename T>
void TreeNode<T>::add_left(T d) {
	lchild = new TreeNode(d);
}

template<typename T>
void TreeNode<T>::add_right(T d) {
	rchild = new TreeNode(d);
}


#endif //DS_TREE_TREE_NODE_HPP
