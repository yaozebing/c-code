//解题思路：
//通过一个定长数组实现循环队列
//入队：首先要判断队列是否已满，再进行入队的操作，入队操作需要考虑索引循环的问题，当索引越界，需要让它变成最小值
//出队：首先要判断队列是否为空，再进行出队操作，出队也需要考虑索引循环的问题
//判空： 队头 == 队尾
//判满： 队尾 + 1 == 队头
#include"MyCircularQueue.h"
typedef struct {
	int* queue;
	int front;
	int rear;
	int k
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
//创建一个可以存放k个元素的循环队列，实际申请的空间为k + 1
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->queue = (int*)malloc(sizeof(int)*(k + 1));
	pcq->front = 0;
	pcq->rear = 0;
	pcq->k = k;

	return pcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//判满
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
	{
		return false;
	}
	//队尾入队
	obj->queue[obj->rear++] = value;
	//如果队尾越界，更新为最小值
	if (obj->rear == obj->k + 1)
		obj->rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//判空
	if (obj->front == obj->rear)
		return false;
	//队头出队
	++obj->front;
	//如果队头越界，更新为最小值
	if (obj->front == obj->k + 1)
		obj->front = 0;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	else
		return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	//队尾元素再rear索引的前一个位置，如果rear为0，
	//则队尾元素在数组的最后一个位置
	if (obj->rear == 0)
		return obj->queue[obj->k];
	else
		return obj->queue[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);
}