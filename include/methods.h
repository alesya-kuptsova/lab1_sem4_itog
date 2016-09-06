#pragma once
#include <iostream>
#include <stdlib.h>
#include "dKucha.h"
#include "Graph_algoritm.h"
#include "Queue.h"
#include "Separaited_Sets.h"
#include "dKucha.h"

double* Algoritm(int st, int ver, double **matr);
//double* Dijkstra(int s, int ver, int *&P, double **matr);
void Sorting(dKucha &a);
//int Kraskal(int ver, int edg, double**matr, int *N, int *K, double *E, PriorQueue<double>*& b,
int Kraskal(Graph *A, PriorQueue<double>*& b,
            bool print, int edg_num);
