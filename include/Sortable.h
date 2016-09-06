#pragma once
#include "ScanTable.h"

class Sortable :
	public ScanTable
{
public:
	Sortable();
	Sortable(int Size);
	Sortable(int Size, double* E);
	Sortable(ScanTable&);
	~Sortable();
	virtual void insert(int key, TData* data);
	virtual void erase(int key);
	void Sorting();
	TabRecord * Min();
	void Print();
};

