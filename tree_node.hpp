#ifndef DS_TREE_TREE_NODE_HPP
#define DS_TREE_TREE_NODE_HPP

template <typename T>
class TreeNode {
protected:
	T data;
	TreeNode *lchild;
	TreeNode *rchild;
	TreeNode *parent;

	TreeNode();
	explicit TreeNode(T d);
	TreeNode(T d, TreeNode *l, TreeNode *r);
	TreeNode(T d, TreeNode *l, TreeNode *r, TreeNode *p);
};

template<typename T>
TreeNode<T>::TreeNode() :
		lchild(nullptr), rchild(nullptr), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d) :
		data(d), lchild(nullptr), rchild(nullptr), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode *l, TreeNode *r) :
		data(d), lchild(l), rchild(r), parent(nullptr) { }

template<typename T>
TreeNode<T>::TreeNode(T d, TreeNode *l, TreeNode *r, TreeNode *p) :
		data(d), lchild(l), rchild(r), parent(p) { }


#endif //DS_TREE_TREE_NODE_HPP
