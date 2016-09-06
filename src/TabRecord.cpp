
#include "TabRecord.h"

TabRecord::TabRecord()
{
	key = 0;
	data = 0;
}

TabRecord::~TabRecord()
{
	delete data;
}

TabRecord::TabRecord(int k, TData * d)
{
	key = k;
	data = d;
}

int TabRecord::GetKey(void) const
{
	return key;
}

TData * TabRecord::GetData(void) const
{
	return data;
}

TabRecord& TabRecord::operator=(const TabRecord & t)
{
	key = t.key;
	data = new TData(t.GetData()->Name);
	return *this;
}

int TabRecord:: operator== (const TabRecord &t) const
{
	return key == t.key;
}

int TabRecord:: operator!= (const TabRecord &t) const
{
	return key != t.key;
}

int TabRecord:: operator> (const TabRecord &t) const
{
	return key > t.key;
}

int TabRecord:: operator< (const TabRecord &t) const
{
	return key < t.key;
}

int TabRecord:: operator>= (const TabRecord &t) const
{
	return key >= t.key;
}

int TabRecord:: operator<= (const TabRecord &t) const
{
	return key <= t.key;
}