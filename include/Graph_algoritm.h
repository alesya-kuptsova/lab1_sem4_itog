#pragma once
const int Vmax = 30; // - ������������ ���

class Graph
{
	int edg;
	int ver;
	double **matr; // - ������� ��������� 
	int *minR; // - ��������� ������ ��������� �� ����� ������������ ���������� 
	int *N; // - ��������� ������ ������
	int *K;// - �������� ������ ������
	double *E;// - ������ �� �����
	int i_edg;
public:
	Graph();
	~Graph();// - ����������
	Graph(int, int); // - �����������, ��� edg - ����� (edge), ver - ������� (vertex)
	Graph(Graph&); // - ����������� �����������
	Graph& operator= (Graph&);// - �������� ������������
	void Generate_Ves();// - �������-��������� ����� ��� ����� �����
	//void Algoritm(); // - �������� ��������� (����� ������������ ���� �� �������)
	void input_edg();
	void Print();
	void PrintMinR();
	void Clear_edg();
	void add_edg(int, int, double); // - ������� ���������� ����� � ���� 
	double GetMinR(int); // - ��������� ����������� ���������� 
	void PrintTree(); // - ������
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
