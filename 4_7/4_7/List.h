#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
 //带头+双向+循环链表增删查改实现
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
ListNode* NodeCreate(LTDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->_next = NULL;
	Node->_prev = NULL;
	Node->_data = x;
	return Node;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
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
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* node = NodeCreate(x);
	ListNode* prev = pHead->_prev;
	prev->_next = node;
	node->_next = pHead;
	node->_prev = prev;
	pHead->_prev = node;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	if (pHead->_next == pHead)
	{
		return NULL;
	}
	ListNode* tail = pHead->_prev;
	pHead->_prev = tail->_prev;
	tail->_prev->_next = pHead;
	free(tail);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* next = pHead->_next;
	ListNode* node = NodeCreate(x);
	node->_next = pHead->_next;
	node->_prev = pHead;
	next->_prev = node;
	if (pHead->_next == pHead)
	{
		pHead->_prev = node;
	}
	pHead->_next = node;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	if (pHead->_next == pHead)
	{
		return NULL;
	}
	ListNode* head = pHead->_next;
	pHead->_next = head->_next;
	head->_next->_prev = pHead;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	if (pHead->_next == pHead)
	{
		return NULL;
	}
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			printf("got it\n");
			return cur;
		}
		cur = cur->_next;
	}
	printf("no this num\n");
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->_prev;
	ListNode* node = NodeCreate(x);
	//printf("%d", prev->_data);
	printf("\n");
	prev->_next = node;
	node->_next = pos;
	node->_prev = prev;
	pos->_prev = node;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = pos->_next;
	next->_prev = pos->_prev;
	free(pos);
}
typedef struct Queue
{
	struct Queue *front;
	struct Queue *rear;
}Queue;
void queuepop(Queue* q)
{
	if (q->front == NULL)
	{
		return NULL;
	}
	Qnode* next = q->front->next;
	free(q->front);
	q = next;
	q->front = q;
}