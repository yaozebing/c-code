#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
	list->_next = list;
	list->_prev = list;
	return list;
}
//创建节点
ListNode* Node(LTDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->_next = NULL;
	Node->_prev = NULL;
	Node->_data = x;
	return Node;
}
// 双向链表销毁
void ListDestory(ListNode* pHead);
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	if (pHead->_next == pHead)
	{
		return NULL;
	}
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* pHead);
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* node = Node(x);
	node->_next = pHead->_next;
	node->_prev = pHead;
	if (pHead->_next == pHead)
	{
		pHead->_prev = node;
	}
	pHead->_next = node;
}
// 双向链表头删
void ListPopFront(ListNode* pHead);
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);

//typedef struct Queue
//{
//	struct Queue *front;
//	struct Queue *rear;
//}Queue;
//void queuepop(Queue* q)
//{
//	if (q->front == NULL)
//	{
//		return NULL;
//	}
//	Qnode* next = q->front->next;
//	free(q->front);
//	q = next;
//	q->front = q;
//}