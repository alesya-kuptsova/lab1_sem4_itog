
#pragma once
class dKucha
{
public:
	double *keys;
	int MaxSize;
	int SizeOfKeys;
	int count;

public:
	dKucha(); // - конструктор по умолчанию
	~dKucha(); // - деструктор
	dKucha(int val, int dim); // - конструктор, val - количество элементов, dim - размерность (количество детей у каждого корня) 
	dKucha(int val, int dim, double *mas);
	dKucha(const dKucha &s); // - конструктор копирования
	void Transpos(int a, int b); // - транспозиция (a и b - ключи)
	int MinChild(int pos); // - поиск минимального эл-та (его позиции)
	void Pop(int pos); // - всплытие
	void Push();
	void Deep(int pos); // - погружение
	void Insert(int elem); // - вставка
	void Delete(int elem); // - удаление
	void ChangeKey(int elem, double k); //- изменение ключа на заданную константу
	void Heapfy(); // - окучивание
	void Print();
	double GetMin();
	int GetMaxSize();
	void DecMaxSize();
	void SetMaxSize(int st);
	int GetSizeOfKeys();
	double* GetKeys();
	double GetKey(int);
	int GetCount();
	void Sorting();
	void RemoveMin();
};
