#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_capacity = 100;//设置栈的容量
	ps->_a = (STDataType*)malloc(ps->_capacity * sizeof(STDataType));//给数组分配空间
	ps->_top = 0;//将栈顶放在初始位置
}
// 入栈 
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
// 出栈 
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))//判断是否为空
	{
		return 0;
	}
	else
	{
		ps->_a--;//将栈顶前移
	}
}
// 获取栈顶元素 
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
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return sizeof(ps->_a) / sizeof(int);
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}
// 销毁栈 
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