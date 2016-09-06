// Tables.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Sortable.h"
#include <iostream>
using namespace std;
int main()
{
	Sortable A(10);
	A.Insert(2, new TData("муму1"));
	A.Insert(4, new TData("муму2"));
	A.Insert(3, new TData("муму3"));

	TabRecord*d= A.Search(4);
	cout<< d->GetData()->Name<<endl;
    return 0;
}

