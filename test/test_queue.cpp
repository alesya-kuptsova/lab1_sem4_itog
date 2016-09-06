#include <gtest.h>
#include "Queue.h"

TEST(Kucha_bst, can_create_default_queue)
{
	ASSERT_NO_THROW(PriorQueue<int>* q = new QKucha<int>(10));
}
 
TEST(Kucha_bst, can_GetSize)
{
	PriorQueue<int>* q = new QKucha<int>(10);
	ASSERT_NO_THROW(q->GetSize());
}

TEST(Kucha_bst, can_check_if_it_is_empty)
{
	PriorQueue<int>* q = new QKucha<int>(10);
	ASSERT_NO_THROW(q->IsEmpty());
}

TEST(Kucha_bst, can_push)
{
	PriorQueue<int>* q = new QKucha<int>(10);
	ASSERT_NO_THROW(q->Push(1));
}

TEST(Kucha_bst, can_pop)
{
	PriorQueue<int>* q = new QKucha<int>(10);
	q->Push(1);
	ASSERT_NO_THROW(q->Pop());
}

TEST(Kucha_bst, can_not_pop_from_empty_queue)
{
	PriorQueue<int>* q = new QKucha<int>(1);
	q->Pop();
	ASSERT_ANY_THROW(q->Pop());
}

TEST(Kucha_bst, can_top)
{
	PriorQueue<int>* q = new QKucha<int>(10);
	q->Push(1);
	ASSERT_NO_THROW(q->Top());
}

TEST(Kucha_bst, can_not_top_from_empty_queue)
{
	PriorQueue<int>* q = new QKucha<int>(1);
	q->Pop();
	ASSERT_ANY_THROW(q->Top());
}

///////////////////////////////////////////////////////////////////////////

TEST(BinTree_bst, can_create_default_queue)
{
	ASSERT_NO_THROW(new QTree<int>());
}

TEST(QTree, isempty)
{
	QTree<int> *a = new QTree<int>;
	EXPECT_EQ(a->IsEmpty(), 1);
}

TEST(QTree, can_Push)
{
	QTree<int> *a = new QTree<int>;
	ASSERT_NO_THROW(a->Push(1));
}

TEST(QTree, can_pop)
{
	QTree<int> *a = new QTree<int>;
	a->Push(1);
	ASSERT_NO_THROW(a->Pop());
}

TEST(QTree, throw_if_Pop_empty_tree)
{
	QTree<int> *a = new QTree<int>;
	ASSERT_ANY_THROW(a->Pop());
}

TEST(QTree, can_Top_queue)
{
	QTree<int> *a = new QTree<int>;
	a->Push(1);
	ASSERT_NO_THROW(a->Top());
}



TEST(QTree, can_getsize_queue)
{
	QTree<int> *a = new QTree<int>;
	ASSERT_NO_THROW(a->GetSize());
}

TEST(QTree, can_getsize_queue2)
{
	QTree<int> *a = new QTree<int>;
	a->Push(1);
	EXPECT_EQ(1, a->GetSize());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Table_bst, can_create_default_queue)
{
	ASSERT_NO_THROW(new QTable<int>(10));
}

TEST(Table_bst, can_create_queue_from_array)
{
	double E[] = { 1, 2, 3, 4 };
	ASSERT_NO_THROW(new QTable<int>(4, E));
}

TEST(Table_bst, insertion_increases_size)
{
	QTable<int> *a = new QTable<int>(2);
	int s = a->GetSize();
	a->Push(6);
	EXPECT_EQ(a->GetSize(), s + 1);
}

TEST(Table_bst, pop_decreases_size)
{
	QTable<int> *a = new QTable<int>(2);
	a->Push(6);
	int s = a->GetSize();
	a->Pop();
	EXPECT_EQ(a->GetSize(), s - 1);
}

TEST(Table_bst, can_top_element)
{
	QTable<int> *a = new QTable<int>(2);
	a->Push(6);
	int n=a->Top();
	EXPECT_EQ(n, 6);
}

TEST(Table_bst, can_get_size)
{
	QTable<int> *a = new QTable<int>(2);
	a->Push(6);
	int n = a->GetSize();
	EXPECT_EQ(n, 1);
}

TEST(Table_bst, if_it_is_empty)
{
	QTable<int> *a = new QTable<int>(2);
	a->Push(6);
	EXPECT_EQ(a->IsEmpty(), false);
}