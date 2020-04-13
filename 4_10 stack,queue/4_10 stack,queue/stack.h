#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_capacity = 100;//设置栈的容量
	ps->_a = (STDataType*)malloc(ps->_capacity * sizeof(STDataType));//给数组分配空间
	ps->_top = 0;//将栈顶放在初始位置
}
// 入栈 
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
// 出栈 
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))//判断是否为空
	{
		return 0;
	}
	else
	{
		ps->_a--;//将栈顶前移
	}
}
// 获取栈顶元素 
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
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_a;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}
// 销毁栈 
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

