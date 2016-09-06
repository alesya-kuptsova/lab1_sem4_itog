#include <gtest.h>
#include <BinTree.h>

TEST(BinSearch, can_create_default_tree)
{
	ASSERT_NO_THROW(BinSearch <int> a);
}


TEST(BinSearch, can_create_epty_node)
{
	ASSERT_NO_THROW(Node <int> n);
}


TEST(BinSearch, can_create_node_with_key)
{
	ASSERT_NO_THROW(Node <int> n (5));
}

TEST(BinSearch, can_add_node_into_empty_tree)
{
	BinSearch <int> a;
	Node <int>* n= new Node <int>(5);
	ASSERT_NO_THROW(a.Push(a.root,n));
}

TEST(BinSearch, can_add_node_into_tree_with_smth)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	ASSERT_NO_THROW(a.Push(a.root, m));
}

TEST(BinSearch, can_copy_tree)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	ASSERT_NO_THROW(BinSearch <int> b(a));
}

TEST(BinSearch, copied_tree_coincides_with_original)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	BinSearch <int> b(a);
	EXPECT_EQ(a==b,true);
}

TEST(BinSearch, can_copy_part_of_tree)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	ASSERT_NO_THROW(a.Copy(m));
}

TEST(BinSearch, can_find_root)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *k = a.FindKey(a.root, 5);
	ASSERT_NE(k, nullptr);
}

TEST(BinSearch, can_find_any_node)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *k = a.FindKey(a.root, 7);
	ASSERT_NE(k, nullptr);
}

TEST(BinSearch, can_not_find_node)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *k = a.FindKey(a.root, 10);
	EXPECT_EQ(k, nullptr);
}

TEST(BinSearch, can_remove_root)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	ASSERT_NO_THROW(a.Remove(a.root,5));
}

TEST(BinSearch, can_remove_node)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	ASSERT_NO_THROW(a.Remove(a.root, 7));
}

TEST(BinSearch, can_find_min_node)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *k = a.FindMin(a.root);
	EXPECT_EQ(k->key, 5);
}

TEST(BinSearch, can_find_max_node)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *k = a.FindMax(a.root);
	EXPECT_EQ(k->key, 7);
}

TEST(BinSearch, can_find_next)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *k = a.FindNext(a.root, a.root);
	EXPECT_EQ(k->key, 7);
}

TEST(BinSearch, can_find_prev)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	Node <int> *t = a.FindKey(a.root, 7);
	Node <int> *k = a.FindPrev(a.root, t);
	EXPECT_EQ(k->key, 5);
}

TEST(BinSearch, can_bypas_wide)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	EXPECT_NO_THROW(a.BypasWide(a.root));
}

TEST(BinSearch, can_bypas_forward)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	EXPECT_NO_THROW(a.BypasForward(a.root));
}

TEST(BinSearch, can_bypas_reverse)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	EXPECT_NO_THROW(a.BypasReverse(a.root));
}

TEST(BinSearch, can_bypas_symmetric)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	EXPECT_NO_THROW(a.BypasSymmetric(a.root));
}

TEST(BinSearch, can_bypas_depth)
{
	BinSearch <int> a;
	Node <int>* n = new Node <int>(5);
	a.Push(a.root, n);
	Node <int>* m = new Node <int>(7);
	a.Push(a.root, m);
	EXPECT_NO_THROW(a.BypasDepth(a.root));
}
