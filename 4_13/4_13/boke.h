#include<stdio.h>
#include<stdlib.h>

typedef int Type;//定义数据类型
typedef struct Stack//定义栈的结构体内容
{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;
typedef struct //定义栈队列的双栈
{
	Stack _pop;
	Stack _push;
} MyQueue;
//栈的基本操作
void stackInit(Stack* st, size_t n)//栈的初始化
{
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;
}
void stackPush(Stack* st, Type data)//进栈
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
void stackPop(Stack* st)//出栈
{
	//尾删
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)//查看栈顶元素
{
	return st->_array[st->_size - 1];
}
size_t stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)//查看栈是否为空
{
	if (st->_size == 0)
		return 1;
	return 0;
}

bool isValid(char * s) {
	Stack st;//申请栈
	stackInit(&st, 100);//初始化栈
	static char arr[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	while (*s != '\0')//进行循环
	{
		int i = 0;
		//寻找左括号
		for (i = 0; i < 3; i++)
		{
			if (*s == arr[i][0])
			{
				stackPush(&st, *s);
				s++;
				break;
			}
		}
		//若是右括号，跳出
		if (i == 3)
		{
			if (stackEmpty(&st))
			{
				return false;
			}
			else
			{
				//查看右括号
				for (i = 0; i < 3; i++)
				{
					if (*s == arr[i][1])
					{
						if (stackTop(&st) == arr[i][0])
						{
							stackPop(&st);
							s++;
							break;
						}
						else
						{
							return false;
						}
					}
				}

			}
		}
	}
	if (stackEmpty(&st))
	{
		return true;
	}
	else
	{
		return false;
	}
}