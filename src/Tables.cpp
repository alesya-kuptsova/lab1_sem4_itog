// Tables.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Sortable.h"
#include <iostream>
using namespace std;
int main()
{
	Sortable A(10);
	A.Insert(2, new TData("����1"));
	A.Insert(4, new TData("����2"));
	A.Insert(3, new TData("����3"));

	TabRecord*d= A.Search(4);
	cout<< d->GetData()->Name<<endl;
    return 0;
}

