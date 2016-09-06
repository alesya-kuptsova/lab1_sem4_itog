
#include "Graph_algoritm.h"
#include "dKucha.h"
#include "Separaited_Sets.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Graph::Graph()
{
	edg=ver=0;
	matr=0;
	N = K = 0;
		E = 0;
	minR = 0;
	i_edg = 0;
}

Graph::~Graph()
{
	for (int i=0; i<ver; i++)
	{
		delete matr[i];
	}
	delete matr;
	if (minR > 0)
	{
		delete[] minR;
	}
	if (N > 0)
	{
		delete[] N;
	}

	if (K > 0)
	{
		delete[] K;
	}
}

Graph::Graph(int _edg, int _ver) // - конструктор, где edg - ребро (edge), ver - вершины (vertex)
{

	if ((_ver<=0) || (_edg<=0))
	{
		throw _ver;
	}
	else
	{
		edg = _edg;
		ver = _ver;
		matr = new double *[ver];
		for (int i = 0; i < ver; i++)
		{
			matr[i] = new double[ver];

			for (int j = 0; j < ver; j++)
			{
				if (i == j) //не было
					matr[i][j] = 1000000;
				else
					matr[i][j] = -1;
			}
		}

		N = new int[edg];
		K = new int[edg];
		E = new double[edg];
	}
	minR = 0;
	i_edg = 0;
}

Graph::Graph(Graph&g)// - конструктор копирования
{
	
	if ((g.ver <= 0) || (g.edg <= 0))
	{
		throw ver;
	}
	else
	{
		ver = g.ver;
		edg = g.edg;
		matr = new double *[ver];
		for (int i = 0; i < ver; i++)
		{
			matr[i] = new double[ver];

			for (int j = 0; j < ver; j++)
			{
				matr[i][j] = g.matr[i][j];
			}
		}

		N = new int[edg];
		K = new int[edg];
		E = new double[edg];
	}
	minR = 0;
	i_edg = g.i_edg;
}

Graph& Graph :: operator= (Graph&g)// - оператор присваивания
{
	if ((g.ver <= 0) || (g.edg <= 0))
	{
		throw ver;
	}
	else
	{
		if ((ver != g.ver) || (edg != g.edg))
		{
			ver = g.ver;
			edg = g.edg;
			matr = new double *[ver];
			for (int i = 0; i < ver; i++)
			{
				matr[i] = new double[ver];
			}
		}

		for (int i = 0; i < ver; i++)
		{
			for (int j = 0; j < ver; j++)
			{
				matr[i][j] = g.matr[i][j];
			}
		}

		N = new int[edg];
		K = new int[edg];
		E = new double[edg];
	}
	return *this;
}

void Graph:: Generate_Ves() // - функция-генератор весов для ребер графа
{
	while (true)
	{
		for (int i = 0; i < ver; i++)
		{
			for (int j = 0; j < ver; j++)
			{
				matr[i][j] = 0;
			}
		}
		// генерация связей:
		for (int i = 0; i < edg; i++)
		{
			int v1 = rand() % ver;
			int v2 = rand() % ver;
			double ves;
			if (v1 != v2)
			{
				ves = rand() % Vmax + 0;
				matr[v1][v2] = ves;
				matr[v2][v1] = ves;
				N[i] = v1;
				K[i] = v2;
				E[i] = ves;
			}

			else i--;
		}

		bool flag = 1;

		for (int i = 0; i < ver; i++)
		{
			int j;
			for (j = 0; j < ver; j++)
			{
				if (matr[i][j] != 0)
					break;
			}
			if (j == ver)
			{
				flag = 0;
			}
		}

		if(flag==1)
		{
			break;
		}
	}
}

void Graph::input_edg()
{
	for (int i=0; i<edg; i++)
	{
		cout<<"edg "<<i+1<<endl;
		int ver1, ver2;
		cout<<"ver1=";
		cin>>ver1;
		cout<<"ver2=";
		cin>>ver2;
		double ves;
		cout<<"ves=";
		cin>>ves;

		matr[ver1-1][ver2-1]=ves;
		matr[ver2-1][ver1-1]=ves;

		N[i] = ver1;
		K[i] = ver2;
		E[i] = ves;
	}
}

void Graph::add_edg(int _ver1, int _ver2, double _ves)
{
	if ((_ver1 < 1)||(_ver1>ver))
	{
		throw _ver1;
	}
	if((_ver2 < 1) || (_ver2 > ver))
	{
		throw _ver2;
	}
	if ((_ves <= 0) || (_ves >= Vmax))
	{
		throw _ves;
	}
	if (_ver1 == _ver2)
	{
		throw _ver1;
	}
	matr[_ver1 - 1][_ver2 - 1] = _ves;
	matr[_ver2 - 1][_ver1 - 1] = _ves;

	N[i_edg] = _ver1;
	K[i_edg] = _ver2;
	E[i_edg] = _ves;
	i_edg++;
}

