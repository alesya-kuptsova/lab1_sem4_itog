#include "ArrayHashTable.h"

TabRecord* ArrayHashTable:: search (int k)
{
	pos = HashF(k) % size;
	freePos = -1;
		for (int i = 0; i < size; i++)
		{
			if (recs[pos] == 0)
				return 0;
			int tmp = recs[pos]->GetKey();
			if (tmp == k)
				return recs[pos];
			if ((recs[pos] == pMark) && (freePos == -1))
				freePos = pos;
			pos = getNextRes(pos, size);
		}
		return 0;
}

void ArrayHashTable::erase(int k)
{
	TabRecord *tmp = search(k);
	if (tmp == 0) 
		return;
	delete recs[pos];
	recs[pos] = pMark;
	count--;
}

void ArrayHashTable::insert(int k, TData * d)
{
	if (isFull())
		return;
	TabRecord *tmp = search(k);
	//if (freePos != -1)
	if (tmp==0)
	{
		freePos = pos;
		recs[pos] = new TabRecord(k, d);
	}
}

int ArrayHashTable:: getNextRes(int r, int size) const
{
	return (r + hashStep) % size;
}