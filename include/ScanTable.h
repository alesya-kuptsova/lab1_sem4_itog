#pragma once
#include "Table.h"
class ScanTable :
	public Table
{
protected:
	TabRecord **recs;
public:
	ScanTable();
	ScanTable(int);
	ScanTable(int, double*);
	~ScanTable();
	virtual TabRecord*search(int key);
	virtual void insert (int, TData*);
	virtual void erase (int key);
};

