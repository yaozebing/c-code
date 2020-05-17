#include "��ͷ.h"

void queueInit(Queue* q)
{
	//��ʼ���ն���
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
//��β���
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//�ն���
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}

//��ͷ����
void queuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//ɾ��֮���Ƿ�Ϊ�ձ�
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}

//��ȡ��ͷԪ��
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}
//��ȡ��βԪ��
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
