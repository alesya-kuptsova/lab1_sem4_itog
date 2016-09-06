#pragma once
#include <string.h>

struct TData
{
	char Name[16];
	TData(char*s)
	{
		//strcpy(Name, s);
		int i;
		for (i = 0; s[i] != 0; i++)
		{
			Name[i] = s[i];
		}
		Name[i] = 0;
	}
};

class TabRecord
{
protected:
	int key;
	TData *data;

public:
	TabRecord();
	~TabRecord();
	TabRecord(int, TData*);
	int GetKey(void) const;
	TData * GetData(void) const;
	TabRecord& operator= (const TabRecord &tab);
	int operator== (const TabRecord &tab) const;
	int operator!= (const TabRecord &tab) const;
	int operator> (const TabRecord &tab) const;
	int operator< (const TabRecord &tab) const;
	int operator>= (const TabRecord &tab) const;
	int operator<= (const TabRecord &tab) const;
};

