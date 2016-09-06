#include "methods.h"
using namespace std;

void Sorting(dKucha &a) // - ���������� �������������
{
	a.Heapfy();
	int sizeA = a.GetMaxSize() - 1;
	int sizeB = a.GetMaxSize();
	double* tmp = new double[sizeB];
	int n = 0;
	while (sizeA > 0)
	{
		a.Transpos(0, sizeA);
		tmp[n] = a.GetKey(sizeA);
		a.DecMaxSize();
		sizeA--;
		a.Deep(0);
		n++;

	}
	tmp[n] = a.GetKey(0);
	a.SetMaxSize(sizeB);
	for (int i = 0; i < sizeB;i++)
		a.ChangeKey(i, 0);
	for (int i = 0; i < sizeB;i++)
		a.ChangeKey(i, tmp[i]);
	delete[] tmp;


}
bool Scan(int f, int * b, int n)
{
	bool res = false;
	for (int i = 0; i < n;i++)
	{
		if (b[i] == f)
			res = true;
	}
	return res;
}

//������� 2:
double* Algoritm(int st, int ver, double **matr) // - �������� ��������� (����� ������������ ���� �� �������)
{
	bool *visit = new bool[ver];
	double *forHeap = new double[ver];
	double *minR = new double[ver];
	for (int i = 0; i < ver; i++)
	{
		visit[i] = false;
		minR[i] = matr[i][i];
	}
	minR[st] = 0;// ������ �����
	int over = 0;

	int k = 0;

	for (int i = 0; i < ver; i++)
	{
		if (visit[i] == false)
		{
			forHeap[k] = minR[i];
			k++;
		}
	}
	dKucha A(ver, 2, forHeap);
	Sorting(A);
	while (over < ver)
	{
		double min = A.GetMin();		
		int index, index1;
		for (int i = 0; i < ver;i++)
		{
			if (minR[i] == min && visit[i] == false) // ������ ������ ������� � ������� ��������
			{
				index = i;
				break;
			}				
		}
		A.Delete(0);
		visit[index] = true;
		for (int i = 0; i < ver;i++)
		{
			if (minR[i] > minR[index] + matr[index][i] && matr[index][i] != -1)
			{
				for (int j = 0; j < ver - over;j++)
				{
					if (A.GetKey(j) == matr[i][i])
					{
						index1 = j;
						break;
					}
				}

				matr[i][i] = minR[index] + matr[index][i];
				A.ChangeKey(index1, matr[i][i]);
				minR[i] = matr[i][i];				
			}
			if (matr[index][i] != -1 && index != i)
				matr[index][i] = matr[i][index] = -1;
		
		}
		Sorting(A);
		over++;
	}
	delete[] forHeap;
	delete[] visit;
	return minR;

	//������� 1
	/*
	bool *visit; // - ������� ������ ���������� ������
	double *mas;
	double *minR;

	minR = new double[ver];
	mas = new double[ver];
	visit = new bool[ver];
	for (int i = 0; i<ver; i++)
	{
		minR[i] = 1000000;
		visit[i] = false;
	}
	int u = 0;
	minR[0] = 0; // - �������������� ������ �������

	for (int j = 0; j<ver; j++)
	{//

		int k = 0;// - ���������� ������ � ���������� �������
		for (int i = 0; i<ver; i++)
		{
			if (visit[i] == false)
			{
				mas[k] = minR[i]; // - ���������� �� ���� ������
				k++;
			}
		}

		dKucha A(ver, 2, mas); // - ������� ���� �� ���� ����������
		Sorting(A);
		double min = A.GetMin(); // - �������� ����������� �������

		for (int i = 0; i<ver; i++) // - ���������� ��������������� ��� (min) �������
		{
			if (minR[i] == min && visit[i] !=true)
			{
				u = i; // - ��������� �������
				break;
			}
		}

		for (int i = 0; i<ver; i++)
		{
			if (matr[u][i]>0 && minR[u] + matr[u][i] < minR[i])// <=
			{
				minR[i] = minR[u] + matr[u][i];
				
			}
				
		}

		visit[u] = true;
	}//

	delete visit;
	delete mas;
	return minR;*/
}

int FindMinVes(int ver, int edg, double**matr, int *N, int *K, double *E)//������ ������������
{
	double min = 1000000;
	int i_min = -1;

	for (int i = 0;i < edg; i++)
	{
		if (E[i] < min && E[i]>0)
		{
			i_min = i;
			min = E[i];
		}
	}
	E[i_min] = -1;

	return i_min;
}

//int Kraskal(int ver, int edg, double**matr, int *N, int *K, double *E, PriorQueue<double>*& Q,
int Kraskal(Graph *A, PriorQueue<double>*& Q,
	bool print, int edg_num)// - �������
{
	int ver = A->GetVer();
	int edg = A->GetEdg();
	//double**matr = A->GetMatr();
	int *N = A->GetN();
	int *K = A->GetK();
	double *E = A->GetE();
	
	bool* visit = new bool[edg];
	for (int i = 0; i < edg; i++)
		visit[i] = false;
	
	Sets S(ver);
	for (int i = 1; i <= ver; i++)
	{
		S.Create(i); // - ������� ��������� �� ver �������������� �����������
	}
	Sets T(edg);

	cout << "Kraskal" << endl;
	while (!Q->IsEmpty())
	{
		//e = FindMinVes(ver, edg, matr, N, K, E);
		int e = Q->Top();
		Q->Pop();

		if (e < 0) break;

		int a = S.Search(A->GetNach(e, visit));
		int b = S.Search(A->GetKon(e, visit));

		if (a != b)
		{
			S.Merge(a, b);
			T.Create(A->GetEdgIndex(A->GetNach(e, visit), A->GetKon(e, visit), visit)+1);
		}
	}

	if(print)
	{
	cout << "min tree:" << endl;
	T.Print();
	cout << endl;
	for (int i = 1; i <= edg; i++)
	{
		if (T.Get(i) > 0)
		{
			cout << N[i-1] << " ";
			cout << K[i-1] << endl;
		}

	}
	}
	delete visit;
	return T.Get(edg_num);
}

//Graph* KraskalNew(Graph& a, PriorQueue<int>*& b)
//{
//	int n = a.GetVer();
//	int m = a.GetEdg();
//	Graph *tree = new Graph(n, m);
//	Sets *set = new Sets(n);
//	for (int i = 0; i<n; i++)
//		set->Create(i);

//	for (int i = 0; i<m;i++)
//		b->Push(a.GetE()[i]);// ���� ������ ��� �-���� �����
//	
//
//
//	int treeEdgeSize = 0;
//	int x = 0;
//	int tmp;
//
//	while (treeEdgeSize < n - 1)
//	{
//		tmp = b->Top();
//		b->Pop();
//
//		int u = a.GetN()[x]; // �������� ��������� ���������� �������
//		int v = a.GetK()[x]; //�������� �������� ���������� �������
//		int weight = tmp;
//
//		int An = set->Search(u); // �������� Search ��������
//		int Ak = set->Search(v);
//		if (An != Ak)
//		{
//			set->Merge(An, Ak); // �������� �������� Merge
//			tree->add_edg(u, v, weight); // ��� ����� � ����
//			treeEdgeSize++;
//		}
//		x++;
//	}
//
//	return tree;
//}


