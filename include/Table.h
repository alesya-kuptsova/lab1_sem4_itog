#pragma once
#include "TabRecord.h"

class Table
{
protected:
	int size;
	int count;
	int pos;
public:
	Table();
	~Table();
	Table(int);
	virtual TabRecord *search(int) = 0;
	virtual void insert(int, TData*) = 0;
	virtual void erase(int) = 0;
	int isEmpty(void) const;
	int isFull(void) const;
	int GetCount();
	/*int SetCount(void) const;*/
};

