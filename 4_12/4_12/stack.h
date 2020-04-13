#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_capacity = 100;//����ջ������
	ps->_a = (STDataType*)malloc(ps->_capacity * sizeof(STDataType));//���������ռ�
	ps->_top = 0;//��ջ�����ڳ�ʼλ��
}
// ��ջ 
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
// ��ջ 
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))//�ж��Ƿ�Ϊ��
	{
		return 0;
	}
	else
	{
		ps->_a--;//��ջ��ǰ��
	}
}
// ��ȡջ��Ԫ�� 
STDataType StackPeek(Stack* ps)
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
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return sizeof(ps->_a) / sizeof(int);
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}
// ����ջ 
//void StackDestroy(Stack* ps)
//{
//	if (ps->_a)
//	{
//		free(ps->_a);
//		ps->_top == 0;
//		ps->_a = NULL;
//		ps->_capacity = 0;
//	}
//}