void Graph::Print()
{
	cout<<"edg="<<edg<<" ver="<<ver<<endl;
	for(int i=0; i<ver; i++)
	{
		for (int j=0; j<ver; j++)
		{
			cout<<matr[i][j]<<" ";
		}
		cout<<endl;
	}
}

//void Graph:: Algoritm() // - алгоритм Дейкстеры (поиск минимального пути до вершины)
//{
//	bool *visit; // - рабочий массив посещенных вершин
//	int *mas;
//
//	minR=new int[ver];
//	mas=new int [ver];
//	visit=new bool[ver];
//	for(int i=0; i<ver; i++)
//	{
//		minR[i]=1000000;
//		visit[i]=false;
//	}
//	int u=0;
//	minR[0]=0; // - инициализируем первую вершину
//
//	for (int j=0; j<ver; j++)
//	{//
//			
//		int k=0;// - количество вершин с временными метками
//		for (int i=0; i<ver; i++)
//		{
//			if(visit[i]==false)
//			{
//				mas[k]=minR[i]; // - расстояние до этих вершин
//				k++;
//			}
//		}
//
//		dKucha A(ver, 2, mas); // - создаем кучу из этих расстояний
//		A.Sorting();
//		int min=A.GetMin(); // - получаем минимальный элемент
//
//		for(int i=0; i<ver; i++) // - определяем соответствующую ему (min) вершину
//		{
//			if (minR[i]==min)
//			{
//				u=i; // - выбранная вершина
//				break;
//			}
//		}
//		
//		for(int i=0; i<ver; i++)
//		{
//			if(matr[u][i]>0 && minR[u]+matr[u][i]<minR[i])
//				minR[i]=minR[u]+matr[u][i];
//		}
//
//		visit[u]=true;
//	}//
//
//	delete visit;
//	delete mas;
// }

void Graph::PrintMinR()
{
	cout<<"minR=";
	for (int i=0; i<ver; i++)
		{
			cout<<minR[i]<<" ";
		}
		cout<<endl;
}

void Graph::Clear_edg()
{
	i_edg = 0;
}

double Graph::GetMinR(int _ver)
{
	if ((_ver < 0) && (_ver >= ver))
	{
		throw _ver;
	}
	return minR[_ver];
}

//void Graph::Kraskal()// - Краскал
//{
//	Sets S(ver);
//	for (int i = 1; i <= ver; i++)
//	{
//		S.Create(i); // - создаем коллекцию из ver одноэлементных подмножеств
//	}
//	Sets T(edg);
//
//	cout << "Kraskal" << endl;
//	while (true)
//	{
//		int e = FindmMinVes();
//		if (e < 0) break;
//
//		int a = S.Search(N[e]);
//		int b = S.Search(K[e]);
//
//		if (a != b)
//		{
//			S.Merge(a, b);
//			/*	PrintTree();
//				S.Print();*/
//			T.Create(e+1);
//		}
//	}
//
//	cout << "min tree:" << endl;
//	T.Print();
//}

double * Graph::CreateE()
{
	double *E = new double[edg];
	int k = 0;
	for (int i = 0; i < ver; i++)
	{
		for (int j = i + 1; j < ver; j++)
		{
			if (matr[i][j] > 0)
				E[k++] = matr[i][j];
		}
	}
	return E;
}

//int Graph::FindmMinVes()
//{
//	int min = 1000000;
//	int i_min = -1;
//	for (int i = 0;i < edg; i++)
//	{
//		if (E[i] < min && E[i]>0)
//		{
//			i_min = i;
//			min = E[i];
//		}
//	}
//	E[i_min] = -1;
//	return i_min;
//}

void Graph::PrintTree()
{
	//cout << "min tree:" << endl;
	for (int i = 0; i < edg; i++)
	{
		cout << E[i] << " ";
	}
	cout << "    ";
}

int Graph:: GetVer()
{
	return ver;
}

double ** Graph::GetMatr()
{
	return matr;
}
int Graph::GetEdg() // - функция возврата для ребер графа
{
	return edg;
}

int* Graph::GetN()
{
	return N;
}

int* Graph::GetK()
{
	return K;
}

double* Graph::GetE()
{
	return E;
}

int Graph::GetNach(int e, bool* visit)
{
	for (int i = 0; i < edg; i++)
	{
		if (E[i] == e && visit[i]!=true)
			return N[i];
	}
	return -1;
}

int Graph::GetKon(int e, bool* visit)
{
	{
		for (int i = 0; i < edg; i++)
		{
			if (E[i] == e && visit[i]!=true)
				return K[i];
		}
		return -1;
	}
}

int Graph::GetEdgIndex(int n, int k, bool* visit)
{
	for (int i = 0; i < edg; i++)
	{
		if (N[i] == n && K[i] == k)
		{
			visit[i] = true;
			return i;
		}
	}
	return -1;
}


