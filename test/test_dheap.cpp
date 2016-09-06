
#include <gtest.h>
#include <dKucha.h>

TEST(dKucha, can_create_default_heap)
{
	ASSERT_NO_THROW(dKucha a);
}

TEST(dKucha, can_copy_other_heap)
{
	dKucha a;
	ASSERT_NO_THROW(dKucha b(a));
}

TEST(dKucha, can_create_heap_with_good_options)
{
	ASSERT_NO_THROW(dKucha a(2, 5));
}

TEST(dKucha, throw_when_wrong_size)
{
	ASSERT_ANY_THROW(dKucha a(4, 0));
}

TEST(dKucha, throw_when_wrong_dimension)
{
	ASSERT_ANY_THROW(dKucha a(0, 5));
}

TEST(dKucha, can_insert_node)
{
	dKucha a;
	ASSERT_NO_THROW(a.Insert(2));
}

TEST(dKucha, can_transposition)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas [i] = i + 1;
	dKucha a(4, 2,mas);
	a.Transpos(2, 3);
	delete[] mas;
	ASSERT_EQ(a.keys[2], 4);
	

}

TEST(dKucha, can_pop_keys)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas[i] = i + 1;
	dKucha a(4, 2, mas);
	//a.ChangeKey(3, 5); // в самой функции уже вызывается pop.
	a.Pop(3);
	ASSERT_EQ(a.keys[0], 1);
}

TEST(dKucha, throw_when_wrong_pos_pop)
{
	dKucha a(2, 3);
	ASSERT_ANY_THROW(a.Pop(-1));
}

TEST(dKucha, can_search_minchild)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas[i] = i + 1;
	dKucha a(4, 2, mas);
	int s = a.MinChild(0);
	ASSERT_EQ(s, 1);
}

TEST(dKucha, throw_then_wrong_pos_minchild)
{
	dKucha a(4, 5);
	ASSERT_ANY_THROW(a.MinChild(-1));
}

TEST(dKucha, can_dip_keys)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas[i] = i + 1;
	dKucha a(4, 2, mas);
	a.keys[0] = 5;
	a.Deep(0);
	ASSERT_EQ(a.keys[3], 5);
}

TEST(dKucha, throw_when_wrong_pos_dip)
{
	dKucha a(2, 6);
	ASSERT_ANY_THROW(a.Deep(-1));
}

TEST(dKucha, can_drop_node)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas[i] = i + 1;
	dKucha a(4, 2, mas);
	a.Delete(2);
	ASSERT_EQ(a.keys[2], 4);
}

TEST(dKucha, throw_when_wrong_pos_drop)
{
	dKucha a(2, 6);
	ASSERT_ANY_THROW(a.Delete(-1));
}

TEST(dKucha, can_changekey)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas[i] = i + 1;
	dKucha a(4, 2, mas);
	a.ChangeKey(3, -1);
	ASSERT_EQ(a.keys[3], -1);
}

TEST(dKucha, throw_when_wrong_pos_changekey)
{
	dKucha a(2, 5);
	ASSERT_ANY_THROW(a.ChangeKey(-4, 5));
}

TEST(dKucha, can_heapfy)
{
	double* mas = new double[4];
	for (int i = 0; i < 4; i++)
		mas[i] = 4- i ;
	dKucha a(4, 2, mas);
	a.Heapfy();

	int r[4] = { 1, 3, 2, 4};
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a.keys[i] == r[i])
			count++;
	}
	ASSERT_EQ(count, 4);
}