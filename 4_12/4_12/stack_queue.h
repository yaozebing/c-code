#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char Type;

typedef struct Stack
{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;
typedef struct {
	Stack _pushstack;
	Stack _popstack;
} MyQueue;

void StackInit(Stack* st)
{
	st->_capacity = 100;
	st->_array = (Type*)malloc(sizeof(Type)* st->_capacity);
	st->_size = 0;
}
void StackPush(Stack* st, Type data)
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
void StackPop(Stack* st)
{
	//尾删
	if (st->_size)
		--st->_size;
}
Type StackTop(Stack* st)
{
	return st->_array[st->_size - 1];
}
int StackEmpty(Stack* st)
{
	if (st->_size == 0)
		return 1;
	return 0;
}

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&mq->_popstack);
	StackInit(&mq->_pushstack);
	return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->_pushstack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//如果pop栈为空
	if (StackEmpty(&obj->_popstack) == 1)
	{
		//将push栈的数据全部导入pop栈
		while (StackEmpty(&obj->_pushstack) == 0)
		{
			StackPush(&obj->_popstack, StackTop(&obj->_pushstack));
			StackPop(&obj->_pushstack);
		}
	}
	int front = StackTop(&obj->_popstack);
	StackPop(&obj->_popstack);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->_popstack))
	{
		while (StackEmpty(&obj->_pushstack) == 0)
		{
			//将push栈的数据全部移动到pop栈
			StackPush(&obj->_popstack, StackTop(&obj->_pushstack));
			StackPop(&obj->_pushstack);
		}
	}
	return StackTop(&obj->_popstack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(&obj->_pushstack) == 1 && StackEmpty(&obj->_popstack) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myQueueFree(MyQueue* obj) {
	free(&obj->_popstack);//释放pop栈
	free(&obj->_pushstack);//释放push栈
	free(obj);
}
