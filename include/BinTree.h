#include <iostream>
#include <queue>
#include <stack>

using namespace std;


template <class T>
class Node
{
public:
	int balance;
	T key;
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;
	Node() { left = NULL; right = NULL; parent = NULL; balance = 0; };
	Node(const T& k) { key = k; left = NULL; right = NULL; parent = NULL; balance = 0; };
};

template <class T>
class BinSearch
{
public:
	int size;
	Node<T> *root;

	BinSearch();
	~BinSearch();
	void DelNode(Node<T>*);
	BinSearch(const BinSearch<T> &);
	int operator==(const BinSearch<T>&) const;

	Node<T>* Copy(Node<T> *);
	virtual void Push(Node<T>*&, const Node<T> *);

	virtual void Remove(Node<T>*&, const T &);
	Node<T>* FindKey(Node<T>*, const T &);
	Node<T>* FindMax(Node<T>*);
	Node<T>* FindMin(Node<T>*);
	Node<T>* FindMin();
	Node<T>* FindNext(Node<T>*, Node<T>*);
	Node<T>* FindPrev(Node<T>*, Node<T>*);//найти предыдущий
	void BypasWide(Node<T>*); //обход в ширину
	void BypasForward(Node<T>*);
	void BypasReverse(Node<T>*);
	void BypasSymmetric(Node<T>*);
	void BypasDepth(Node<T>*);
	
	int GetSize();
	int GetHeight(Node<T>*);
};

template <class T>
BinSearch<T>::BinSearch()
{
	root = NULL;
	size = 0;
};

template <class T>
BinSearch<T>::~BinSearch()
{
	if (root != 0)
		DelNode(root);
}

template <class T>
void BinSearch<T>::DelNode(Node<T>*r)
{
	if (r->left != 0)
	{
		DelNode(r->left);
	}
	if (r->right != 0)
	{
		DelNode(r->right);
	}
	delete r;
}

;

template <class T>
BinSearch<T>::BinSearch(const BinSearch<T> &tree)
{
	root = Copy(tree.root);
	size = tree.size;
};

template <class T>
Node<T>* BinSearch<T>::Copy(Node<T> *newroot)
{
	if (newroot == NULL)
		return NULL;
	Node<T>* l = Copy(newroot->left);
	Node<T>* r = Copy(newroot->right);
	Node<T>* newtree = new Node<T>;
	newtree->key = newroot->key;
	newtree->left = l;
	newtree->right = r;
	root = newtree;
	return newtree;
};

template <class T>
void BinSearch<T>::Push(Node<T>* &tree, const Node<T> *node)
{
	T newkey = node->key;
	if (tree == NULL)
	{
		tree = new Node<T>;
		tree->key = newkey;
		size++;
		return;
	}

	Node<T>* tmp = tree;
	Node<T>* previous = new Node<T>;
	while (tmp != NULL)
	{
		previous = tmp;
		if (tmp->key <= newkey)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (previous->key <= newkey)
	{
		previous->right = new Node<T>(newkey);
		previous->right->parent = previous;
	}
	else
	{
		previous->left = new Node<T>(newkey);
		previous->left->parent = previous;
	}
	size++;
};

template <class T>
void BinSearch<T>::Remove(Node<T>*& tree, const T &k)
{
	Node<T>* x = FindKey(tree, k);
	if (x == NULL)
		//return;
		throw
		exception("Key doesn't exist"); //test

	if ((x->left == NULL) && (x->right == NULL))
	{
		if (x->parent != 0)
		{
			if (x->parent->left == x)
				x->parent->left = 0;
			if (x->parent->right == x)
				x->parent->right= 0;
		}
		if (tree == x)
			tree = 0;
		delete x;
		size--;
		return;
	}

	if ((x->left == NULL) && (x->right != NULL))
	{
		Node<T>* y = x->right;
		y->parent = x->parent;
		if (x->parent == NULL)
		{
			tree = y;
			size--;
			return;
		}
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		if(x==tree)
			tree = y;
		size--;
		return;
	}
	if ((x->left != NULL) && (x->right == NULL))
	{
		Node<T>* y = x->left;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		size--;
		return;
	}
	Node<T>* y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	if (y->right != NULL)
		y->right->parent = y->parent;
	delete y;
	size--;
};

template <class T>
Node<T>* BinSearch<T>::FindKey(Node<T> *tree, const T &k)
{
	while ((tree != NULL) && (tree->key != k))
	{
		if (k < tree->key)
			tree = tree->left;
		if (k > tree->key)
			tree = tree->right;
	}
	return tree;
};

template <class T>
Node<T>* BinSearch<T>::FindMin(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty");
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
};

template <class T>
Node<T>* BinSearch<T>::FindMin()
{
	return FindMin(root);
}

template <class T>
Node<T>* BinSearch<T>::FindMax(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
};

template <class T>
Node<T>* BinSearch<T>::FindNext(Node<T> *tree, Node<T> *node)
{
	if (tree == NULL)
		throw
		exception("Tree is empty");
	if (node == NULL)
		throw
		exception("Node is empty"); 

	node = FindKey(tree, node->key);
	if (node->right != NULL)
		return FindMin(node->right);
	while ((node->parent != NULL) && (node->parent->right == node))
		node = node->parent;
	if (node->parent == NULL)
		throw
		exception("Parent doesn't exist");
	return node->parent;
};

template <class T>
Node<T>* BinSearch<T>::FindPrev(Node<T> *tree, Node<T> *node)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	if (node == NULL)
		throw
		exception("Node is empty"); 
	node = FindKey(tree, node->key);
	if (node->right != NULL)
		return FindMax(node->left);
	while ((node->parent != NULL) && (node->parent->left == node))
		node = node->parent;
	if (node->parent == NULL)
		throw
		exception("Parent doesn't exist"); 
	return node->parent;
}

