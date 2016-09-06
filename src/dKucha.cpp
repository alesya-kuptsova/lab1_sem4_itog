
#include "dKucha.h"
#include <cstdlib>
#include <stdio.h>

dKucha::dKucha() // - конструктор по умолчанию
{
	MaxSize = 4;
	keys = new double[MaxSize];
	SizeOfKeys = 3;
	keys[0] = 0;
	count = 0;
}

dKucha:: ~dKucha() // - деструктор
{
	delete[] keys;
}

dKucha::dKucha(int val, int dim) // - конструктор, val - количество элементов, dim - размерность (количество детей у каждого корня) 
{
	if (dim >= 1 && val >= 1)
	{
		SizeOfKeys = dim;
		MaxSize = val;
		keys = new double[MaxSize];
		count = MaxSize;

		for (int i = 0; i < MaxSize; i++)
			keys[i] = rand() % MaxSize;
	}
	else throw dim;
}

dKucha::dKucha(int val, int dim, double *mas)// - конструктор из одномерного массива
{
	if (dim >= 1 || val >= 1)
	{
		SizeOfKeys = dim;
		MaxSize = val;
		keys = new double[MaxSize];

		count = MaxSize;

		for (int i = 0; i < MaxSize; i++)
			keys[i] = mas[i];
	}
	else throw dim;
}

dKucha::dKucha(const dKucha &s) // - конструктор копирования
{
	MaxSize = s.MaxSize;
	SizeOfKeys = s.SizeOfKeys;
	keys = new double[s.MaxSize];
	for (int i = 0; i < MaxSize; i++)
		keys[i] = s.keys[i];
	count = s.count;
}

void dKucha::Transpos(int a, int b) // - транспозиция
{
	double c;
	c = keys[a];
	keys[a] = keys[b];
	keys[b] = c;
}

int dKucha::MinChild(int pos) // - поиск минимального эл-та (его позиции)
{	
	if (pos < 0)
	{
		throw pos;
	}
	else
	{ 
	int d, n;
	n = MaxSize;
	d = SizeOfKeys;
	if (pos*d + 1 >= n)
		return 0;
	else
	{
		int s, last;
		double mk;
		s = pos*d + 1;
		mk = keys[s];
		last = (pos + 1)*d;
		if (last >= n)
			last = n - 1;

		for (int pos = s + 1; pos <= last; pos++)
		{
			if (mk > keys[pos])
			{
				mk = keys[pos];
				s = pos;
			}
		}
		return s;	
	}
	}
}

void dKucha::Pop(int pos) // - всплытие
{
	if (pos < 0)
	{
		throw pos;
	}
	else
	{
		int p, d;
		d = SizeOfKeys;
		p = (pos - 1) / d;
		while ((pos != 0) && (keys[p] > keys[pos]))
		{
			Transpos(pos, p);
			pos = p;
			p = (pos - 1) / d;
		}
		count--;
	}
}

void dKucha::Deep(int pos) // - погружение
{
	if (pos < 0)
	{
		throw pos;
	}
	else
	{
		int s;
		s = MinChild(pos);
		while ((s != 0) && (keys[pos] > keys[s])) //?????
		{
			Transpos(pos, s);
			//Print();

			pos = s;
			s = MinChild(pos);

		}
	}
}

void dKucha::Insert(int elem)
{
	double* tmp = new double[GetMaxSize()];
	for (int i = 0; i < GetMaxSize(); i++)
		tmp[i] = keys[i];
	MaxSize++;
	delete[] keys;
	keys = new double[MaxSize];
	for (int i = 0; i < MaxSize - 1;i++)
		keys[i] = tmp[i];
	keys[MaxSize - 1] = elem;;
	Pop(MaxSize - 1);
	delete[] tmp;
}

void dKucha::Delete(int elem) // - удаление
{
	if (elem < 0)
	{
		throw elem;
	}
	
		int last = MaxSize - 1;
		Transpos(last, elem);

		double* tmp = new double[MaxSize - 1];
		for (int i = 0; i < MaxSize - 1; i++)
			tmp[i] = keys[i];
		delete[] keys;

		MaxSize -= 1;
		keys = new double[MaxSize];
		for (int i = 0; i < MaxSize;i++)
			keys[i] = tmp[i];

		if (keys[elem] == keys[last])
		{

		}
	/*int n, d;
	d = MaxSize;
	n = SizeOfKeys;
	keys[elem] = keys[d - 1];
	n = n - 1;*/


		else if ((elem != 0) && (keys[elem] < (keys[(elem - 1) / SizeOfKeys])))
		{
			Pop(elem);
		}
		else
			Deep(elem);
	
	
	delete[] tmp;
}

void dKucha::ChangeKey(int elem, double k) //- изменение ключа
{
	if (elem < 0)
	{
		throw elem;
	}
	else
	{
		keys[elem] = k; // было keys[elem] - k
		//Pop(elem);
	}
}

void dKucha::Heapfy() // - окучивание
{
	for (int i = MaxSize - 1; i >= 0; i--) // for (int i = (MaxSize/SizeOfKeys)-1; i >= 0; i--)
		Deep(i);
}

//void dKucha :: Sorting(void) // - сортировка пирамидальная
//{
//	Heapfy();
//	int k = MaxSize;
//	MaxSize--;
//	while (MaxSize > 0)
//	{
//		Transpos(0, MaxSize);
//		//Print();
//		MaxSize--;
//		Deep(0);
//	}
//	MaxSize = k;
//	for (int i = 0; i < (MaxSize / 2); i++)
//		Transpos(i, MaxSize - 1 - i);
//
//}

void dKucha :: Print()
{
	for (int i = 0; i < MaxSize; i++)
		printf("%f ", keys[i]);
	printf("\n");
}
double dKucha :: GetMin()
{
	return keys[0];
}

int dKucha::GetMaxSize()
{
	return MaxSize;
}

void dKucha::Push()
{
	count++;
}

void dKucha::DecMaxSize()
{
	MaxSize--;
}

void dKucha::SetMaxSize(int st)
{
	MaxSize = st;
}

int dKucha::GetSizeOfKeys()
{
	return SizeOfKeys;
}
double* dKucha::GetKeys()
{
	return keys;
}

double dKucha::GetKey(int a)
{
	return keys[a];
}

int dKucha::GetCount()
{
	return count;
}

void dKucha::Sorting()
{
	Heapfy();
	int k = GetMaxSize();
	DecMaxSize();
	while (GetMaxSize() > 0)
	{
		Transpos(0, GetMaxSize());
		DecMaxSize();
		Deep(0);
	}
	SetMaxSize(k);
	for (int i = 0; i < (GetMaxSize() / 2); i++)
		Transpos(i, GetMaxSize() - 1 - i);
}

void dKucha::RemoveMin()
{
	count--;
}
