#pragma once
class Sets
{
	int *set; // - массив с элементами множества
	int size; // - размер рассива
public:
	Sets(); // - конструктор по умолчанию
	Sets(int n); // - конструктор
	~Sets(); // - деструктор
	void Create(int); // - создание подмножества из одной вершины
	void Merge(int, int);// - объединение
	int Search(int);// - поиск
	void Print();
	int Get(int);
};

