#include"stack.h"
int  main()
{
	Stack ps;
	StackInit(&ps);

	StackPush(&ps, 1);
	StackPop(&ps);

	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);

	Queue q;
	QueueInit(&q);

	return 0;
}