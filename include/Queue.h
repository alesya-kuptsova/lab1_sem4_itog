#pragma once
#include "dKucha.h"
#include "BinTree.h"
#include "Sortable.h"

template <class T>
class PriorQueue
{
public:
	PriorQueue(void) {};
	virtual ~PriorQueue() {};
	virtual void Push(const T) = 0; 
	virtual void Pop() = 0;
	virtual int IsEmpty() = 0;
	virtual int GetSize() = 0;
	virtual T Top() = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class QKucha : public PriorQueue<T>
{
private:
	dKucha* h;
public:
	QKucha(int);
	QKucha(int dim, double *mas);
	QKucha();
	virtual ~QKucha() { delete h; }
	void Push(const T);
	void Pop();
	T Top();
	int IsEmpty();
	virtual int GetSize() { return h->GetCount(); };
};

template <class T>
QKucha<T>:: QKucha (int dim)
{
	if (dim < 0)
		throw dim;
	h= new dKucha(dim, 3);
}

template <class T>
QKucha<T>::QKucha(int dim, double *mas)
{
	if (dim < 0)
		throw dim;
	h = new dKucha(dim, 3, mas);
	h->Sorting();
}

template <class T>
QKucha<T>::QKucha()
{
	h = new dKucha();
}

template  <class T>
void QKucha<T>::Pop()
{
	if (IsEmpty())
		throw -1; 
	h->RemoveMin();
	h->Delete(0);
}

template <class T>
void QKucha <T> :: Push(const T x)
{
	h->Insert(x);
	h->Push();
	h->Sorting();
}

template <class T>
int QKucha <T> ::IsEmpty()
{
	return h->GetCount() == 0;
};

template <class T>
T QKucha <T>::Top()
{
	if (IsEmpty())
		throw -1;
	else return h->GetKey(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class QTree : public PriorQueue <T>
{
private:
	BinSearch<T> *tree;
public:
	QTree()
	{
		tree = new BinSearch<T>;
	}

	virtual ~QTree() 
	{
		delete tree;
	};

	virtual void Push(const T x)
	{
		Node<T> *tmp = new Node<T>(x);
		tree->Push(tree->root, tmp);
	}

	virtual void Pop()
	{
		tree->Remove(tree->root, tree->FindMin()->key);
		//size--;
	}

	virtual int IsEmpty()
	{
		return tree->GetSize() == 0; 
	};

	virtual T Top()
	{
		//return tree->root->balance;
		return tree->FindMin()->key;
	};

	virtual int GetSize() 
	{
		return tree->GetSize();
	};
	//int operator==(const Queue_on_tree<T>&)const;
};

//template <class T>
//int QTree<T>::operator==(const Queue_on_tree<T>& newtree)const
//{
//	return *tree == *newtree.tree;
//}

template <class T>
class QTable : public PriorQueue <T>
{
private:
	Sortable* table;
	int s;
public:
	QTable(int);
	QTable(int, double*);
	~QTable();
	void Push(T);
	void Pop();
	T Top();
	int IsEmpty();
	int GetSize();
};

template <class T>
QTable<T> :: QTable(int x)
{
	if (x < 0)
		throw x; 
	table = new Sortable(x);
	s = 0;
}

template <class T>
QTable<T> ::QTable(int x, double* E)
{
	if (x < 0)
		throw x;
	table = new Sortable(x, E);
	s = 0;
}

template <class T>
QTable<T>::~QTable()
{
	delete table;
}

template <class T>
void QTable<T>::Push(T x)
{
	char str[10];
	sprintf_s(str, "%f", (float)x);
	table->insert(s, new TData(str));
	table->Sorting();
	s++; 
}

template <class T>
void QTable<T>::Pop()
{
	if (IsEmpty())
		throw - 1;
	table->erase(table->Min()->GetKey());
	s--;
	table->Sorting();
}

template <class T>
T QTable<T>::Top()
{
	char *str = table->Min()->GetData()->Name;
	float val;
	sscanf_s(str, "%f", &val);
	return val;
}

template <class T>
int QTable<T>::GetSize()
{
	return table->GetCount();
}

template <class T>
int QTable<T>::IsEmpty()
{
	if (table->GetCount() == 0)
		return 1;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

template <class T>
class CreateQ
{
public:
	static bool Create(PriorQueue<T>*&, const int, const int, double *E);
};

template <class T>
bool CreateQ<T>::Create(PriorQueue<T>*& q, const int a, const int b, double *E)
{
	if (a == 1) // куча
	{
		q = new QKucha<T>(b, E);
		return true;
	}
	if (a == 2) // дерево
	{
		q = new QTree<T>();
		for (int i = 0; i<b;i++)
				q->Push(E[i]);// надо пушить вес и-того ребра
		return true;
	}
	if (a == 3) //таблицы
	{
		q = new QTable<T>(b, E);
		return true;
	}
	return false;
}