#ifndef DS_TREE_TREE_NODE_HPP
#define DS_TREE_TREE_NODE_HPP

template<typename T>
class TreeNode {
public:
	T _data;
	TreeNode<T>* lchild;
	TreeNode<T>* rchild;
	TreeNode<T>* parent;

	TreeNode();
	explicit TreeNode(T d);
	TreeNode(T d, TreeNode<T>* l, TreeNode<T>* r);
	TreeNode(T d, TreeNode<T>* l, TreeNode<T>* r, TreeNode<T>* p);

	virtual ~TreeNode();

//	inline TreeNode<T> *root();
	inline TreeNode<T>* left_child_pointer();
	inline TreeNode<T>* right_child_pointer();
	inline TreeNode<T>& left_child();
	inline TreeNode<T>& right_child();

	virtual inline TreeNode<T>& add_left(TreeNode<T>* t);
	virtual inline TreeNode<T>& add_right(TreeNode<T>* t);
	virtual inline TreeNode<T>& add_left(T d);
	virtual inline TreeNode<T>& add_right(T d);

	inline T data();
	inline void set_data(T d);
};

template<typename T>
TreeNode<T>::TreeNode() :
		lchild(nullptr), rchild(nullptr), parent(nullptr) {}

template<typename T>
TreeNode<T>::TreeNode(T d) :
		_data(d), lchild(nullptr), rchild(nullptr), parent(nullptr) {}

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode<T>* l, TreeNode<T>* r) :
		_data(d), lchild(l), rchild(r), parent(nullptr) {}

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode<T>* l, TreeNode<T>* r, TreeNode<T>* p) :
		_data(d), lchild(l), rchild(r), parent(p) {}

template<typename T>
TreeNode<T>::~TreeNode() {
	// Nothing to do
}

template<typename T>
TreeNode<T>* TreeNode<T>::left_child_pointer() {
	return lchild;
}

template<typename T>
TreeNode<T>* TreeNode<T>::right_child_pointer() {
	return rchild;
}

template<typename T>
TreeNode<T>& TreeNode<T>::left_child() {
	return *lchild;
}

template<typename T>
TreeNode<T>& TreeNode<T>::right_child() {
	return *rchild;
}

template<typename T>
T TreeNode<T>::data() {
	return _data;
}

template<typename T>
void TreeNode<T>::set_data(T d) {
	_data = d;
}

template<typename T>
TreeNode<T>& TreeNode<T>::add_left(TreeNode<T>* t) {
	lchild = t;
	return *t;
}

template<typename T>
TreeNode<T>& TreeNode<T>::add_right(TreeNode<T>* t) {
	rchild = t;
	return *t;
}

template<typename T>
TreeNode<T>& TreeNode<T>::add_left(T d) {
	lchild = new TreeNode(d);
	return *lchild;
}

template<typename T>
TreeNode<T>& TreeNode<T>::add_right(T d) {
	rchild = new TreeNode(d);
	return *rchild;
}


#endif //DS_TREE_TREE_NODE_HPP
