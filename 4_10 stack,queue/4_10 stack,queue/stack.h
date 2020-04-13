#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_capacity = 100;//����ջ������
	ps->_a = (STDataType*)malloc(ps->_capacity * sizeof(STDataType));//���������ռ�
	ps->_top = 0;//��ջ�����ڳ�ʼλ��
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity += 100;
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
		//STDataType* NewA = (STDataType*)malloc(sizeof(STDataType)*ps->_capacity);
		//memcpy(NewA, ps->_a, ps->_capacity * sizeof(STDataType));
		//free(ps->_a);
		//ps->_a = NewA;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))//�ж��Ƿ�Ϊ��
	{
		return 0;
	}
	else
	{
		ps->_a--;//��ջ��ǰ��
	}
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return 0;
	}
	else
	{
		return ps->_a[ps->_top - 1];
	}
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_a;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	if (ps->_a)
	{
		free(ps->_a);
		ps->_top == 0;
		ps->_a = NULL;
		ps->_capacity = 0;
	}
}

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

