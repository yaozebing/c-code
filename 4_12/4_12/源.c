typedef struct {
	//入队栈
	Stack pushST;
	//出队栈
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	MyQueue* pqueue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&pqueue->pushST, maxSize);
	StackInit(&pqueue->popST, maxSize);
	return pqueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//入队栈进行入栈操作
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//如果出队栈为空，导入入队栈的元素
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	int front = StackTop(&obj->popST);
	//出队栈进行出队操作
	StackPop(&obj->popST);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	//类似于出队操作
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) == 0
		&& StackEmpty(&obj->popST) == 0;
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);

	free(obj);
}
