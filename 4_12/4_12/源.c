typedef struct {
	//���ջ
	Stack pushST;
	//����ջ
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
	//���ջ������ջ����
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//�������ջΪ�գ��������ջ��Ԫ��
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	int front = StackTop(&obj->popST);
	//����ջ���г��Ӳ���
	StackPop(&obj->popST);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	//�����ڳ��Ӳ���
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
