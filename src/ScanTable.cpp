
#include "ScanTable.h"
#include <stdio.h>

ScanTable::ScanTable()
{
}

ScanTable::ScanTable(int size): Table (size)
{
	recs = new TabRecord*[size];
}

ScanTable::ScanTable(int size, double *E) : Table(size)
{
	char boof[16];
	recs = new TabRecord*[size];
	for (int i = 0; i < size; i++)
	{
		sprintf_s(boof, "%f", E[i]);
		this->insert((int)E[i], new TData(boof));
	}
}


ScanTable::~ScanTable()
{
}

TabRecord * ScanTable::search(int key)
{
	for (int i = 0; i < count; i++)
	{
		if (key == recs[i]->GetKey())
		{
			pos = i;
			return recs[i];
		}
	}
	return nullptr;
}

void ScanTable::insert(int k, TData * d)
{
	if (isFull())
		throw k;
	recs[count] = new TabRecord(k, d);
	count++;
}

void ScanTable::erase(int key)
{
	if (isEmpty())
		throw key;
	//если поиск не дал результатов
	if (search(key) == 0)
		return;
	delete recs[key];
	recs[key] = recs[count - 1];
	count--;
}
