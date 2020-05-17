#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
 //��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;//������
	struct ListNode* _next;//����ָ��
	struct ListNode* _prev;//ǰ��ָ��
}ListNode;
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));//����һ��ListNode���͵�ָ�룬��Ϊ���ָ��ָ���λ�ÿ���һ��ListNode��С�Ŀռ�
	pHead->_next = pHead;//����ָ��ͷ�ڵ��Լ�
	pHead->_prev = pHead;//ǰ��ָ��ͷ�ڵ�
	return pHead;//����ͷָ�룬ͷָ��ָ��Ŀռ�ָ��ͷ�ڵ�
}
//�����ڵ�
ListNode* NodeCreate(LTDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->_next = NULL;
	Node->_prev = NULL;
	Node->_data = x;
	return Node;
}
// ˫����������
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
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	if (pHead->_next == pHead)//����Ƿ�Ϊ������
	{
		return NULL;
	}
	ListNode* cur = pHead->_next;//����һ���ƶ���ָ��
	while (cur != pHead)//pHead�ǹ̶��ģ�cur��ͣ����ƶ�������Ϊѭ�������
	{
		printf("%d ", cur->_data);
		cur = cur->_next;//��ָ�벻������ƶ�
	}
	printf("\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* node = NodeCreate(x);//�����½ڵ�
	ListNode* prev = pHead->_prev;//����ԭ����β�ڵ�
	prev->_next = node;//��ԭ����β�ڵ�ĺ���ָ���µ�β�ڵ�
	node->_next = pHead;//����β�ڵ�ĺ���ָ��ͷ�ڵ�
	node->_prev = prev;//����β�ڵ��ǰ��ָ��ԭ����β�ڵ�
	pHead->_prev = node;//��ͷ�ڵ��ǰ��ָ���µ�β�ڵ�
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	if (pHead->_next == pHead)//�ж��Ƿ�Ϊ������
	{
		return NULL;
	}
	ListNode* tail = pHead->_prev;//����ԭβ�ڵ�
	pHead->_prev = tail->_prev;//��ͷ�ڵ��ǰ��ָ��ԭβ�ڵ��ǰ��
	tail->_prev->_next = pHead;//��ԭβ�ڵ��ǰ���ĺ���ָ��ͷ�ڵ�
	free(tail);//�ͷ�ԭβ�ڵ�Ŀռ�
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* next = pHead->_next;//����ͷ�ڵ����һ���ڵ��ַ
	ListNode* node = NodeCreate(x);//�����ڵ�
	node->_next = pHead->_next;//������ڵ��ǰ����ָ��ͷ�ڵ��ͷ�ڵ����һ���ڵ�
	node->_prev = pHead;
	next->_prev = node;//��֮ǰ����Ԫ�ڵ��ǰ��ָ���µ���Ԫ�ڵ�
	if (pHead->_next == pHead)//�ж��Ƿ�Ϊ������
	{
		pHead->_prev = node;//������Ҫ��ͷ�ڵ��ǰ���ı�
	}
	pHead->_next = node;//�ı�ͷ�ڵ�ĺ���
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	if (pHead->_next == pHead)//�ж��Ƿ�Ϊ������
	{
		return NULL;
	}
	ListNode* head = pHead->_next;//����ԭ��Ԫ�ڵ�
	pHead->_next = head->_next;//��ͷ���ĺ���ָ������Ԫ�ڵ�
	head->_next->_prev = pHead;//������Ԫ�ڵ��ǰ��ָ��ͷ�ڵ�
}
// ˫���������
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
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->_prev;//����posǰ�Ľڵ��ַ
	ListNode* node = NodeCreate(x);//�����½ڵ�
	prev->_next = node;//��prev�ĺ���ָ���½ڵ�
	node->_next = pos;//���½ڵ�ĺ���ָ��pos
	node->_prev = prev;//���½ڵ��ǰ��ָ��prev
	pos->_prev = node;//��pos��ǰָ���½ڵ�
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;//����pos��ǰ���ڵ�ĵ�ַ
	ListNode* next = pos->_next;//����pos�ĺ����ڵ�ĵ�ַ
	prev->_next = pos->_next;//��prev�ĺ���ָ��pos�ĺ���
	next->_prev = pos->_prev;//��next��ǰ��ָ��pos��ǰ��
	free(pos);//�ͷ�pos
}
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

void delete(ListNode* pnode) {
	if (pnode->_next == NULL) {
		return false;
	}
	ListNode* next = pnode->_next;
	free(pnode);
	pnode = next;
	return true;
}