#include"stack.h"
#define DEFSTACKSIZE 100

//void CheckCapacity(Stack* ps)
//{
//	if (ps->size >= ps->capacity)
//	{
//		ps->capacity *= 2;
//		ps->array = (STDataType *)realloc(ps->array, ps->capacity * sizeof(STDataType));
//	}
//}
//
//void StackInit(Stack* ps)
//{
//	ps->array = (STDataType *)calloc(DEFSTACKSIZE, sizeof(STDataType));
//	ps->capacity = DEFSTACKSIZE;
//	ps->size = 0;
//}
//
//void StackPush(Stack* ps, STDataType x)
//{
//	CheckCapacity(ps);
//
//	ps->array[ps->size] = x;
//	ps->size++;
//}
//
//void StackPop(Stack* ps)
//{
//	if (ps->size == 0)
//	{
//		return;
//	}
//	ps->size--;
//}
//
//STDataType StackTop(Stack* ps)
//{
//	if (ps->size == 0)
//	{
//		return (STDataType)0;
//	}
//	return ps->array[ps->size - 1];
//}
//
//int StackEmpty(Stack* ps)
//{
//	return ps->size == 0;
//}
//
//int StackSize(Stack* ps)
//{
//	return ps->size;
//}
//
//void StackDestory(Stack* ps)
//{
//	if (ps->array)
//	{
//		free(ps->array);
//		ps->array = NULL;
//		ps->size = 0;
//		ps->capacity = 0;
//	}
//}


QueueNode * BuyQueueNode(QuDataType x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}

void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}

void QueuePush(Queue* q, QuDataType x)
{
	QueueNode * cur = BuyQueueNode(x);

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

void QueuePop(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}
	QueueNode* tmp = q->_front->_next;
	free(q->_front);
	q->_front = tmp;
}

QuDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}

QuDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}

int QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}

int QueueSize(Queue* q)
{
	QListNode * cur;
	int count = 0;
	for (cur = q->_front; cur; cur = cur->_next)
	{
		count++;
	}
	return count;
}

void QueueDestory(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}

	while (q->_front)
	{
		QueuePop(q);
	}
}
