#pragma once
#include<stdio.h>
#include<stdlib.h>
// ֧�ֶ�̬������ջ


typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;
// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}
QNode* BuyNode(QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = x;
	node->_next = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode* cur = BuyNode(data);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = cur;
	}
	else
	{
		q->_rear->_next = cur;
		q->_rear = cur;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	int n = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	QNode* next = q->_front->_next;
	while (q->_front)
	{
		QueuePop(q);
	}
}

