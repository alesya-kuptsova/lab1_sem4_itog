#include <gtest.h>
#include "Table.h"
#include "TabRecord.h"
#include "ScanTable.h"
#include "Sortable.h"
#include "HashTable.h"
#include "ArrayHashTable.h"
#include <stdio.h>
using namespace std;

TEST(Tab_Record, can_create_table)
{
	TabRecord *tab;
	ASSERT_NO_THROW(tab = new TabRecord(3, new TData("abc")));
}

TEST(Tab_Record, can_get_key)
{
	TabRecord *tab = new TabRecord (3, new TData("abc"));
	int k;
	ASSERT_NO_THROW(k = tab->GetKey());
}

TEST(Tab_Record, can_get_data)
{
	TabRecord *tab = new TabRecord(3, new TData("abc"));
	TData *d;
	ASSERT_NO_THROW(d = tab->GetData());
}

TEST(Tab_Record, get_key_correctly)
{
	TabRecord *tab = new TabRecord(3, new TData("abc"));
	int k = tab->GetKey();
	EXPECT_EQ(3, k);
}
TEST(Tab_Record, get_data_correctly)
{
	TabRecord *tab = new TabRecord(3, new TData("abc"));
	TData *d = tab->GetData();
	char * s = d->Name;
	EXPECT_EQ(strcmp(s,"abc"), 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Scan_Table, can_create_table_by_size)
{
	ASSERT_NO_THROW(ScanTable *tab = new ScanTable(2));
}

TEST(Scan_Table, can_create_table) //fix
{
	ASSERT_NO_THROW(ScanTable *tab = new ScanTable());
}

TEST(Scan_Table, can_copy_table)
{
	ScanTable s(2);
	ASSERT_NO_THROW(ScanTable cps(s));
}

TEST(Scan_Table, can_search)
{
	ScanTable *s = new ScanTable(3);
	s->insert(1, new TData("a"));
	s->insert(5,  new TData("b"));
	TabRecord* t;
	ASSERT_NO_THROW(t = s->search(5));
}

TEST(Scan_Table, can_push)
{
	ScanTable s(2);
	ASSERT_NO_THROW(s.insert(3, new TData("abc")));
}

TEST(Scan_Table, can_remove)
{
	ScanTable *s = new ScanTable(3);
	s->insert(1, new TData("a"));
	s->insert(5, new TData("b"));
	ASSERT_NO_THROW(s->erase(1));
}

TEST(Scan_Table, searches_correctly)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	TabRecord D(2, new TData("b"));
	char * s1 = D.GetData()->Name;
	char * s2 = (s.search(2))->GetData()->Name;
	EXPECT_EQ(strcmp(s1, s2), 0);
}

TEST(Scan_Table, can_get_count)
{
	ScanTable s(3);
	ASSERT_NO_THROW(s.GetCount());
}

TEST(Scan_Table, cant_create_table_with_invalid_argument)
{
	ASSERT_ANY_THROW(ScanTable s(-1));
}

TEST(Scan_Table, insert_increases_count)
{
	ScanTable s(3);
	size_t expCount = s.GetCount() + 2;
	s.insert(1, new TData("b"));
	s.insert(2, new TData("a"));
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(Scan_Table, cant_insert_record_when_table_is_full)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	ASSERT_ANY_THROW(s.insert(4, new TData("d")));
}

TEST(Scan_Table, removing_decrease_count)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));;
	size_t expCount = s.GetCount() - 1;
	s.erase(1);
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(Scan_Table, cant_remove_record_when_table_is_empty)
{
	ScanTable s(3);
	ASSERT_ANY_THROW(s.erase(1));
}

TEST(Scan_Table, removing_of_non_existing_record_does_not_decrease_count)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	size_t expCount = s.GetCount();
	s.erase(4);
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(Scan_Table, search_does_not_change_count)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	size_t expCount = s.GetCount();
	s.search(2);
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(Scan_Table, search_returns_0_if_record_does_not_exist)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	EXPECT_EQ(NULL, s.search(4));
}

TEST(Scan_Table, copied_table_is_equal_to_source_one)
{
	ScanTable s(3);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	ScanTable copyt(s);
	EXPECT_EQ(s.GetCount(), copyt.GetCount());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Sort_Table, can_create_table)
{
	ASSERT_NO_THROW(Sortable *s = new Sortable(2));
}

TEST(Sort_Table, can_copy_table)
{
	Sortable s(2);
	ASSERT_NO_THROW(Sortable cps(s));
}

TEST(Sort_Table, can_search)
{
	Sortable *s = new Sortable(3);
	s->insert(1, new TData("a"));
	s->insert(5, new TData("b"));
	TabRecord* t;
	ASSERT_NO_THROW(t = s->search(5));
}

TEST(Sort_Table, can_push)
{
	Sortable s(2);
	ASSERT_NO_THROW(s.insert(3, new TData("abc")));
}

//TEST(Sort_Table, can_remove)
//{
//	Sortable *s = new Sortable(2);
//	s->insert(1, new TData("a"));
//	s->insert(5, new TData("b"));
//	ASSERT_NO_THROW(s->erase(5));
//}

//TEST(Sort_Table, can_sort)
//{
//	Sortable s(2);
//	s.insert(1, new TData("a"));
//	s.insert(5, new TData("b"));
//	ASSERT_NO_THROW(s.Sorting());
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Aray_Hash_Table, can_create_table)
{
	ASSERT_NO_THROW(Table *ht = new ArrayHashTable(5, 2));
}

TEST(Aray_Hash_Table, can_search)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->insert(1, new TData("b"));
	ASSERT_NO_THROW(ht->search(1));
}
 
TEST(Aray_Hash_Table, can_push)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ASSERT_NO_THROW(ht->insert(1, new TData("b")));
}

TEST(Aray_Hash_Table, can_remove)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->insert(1, new TData("b"));
	ASSERT_NO_THROW(ht->erase(1));
}

TEST(Aray_Hash_Table, can_reset)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->insert(1, new TData("b"));
	ASSERT_NO_THROW(ht->reset());
}

TEST(Aray_Hash_Table, can_get_next)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->insert(1, new TData("b"));
	ASSERT_NO_THROW(ht->GetNext());
}

TEST(Aray_Hash_Table, insert_increases_count)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	size_t expCount = ht->GetCount();
	ht->insert(2, new TData("b"));
	EXPECT_EQ(expCount, ht->GetCount());
}
TEST(Aray_Hash_Table, remove_decreases_count)
{
	ArrayHashTable s(3, 1);
	s.insert(1, new TData("a"));
	s.insert(2, new TData("b"));
	s.insert(3, new TData("c"));
	size_t expCount = s.GetCount() - 1;
	s.erase(1);
	EXPECT_EQ(expCount, s.GetCount());
}
