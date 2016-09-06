#pragma once
const int Vmax = 30; // - максимальный вес

class Graph
{
	int edg;
	int ver;
	double **matr; // - матрица связности 
	int *minR; // - результат работы алгоритма на поиск минимального расстояния 
	int *N; // - начальные номера вершин
	int *K;// - конечные номера вершин
	double *E;// - массив из весов
	int i_edg;
public:
	Graph();
	~Graph();// - деструктор
	Graph(int, int); // - конструктор, где edg - ребро (edge), ver - вершины (vertex)
	Graph(Graph&); // - конструктор копирования
	Graph& operator= (Graph&);// - оператор присваивания
	void Generate_Ves();// - функция-генератор весов для ребер графа
	//void Algoritm(); // - алгоритм Дейкстеры (поиск минимального пути до вершины)
	void input_edg();
	void Print();
	void PrintMinR();
	void Clear_edg();
	void add_edg(int, int, double); // - функция добавления ребра в граф 
	double GetMinR(int); // - получение минималного расстояния 
	void PrintTree(); // - печать
	double* CreateE();
	int GetVer();
	double ** GetMatr();
	int GetEdg();
	int* GetN();
	int* GetK();
	double* GetE();
	int GetNach(int, bool*);
	int GetKon(int, bool*);
	int GetEdgIndex(int,int,bool*);

};
