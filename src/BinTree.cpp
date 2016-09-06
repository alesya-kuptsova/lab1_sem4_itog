#include "BinTree.h"

//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//
//
//int keyCompareFunc(TKey keyzn, TKey key)
//{
//	TKey rez = keyzn - key;
//	if (rez < 0)
//		return -1;
//	if (rez == 0)
//		return 0;
//	if (rez > 0)
//		return 1;
//}
//
//int znach_insert(struct Node **rootNode, TKey key, TValue value)
//{
//	/* znach_insert() ��������� ����� ������.
//	� ������, ���� ���� key ��� ������� � �������, �� ������ ����������� ��� value */
//
//	if (*rootNode == 0)
//	{
//		struct Node *newNode;
//
//		newNode->znach.key = key;
//		newNode->znach.value = value;
//		newNode->left = NULL;
//		newNode->right = NULL;
//		// ������ ������, ����� ������� ���� ����� ������
//		*rootNode = newNode;
//	}
//	else
//	{
//		struct Node *curNode = *rootNode; // ������� ����
//		int iCmp; // ������ �������� ������� ��������� ����� �������� ���� � ����� �������
//
//		while (1)
//		{
//			iCmp = keyCompareFunc(curNode->znach.key, key);
//
//			if (iCmp < 0)
//			{
//				// ���� ������� ������ ����� �������� ����
//				if (curNode->left != NULL)
//					curNode = curNode->left;
//				else
//				{
//					struct Node *newNode;// = malloc(sizeof (*newNode));
//
//					newNode->znach.key = key;
//					newNode->znach.value = value;
//					newNode->left = NULL;
//					newNode->right = NULL;
//
//					curNode->left = newNode;
//					break;
//				}
//			}
//			else if (iCmp > 0)
//			{
//				// ���� ������� ������ ����� �������� ����
//				if (curNode->right != NULL)
//					curNode = curNode->right;
//				else
//				{
//					struct Node *newNode;
//
//					newNode->znach.key = key;
//					newNode->znach.value = value;
//					newNode->left = NULL;
//					newNode->right = NULL;
//
//					curNode->right = newNode;
//					break;
//				}
//			}
//			else
//			{
//				// ���� ������� ����� ����� �������� ����. � ����� ������ ������ ��������� �������� ����
//				curNode->znach.value = value;
//				break;
//			}
//		}
//	}
//
//	return 0;
//}
//
//struct Znach * znach_has_key(struct Node *rootNode, TKey key)
//{
//	/* znach_has_key() ��������� ������� �� � ������� ���� key
//	� ������ ���������� �������� ���������� NULL,
//	����� ��������� Znach, ���������� ������� ���� */
//
//	if (!rootNode) // ���� ������� ����, �� �� ������ �� �����
//		return NULL;
//
//	struct Node *curNode = rootNode; // ������� ����
//	int iCmp; // ������ ��������� ��������� ����� �������� ���� � ��������
//
//
//	while (1)
//	{
//		iCmp = keyCompareFunc(curNode->znach.key, key);
//
//		if (iCmp < 0)
//		{
//			if (curNode->left == NULL)
//				return NULL; // ���� �� ������
//			else
//				curNode = curNode->left;
//		}
//		else if (iCmp > 0)
//		{
//			if (curNode->right == NULL)
//				return NULL; // ���� �� ������
//			else
//				curNode = curNode->right;
//		}
//		else
//		{
//			// ���� �� �����, �� ���� ������
//			return &curNode->znach;
//		}
//	}
//}
//
//int znach_delete(struct Node ** const rootNode, TKey key)
//{
//	struct Node *parentNode = NULL;
//	struct Node *curNode = *rootNode;
//	int iCmp;
//
//	while (1)
//	{
//		iCmp = keyCompareFunc(curNode->znach.key, key);
//
//		if (iCmp < 0)
//		{
//			if (curNode->left != NULL)
//			{
//				parentNode = curNode;
//				curNode = curNode->left;
//			}
//		}
//		else if (iCmp > 0)
//		{
//			if (curNode->right != NULL)
//			{
//				parentNode = curNode;
//				curNode = curNode->right;
//			}
//		}
//		else
//		{
//			// ���� �� �����, �� ���� ������. ������� �� �����
//			break;
//		}
//	} // end while (1)
//
//	if (!curNode->left && !curNode->right) // ������� ���� ��� ��������
//	{
//		if (!parentNode) // ������� ���� �������
//			*rootNode = NULL;
//		else
//		{
//			if (parentNode->left == curNode)
//				parentNode->left = NULL;
//			else
//				parentNode->right = NULL;
//		}
//
//		free(curNode);
//	}
//	else if (curNode->left && curNode->right) // ���� ��������� ���� ������� ��� �������
//	{
//		struct Node *leaf = curNode->left; // ��� ���������� ������
//		struct Node *leafParent = curNode;
//		// ���� ������ ������ � ������ ���������� ��������
//		while (leaf->left || leaf->right) // ���� � �������� ���� ���� ����
//		{
//			leafParent = leaf;
//
//			if (leaf->left)
//				leaf = leaf->left;
//			else
//				leaf = leaf->right;
//		}
//
//		if (leafParent->left == leaf) // ������� ���������� � �������� � ��� ��������
//			leafParent->left = NULL;
//		else
//			leafParent->right = NULL;
//
//		leaf->left = curNode->left;
//		leaf->right = curNode->right;
//
//		if (parentNode) // ���� ������� �� ����� ������ ������
//		{
//			// �������� ��������� ������� ������� �� ��� ���������
//			if (parentNode->left == curNode)
//				parentNode->left = leaf;
//			else
//				parentNode->right = leaf;
//		}
//		else // ���� ������� ����� ������ ������
//		{
//			*rootNode = leaf;
//		}
//
//		free(curNode);
//	}
//	else // ���� � ���������� ���� ������ ���� �������
//	{
//		if (parentNode)
//		{
//			if (parentNode->left == curNode)
//				parentNode->left = curNode->left ? curNode->left : curNode->right;
//			else
//				parentNode->right = curNode->left ? curNode->left : curNode->right;
//		}
//		else // ������� ����� ������ ������
//		{
//			*rootNode = parentNode->left = curNode->left ? curNode->left : curNode->right;
//		}
//
//		free(curNode);
//	}
//
//	return 0;
//}