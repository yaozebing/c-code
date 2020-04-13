#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
	int* queue;
	int front;
	int rear;
	int k
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue obj;
	obj.queue = (int*)malloc((k + 1) * sizeof(int));//给数组开辟空间，k+1是为了进行判满
	obj.k = k;
	obj.front = 0;
	obj.rear = 0;
	return &obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{

		obj->queue[obj->rear++] = value;
		if (obj->rear == obj->k)
		{
			obj->rear = 0;
		}
		return true;
	}
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	else
	{
		obj->front++;
		if (obj->front == obj->k)
		{
			obj->front = 0;
		}
		return true;
	}
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->queue[obj->front];
	}
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		if (obj->rear == 0)
		{
			return obj->queue[obj->k - 1];
		}
		else
		{
			return obj->queue[obj->rear - 1];
		}
	}
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % obj->k == 0;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	obj->front = obj->rear = 0;
	obj->k = 0;
	free(obj->queue);
}