template <class T>
void BinSearch<T>::BypasWide(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	queue <Node<T>*> q;
	q.push(tree);
	while (q.empty() == 0)
	{
		Node<T>* tmp = q.front();
		//cout << tmp->key << '(' << tmp->balance << ')';
		q.pop();
		if (tmp->left != NULL)
			q.push(tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
	}
}

template <class T>
void BinSearch<T>::BypasDepth(Node<T> *tree)
{
	if (tree == NULL)
		//return;
		throw
		exception("Tree is empty"); 
	stack<Node<T>*> s;
	s.push(tree);
	while (!s.empty())
	{
		Node<T>* tmp = s.top();
		//cout << tmp->key << '(' << tmp->balance << ')';
		s.pop();
		if (tmp->right != NULL)
			s.push(tmp->right);
		if (tmp->left != NULL)
			s.push(tmp->left);
	}
}

template <class T>
void BinSearch<T>::BypasForward(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	//cout << tree->key << '(' << tree->balance << ')';
	if(tree->left!=0)
		BypasForward(tree->left);
	if (tree->right!=0)
		BypasForward(tree->right);
}

template <class T>
void BinSearch<T>::BypasSymmetric(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty");
	if (tree->left != 0)
	BypasSymmetric(tree->left);
   //	cout << tree->key << '(' << tree->balance << ')';
	if (tree->left != 0)
	BypasSymmetric(tree->right);
}

template <class T>
void BinSearch<T>::BypasReverse(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	if (tree->left != 0)
	BypasReverse(tree->left);
	if (tree->left != 0)
	BypasReverse(tree->right);
	// cout << tree->key << '(' << tree->balance << ')';
}

template <class T>
int BinSearch<T>::operator==(const BinSearch<T>& tree)const
{
	if ((root == NULL) && (tree.root == NULL))
		return 1;
	if (size != tree.size)
		return 0;
	int *z = new int[size];
	int *b = new int[tree.size];
	queue <Node<T>*> q;
	queue <Node<T>*> p;
	q.push(root);
	int tmp1 = 0;
	int tmp2 = 0;
	while (q.empty() == 0)
	{
		Node<T>* tmp = q.front();
		z[tmp1] = tmp->key;
		q.pop();
		if (tmp->left != NULL)
			q.push(tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
		tmp1++;
	}
	p.push(tree.root);
	while (p.empty() == 0)
	{
		Node<T>* tmp3 = p.front();
		b[tmp2] = tmp3->key;
		p.pop();
		if (tmp3->left != NULL)
			p.push(tmp3->left);
		if (tmp3->right != NULL)
			p.push(tmp3->right);
		tmp2++;
	}
	for (int i = 0; i<size; i++)
		if (z[i] != b[i])
			return 0;
	return 1;
}

template <class T>
int BinSearch<T>::GetSize()
{
	return size;
}

template <class T>
int BinSearch<T>::GetHeight(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty")
		int l, r;
	if (tree->left != NULL)
	{
		l = GetHeight(tree->left);
	}
	else
		l = -1;
	if (tree->right != NULL)
	{
		r = GetHeight(tree->right);
	}
	else
		r = -1;
	int max = l > r ? l : r;
	return max + 1;
};

//#include <stdio.h>
//struct Znach; // опережающее объявление
//
//typedef int TKey;   // тип ключа
//typedef int TValue; // тип значения
//
//typedef int(*keyCompareFuncPointer)(TKey, TKey); // указатель на функцию сравнения ключей
//												 //typedef int (*valueCompareFuncPointer) (TValue, TValue); // // указатель на функцию сравнения значения
//typedef void(*outNodeFuncPointer) (struct Znach *);
//
//struct Znach
//{
//	TKey key;
//	TValue value;
//};
//
//struct Node
//{
//	struct Znach znach;
//	struct Node *left;  // левое поддерево (для меньших значений)
//	struct Node *right; // правое поддерево (для бОльших значений)
//};
//
///* Znach_has_key() проверяет имеется ли в словаре ключ key
//в случае отсутствия такового возвращает NULL,
//иначе структуру Znach, содержащий искомый ключ */
//
//struct Znach * znach_has_key(struct Node *rootNode, TKey key);
//TValue znach_get_value(TKey key);                 // возвращает значение по ключу
//												  /* znach_insert() вставляет в словарь новую запись.
//												  В случае, если ключ key уже имеется в словаре, то просто обновляется его value */
//int znach_insert(struct Node **rootNode, TKey key, TValue value);
///* удаляет элемент словаря по ключу. Возвращает 0 в случае успеха*/
//int znach_delete(struct Node ** const rootNode, TKey key);