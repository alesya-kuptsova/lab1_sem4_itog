#pragma once
#include "HashTable.h"

class ArrayHashTable: public HashTable
{
protected:
	TabRecord **recs;
	int freePos;
	int hashStep;
	TabRecord *pMark; // - маркер удаленной
	int getNextRes(int, int) const;

public:
	ArrayHashTable(int size, int hashStep) : HashTable(size) 
	{
		this->hashStep = hashStep;
		recs = new TabRecord *[size];
		for (int i = 0; i < size; i++)
			recs[i] = 0;
		pMark = new TabRecord(-1, 0);
	}
	virtual TabRecord* search(int); // - поиск
	virtual void erase(int); // - удаление
	virtual void insert(int, TData*); // - вставка
	void reset() {};
	void GetNext() {};
};


