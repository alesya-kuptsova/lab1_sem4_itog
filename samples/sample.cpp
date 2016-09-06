// Graphs.cpp: определяет точку входа для консольного приложения.
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
	cout << "Выберите задачу:\n 1 - задача на Кучи,\n"
		" 2 - задача на Графы,\n" << endl;
	cin >> tmp1;

	switch (tmp1)
	{
	case 1:
	{
		int _MaxSize = 0;
		int _SizeOfKeys = 0;

		printf("Введите размерность, пожалуйста\n");
		scanf_s("%d", &_SizeOfKeys);
		printf("Введите размер кучи\n");
		scanf_s("%d", &_MaxSize);
		dKucha B (_MaxSize, _SizeOfKeys);

		B.Print();
		printf("Ваш массив до сортировки:\n");
		B.Print();
		printf("\n");
		Sorting(B);
		printf("Ваш массив после сортировки:\n");
		B.Print();
		break;
	}

	case 2:
	{
		int Ver;
		int Edg;
		int tmp2;
		Graph A;
		cout << "Выберите вариант задания исходных данных:\n 1 - ручной ввод №1,\n"
			" 2 - ручной ввод №2 (с введением количества ребер и вершин),\n"
			" 3 - рандомный ввод" << endl;
		cin >> tmp2;
		switch (tmp2)
		{
		case 1:
		{
			cout << "Введите количество ребер и вершин" << endl;
			cin >> Edg >> Ver;
			A = Graph(Edg, Ver);
			cout << "Введите номер начальной вершины, конечной и вес для каждого ребра" << endl;
			A.input_edg();
		
			A.Print();
			
			break;
		}
		case 2:
		{
			cout << "Введите количество вершин и ребер" << endl;
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
			cout << "Сгенерированный граф имеет вид:" << endl;
			A.Print();
			break;
		}
		}

		cout << "Выберите что Вы хотите сделать с графом:\n "
			"1 - Выполнить алгоритм Дейкстеры (поиск пути до той или иной вершины),\n "
			"2 - Выполнить алгоритм Краскала (поиск минимального остовного дерева)" << endl;

		cin >> tmp2;
		switch (tmp2)
		{
		case 1:
		{
			cout << "Введите с какой вершины начинать отсчет: " << endl;
			int tmptmp;
			cin >> tmptmp;
			int* P = new int[A.GetVer()];
			double *MinR = Algoritm(tmptmp, A.GetVer(), A.GetMatr());
			cout << "Результат алгоритма:" << endl;
			cout << "----------------------------------Текущая вершина: "<< tmptmp << endl;
			cout << "----------------------------------" << endl;
			cout << "Вершины:";
			for (int i = 0; i < A.GetVer(); i++)
			{
				cout << i + 1 << "    ";
			}
			cout << endl;
			cout << "Расстояния:";

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
			cout << "На какой очереди выполнять: 1 - на куче, 2 - на графах, 3 - на таблицах"<<endl;
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
//cout << "верно"<<endl;
//else cout << "лошара" << endl;

	return 0;
}

