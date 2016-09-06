#include <gtest.h>
#include "methods.h"
#include "Graph_algoritm.h"

TEST(methods, can_do_the_algorithm)// fix
{
	Graph a(9, 6);
	a.Clear_edg();
	a.add_edg(1, 2, 7);
	a.add_edg(1, 6, 14);
	a.add_edg(1, 3, 9);
	a.add_edg(2, 3, 10);
	a.add_edg(2, 4, 15);
	a.add_edg(3, 6, 2);
	a.add_edg(3, 4, 11);
	a.add_edg(5, 6, 9);
	a.add_edg(4, 5, 6);
	double *MinR = Algoritm(0, a.GetVer(), a.GetMatr());
	EXPECT_EQ(MinR[4], 20);
}

TEST(Graph, can_do_the_cruscal_algorithm_with_queue_on_heap)
{
	Graph a(9, 6);
	a.add_edg(1, 2, 7);
	a.add_edg(1, 6, 14);
	a.add_edg(1, 3, 9);
	a.add_edg(2, 3, 10);
	a.add_edg(2, 4, 15);
	a.add_edg(3, 6, 2);
	a.add_edg(3, 4, 11);
	a.add_edg(5, 6, 9);
	a.add_edg(4, 5, 6);

	PriorQueue<double>* queue;
	CreateQ<double>::Create(queue, 1, a.GetEdg(), a.GetE());
	int res = Kraskal(&a, queue, false, 1);

	EXPECT_EQ(res, 1);
}

TEST(Graph, can_do_the_cruscal_algorithm_with_queue_on_binary_tree)
{
	Graph a(9, 6);
	a.add_edg(1, 2, 7);
	a.add_edg(1, 6, 14);
	a.add_edg(1, 3, 9);
	a.add_edg(2, 3, 10);
	a.add_edg(2, 4, 15);
	a.add_edg(3, 6, 2);
	a.add_edg(3, 4, 11);
	a.add_edg(5, 6, 9);
	a.add_edg(4, 5, 6);

	PriorQueue<double>* queue;
	CreateQ<double>::Create(queue, 2, a.GetEdg(), a.GetE());
	int res = Kraskal(&a, queue, false, 1);

	EXPECT_EQ(res, 1);
}

TEST(Graph, can_do_the_cruscal_algorithm_with_queue_on_tables)
{
	Graph a(9, 6);
	a.add_edg(1, 2, 7);
	a.add_edg(1, 6, 14);
	a.add_edg(1, 3, 9);
	a.add_edg(2, 3, 10);
	a.add_edg(2, 4, 15);
	a.add_edg(3, 6, 2);
	a.add_edg(3, 4, 11);
	a.add_edg(5, 6, 9);
	a.add_edg(4, 5, 6);

	PriorQueue<double>* queue;
	CreateQ<double>::Create(queue, 3, a.GetEdg(), a.GetE());
	int res = Kraskal(&a, queue, false, 1);

	EXPECT_EQ(res, 1);
}
