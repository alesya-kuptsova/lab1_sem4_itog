#include "..\include\Sortable.h"

#include "Sortable.h"
#include <stdio.h>


Sortable::Sortable()
{
}

Sortable::Sortable(int size)
	: ScanTable(size)
{

}

Sortable::Sortable(int Size, double * E)
	: ScanTable(Size, E)
{
	Sorting();
//	Print();
}

Sortable::Sortable(ScanTable &)
{
}


Sortable::~Sortable()
{
}

void Sortable::insert(int k, TData * d)
{
	if (isFull())
		return;
	search(k);
	for (int i = count + 1; i >= pos + 1;i--)
		recs[i] = recs[i - 1];
	count++;
	recs[pos] = new TabRecord(k, d);
}

void Sortable::Sorting()
{
	TabRecord *tmp;
	for (int i = 0; i < count-1; i++)
		for (int j = 0; j < count-1-i; j++)
	{
		if (recs[j]->GetKey() > recs[j+1]->GetKey())
		{
			tmp = recs[j];
			recs[j] = recs[j+1];
			recs[j+1] = tmp;
		}
	}
}

void Sortable::erase(int key)
{
	//если поиск не дал результатов
	if (search(key) == 0)
		return;
	delete recs[pos];
	recs[pos] = recs[count - 1];
	count--;
}

TabRecord * Sortable::Min()
{
	return recs[0];
}

void Sortable::Print()
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", recs[i]->GetKey());
	}
	printf("\n");
}
