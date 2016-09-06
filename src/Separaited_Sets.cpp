
#include "Separaited_Sets.h"
#include <iostream>
using namespace std;

Sets::Sets()// - ����������� �� ���������
{
	size = 0;
	set = 0;
}

Sets::~Sets()// - ����������
{
	if (set != 0)
	{
		delete[] set;
	}
}

Sets::Sets(int n) // - �����������
{
	size = n;
	set = new int [size+1];
	for (int i = 0; i < size+1; i++)
	{
		set[i] = 0;
	}
}

void Sets:: Create(int v) // - �������� ������������ �� ����� �������
{
	set[v] = v;
}

void Sets:: Merge(int x, int y)// - �����������
{
	set[x] = y;
}

int Sets:: Search(int x)// - �����
{
	while (set[x] != x)
	{
		x = set[x];
	}
	return x;
}

int Sets::Get(int b)
{
	return set[b];
}

void Sets::Print()
{
	for (int i = 1; i < size + 1; i++)
	{
		cout << set[i] <<" ";
	}
	cout << endl;
}

