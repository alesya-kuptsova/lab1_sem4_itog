#pragma once
#include "Table.h"

class HashTable:
	public Table
{
public:
	HashTable(int size) : Table (size) {}
protected: 
	virtual unsigned long HashF (int key) const;
};

