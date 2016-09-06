// Graphs.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "Graph_algoritm.h"
#include "methods.h"
#include "dKucha.h"
#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int tmp1;
	cout << "�������� ������:\n 1 - ������ �� ����,\n"
		" 2 - ������ �� �����,\n" << endl;
	cin >> tmp1;

	switch (tmp1)
	{
	case 1:
	{
		int _MaxSize = 0;
		int _SizeOfKeys = 0;

		printf("������� �����������, ����������\n");
		scanf_s("%d", &_SizeOfKeys);
		printf("������� ������ ����\n");
		scanf_s("%d", &_MaxSize);
		dKucha B (_MaxSize, _SizeOfKeys);

		B.Print();
		printf("��� ������ �� ����������:\n");
		B.Print();
		printf("\n");
		Sorting(B);
		printf("��� ������ ����� ����������:\n");
		B.Print();
		break;
	}

	case 2:
	{
		int Ver;
		int Edg;
		int tmp2;
		Graph A;
		cout << "�������� ������� ������� �������� ������:\n 1 - ������ ���� �1,\n"
			" 2 - ������ ���� �2 (� ��������� ���������� ����� � ������),\n"
			" 3 - ��������� ����" << endl;
		cin >> tmp2;
		switch (tmp2)
		{
		case 1:
		{
			cout << "������� ���������� ����� � ������" << endl;
			cin >> Edg >> Ver;
			A = Graph(Edg, Ver);
			cout << "������� ����� ��������� �������, �������� � ��� ��� ������� �����" << endl;
			A.input_edg();
		
			A.Print();
			
			break;
		}
		case 2:
		{
			cout << "������� ���������� ������ � �����" << endl;
			cin >> Edg >> Ver;
			A = Graph(Edg, Ver);
			A.Generate_Ves();
			A.Print();
			break;
		}
		case 3:
		{
			while (true)
			{
				Edg = rand() % 100;
				Ver = rand() % 50;
				if (Ver < Edg)
				{
					break;
				}
			}
			A = Graph(Edg, Ver);
			A.Generate_Ves();
			cout << "��������������� ���� ����� ���:" << endl;
			A.Print();
			break;
		}
		}

		cout << "�������� ��� �� ������ ������� � ������:\n "
			"1 - ��������� �������� ��������� (����� ���� �� ��� ��� ���� �������),\n "
			"2 - ��������� �������� �������� (����� ������������ ��������� ������)" << endl;

		cin >> tmp2;
		switch (tmp2)
		{
		case 1:
		{
			cout << "������� � ����� ������� �������� ������: " << endl;
			int tmptmp;
			cin >> tmptmp;
			int* P = new int[A.GetVer()];
			double *MinR = Algoritm(tmptmp, A.GetVer(), A.GetMatr());
			cout << "��������� ���������:" << endl;
			cout << "----------------------------------������� �������: "<< tmptmp << endl;
			cout << "----------------------------------" << endl;
			cout << "�������:";
			for (int i = 0; i < A.GetVer(); i++)
			{
				cout << i + 1 << "    ";
			}
			cout << endl;
			cout << "����������:";

			for (int i = 0; i < A.GetVer(); i++)
			{
				printf("%f ", MinR[i]);
			}
			cout << endl;
			A.Print();
			break;
		}
		case 2:
		{
		//	Graph *A = new Graph(Edg, Ver);
			int tmpQ;
			cout << "�� ����� ������� ���������: 1 - �� ����, 2 - �� ������, 3 - �� ��������"<<endl;
			cin >> tmpQ;
			PriorQueue<double>* queue;
			CreateQ<double>::Create(queue, tmpQ, A.GetEdg(), A.GetE());
			//res = KraskalNew(A, queue);
			//Kraskal(Ver, Edg, A.GetMatr(), A.GetN(), A.GetK(), A.GetE(), queue, true, 0);
			Kraskal(&A, queue, true, 0);
			break;
		}
		}
	}
	}
//Graph a(9, 6);
//a.add_edg(1, 2, 7);
//a.add_edg(1, 6, 14);
//a.add_edg(1, 3, 9);
//a.add_edg(2, 3, 10);
//a.add_edg(2, 4, 15);
//a.add_edg(3, 6, 2);
//a.add_edg(3, 4, 11);
//a.add_edg(5, 6, 9);
//a.add_edg(4, 5, 6);
//int *M = Algoritm(a.GetVer(), a.GetMatr());
//int b=a.GetMinR(4);
//if (b = 20)
//cout << "�����"<<endl;
//else cout << "������" << endl;

	return 0;
}

