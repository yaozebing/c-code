#pragma once
#include"标头.h"

void stackInit(Stack* st, size_t n)
{
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;
}

void stackPush(Stack* st, Type data)
{
	//检查容量
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
	//尾插
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
	//尾删
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)
{
	return st->_array[st->_size - 1];
}

size_t stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)
{
	if (st->_size == 0)
		return 1;
	return 0;
}

void stackDestory(Stack* st)
{
	free(st->_array);
	st->_array = NULL;
	st->_size = st->_capacity = 0;
}




void queueInit(Queue* q)
{
	//初始化空队列
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

QNode* creatNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//队尾入队
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//空队列
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}

//队头出队
void queuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//删除之后是否为空表
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}

//获取队头元素
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}
//获取队尾元素
QDataType queueBack(Queue* q)
{
	return q->_rear->_data;
}

int queueSize(Queue* q)
{
	/*
	int num = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		++num;
		cur = cur->_next;
	}
	return num;
	*/
	return q->_size;
}

int queueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

void queueDestory(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
