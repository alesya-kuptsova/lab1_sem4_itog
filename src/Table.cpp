
#include "Table.h"

Table::Table()
{
	size = 0;
	count = 0;
	pos = 0;
}

Table::Table(int s)
{
	size = s;
	count = 0;
	pos = 0;
}

int Table::isEmpty(void) const
{
	return count==0;
}

int Table::isFull(void) const
{
	return count==size;
}

Table::~Table()
{
	
}
int Table::GetCount(void)
{
	return count;
}
