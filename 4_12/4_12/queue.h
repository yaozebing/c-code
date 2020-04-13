#pragma once
#include<stdio.h>
#include<stdlib.h>
// 支持动态增长的栈


typedef int QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;
// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
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
// 队尾入队列 
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
// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	if (QueueEmpty)
	{
		return 0;
	}
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}
// 销毁队列 
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

