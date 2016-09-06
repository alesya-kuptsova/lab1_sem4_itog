
#include <gtest.h>
#include <dKucha.h>
#include <Graph_algoritm.h>

//TEST(Graph, can_create_default_graph)
//{
//	ASSERT_NO_THROW(Graph a);
//}

TEST(Graph, can_create_graph_with_good_options)
{
	ASSERT_NO_THROW(Graph a(5, 4));
}

TEST(Graph, can_generate_graph_with_good_options)
{
	Graph a(5, 4);
	ASSERT_NO_THROW(a.Generate_Ves());
}

TEST(Graph, throw_when_wrong_number_of_vertex)
{
	ASSERT_ANY_THROW(Graph a(5, 0));
}

TEST(Graph, throw_when_negative_number_of_vertex)
{
	ASSERT_ANY_THROW(Graph a(5, -1));
}

TEST(Graph, throw_when_wrong_number_of_edge)
{
	ASSERT_ANY_THROW(Graph a(0, 5));
}

TEST(Graph, throw_when_negative_number_of_edge)
{
	ASSERT_ANY_THROW(Graph a(-8, 5));
}

TEST(Graph, throw_when_wrong_number_of_vertex1_in_including)
{
	Graph* pa = new Graph(5, 4);
	ASSERT_ANY_THROW(pa->add_edg(6, 1, 1));
}

TEST(Graph, throw_when_negative_number_of_of_vertex1_in_including)
{
	Graph a(5, 4);
	ASSERT_ANY_THROW(a.add_edg(-6, 1, 1));
}
TEST(Graph, throw_when_wrong_number_of_vertex2_in_including)
{
	Graph a(5, 4);
	ASSERT_ANY_THROW(a.add_edg(5, 7, 1));
}

TEST(Graph, throw_when_negative_number_of_of_vertex2_in_including)
{
	Graph a(5, 4);
	ASSERT_ANY_THROW(a.add_edg(5, -1, 1));
}
TEST(Graph, throw_when_wrong_number_of_ves_in_including)
{
	Graph a(5, 4);
	ASSERT_ANY_THROW(a.add_edg(5, 6, 35));
}

TEST(Graph, throw_when_negative_number_of_of_ves_in_including)
{
	Graph a(5, 4);
	ASSERT_ANY_THROW(a.add_edg(5, 6, -3));
}
TEST(Graph, throw_when_we_have_loop_in_graph)
{
	Graph a(5, 4);
	ASSERT_ANY_THROW(a.add_edg(5, 5, 1));
}



