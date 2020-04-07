#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
	list->_next = list;
	list->_prev = list;
	return list;
}
//�����ڵ�
ListNode* Node(LTDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->_next = NULL;
	Node->_prev = NULL;
	Node->_data = x;
	return Node;
}
// ˫����������
void ListDestory(ListNode* pHead);
// ˫�������ӡ
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
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* pHead);
// ˫������ͷ��
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
// ˫������ͷɾ
void ListPopFront(ListNode* pHead);
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
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