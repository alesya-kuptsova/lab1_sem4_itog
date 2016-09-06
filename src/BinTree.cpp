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
//	/* znach_insert() вставляет новую запись.
//	В случае, если ключ key уже имеется в словаре, то просто обновляется его value */
//
//	if (*rootNode == 0)
//	{
//		struct Node *newNode;
//
//		newNode->znach.key = key;
//		newNode->znach.value = value;
//		newNode->left = NULL;
//		newNode->right = NULL;
//		// пустое дерево, новый элемент есть новый корень
//		*rootNode = newNode;
//	}
//	else
//	{
//		struct Node *curNode = *rootNode; // текущий узел
//		int iCmp; // хранит значение функции сравнения ключа текущего узла и ключа вставки
//
//		while (1)
//		{
//			iCmp = keyCompareFunc(curNode->znach.key, key);
//
//			if (iCmp < 0)
//			{
//				// ключ вставки меньше ключа текущего узла
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
//				// ключ вставки больше ключа текущего узла
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
//				// ключ вставки равен ключу текущего узла. В таком случае просто обновляем значение узла
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
//	/* znach_has_key() проверяет имеется ли в словаре ключ key
//	в случае отсутствия такового возвращает NULL,
//	иначе структуру Znach, содержащий искомый ключ */
//
//	if (!rootNode) // если словарь пуст, то мы ничего не нашли
//		return NULL;
//
//	struct Node *curNode = rootNode; // текущий узел
//	int iCmp; // хранит результат сравнения ключа текущего узла и искомого
//
//
//	while (1)
//	{
//		iCmp = keyCompareFunc(curNode->znach.key, key);
//
//		if (iCmp < 0)
//		{
//			if (curNode->left == NULL)
//				return NULL; // ключ не найден
//			else
//				curNode = curNode->left;
//		}
//		else if (iCmp > 0)
//		{
//			if (curNode->right == NULL)
//				return NULL; // ключ не найден
//			else
//				curNode = curNode->right;
//		}
//		else
//		{
//			// если мы здесь, то ключ найден
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
//			// если мы здесь, то ключ найден. Выходим из цикла
//			break;
//		}
//	} // end while (1)
//
//	if (!curNode->left && !curNode->right) // удаляем узел без потомков
//	{
//		if (!parentNode) // удаляем весь словарь
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
//	else if (curNode->left && curNode->right) // если удаляемый узел содежит два потомка
//	{
//		struct Node *leaf = curNode->left; // для нахождения листка
//		struct Node *leafParent = curNode;
//		// цикл поиска листка у дерева удаляемого элемента
//		while (leaf->left || leaf->right) // пока у текущего узла есть дети
//		{
//			leafParent = leaf;
//
//			if (leaf->left)
//				leaf = leaf->left;
//			else
//				leaf = leaf->right;
//		}
//
//		if (leafParent->left == leaf) // удаляем информацию о листочке у его родителя
//			leafParent->left = NULL;
//		else
//			leafParent->right = NULL;
//
//		leaf->left = curNode->left;
//		leaf->right = curNode->right;
//
//		if (parentNode) // если удаляем не самый корень дерева
//		{
//			// заменяем удаляемый элемент листком из его поддерева
//			if (parentNode->left == curNode)
//				parentNode->left = leaf;
//			else
//				parentNode->right = leaf;
//		}
//		else // усли удаляем самый корень дерева
//		{
//			*rootNode = leaf;
//		}
//
//		free(curNode);
//	}
//	else // если у удаляемого узла только один потомок
//	{
//		if (parentNode)
//		{
//			if (parentNode->left == curNode)
//				parentNode->left = curNode->left ? curNode->left : curNode->right;
//			else
//				parentNode->right = curNode->left ? curNode->left : curNode->right;
//		}
//		else // удаляем самый корень дерева
//		{
//			*rootNode = parentNode->left = curNode->left ? curNode->left : curNode->right;
//		}
//
//		free(curNode);
//	}
//
//	return 0;
//}