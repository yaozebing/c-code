#include<stdio.h>
#include<stdlib.h>

typedef int Type;//������������
typedef struct Stack//����ջ�Ľṹ������
{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;
typedef struct //����ջ���е�˫ջ
{
	Stack _pop;
	Stack _push;
} MyQueue;
//ջ�Ļ�������
void stackInit(Stack* st, size_t n)//ջ�ĳ�ʼ��
{
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;
}
void stackPush(Stack* st, Type data)//��ջ
{
	//�������
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
	//β��
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)//��ջ
{
	//βɾ
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)//�鿴ջ��Ԫ��
{
	return st->_array[st->_size - 1];
}
size_t stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)//�鿴ջ�Ƿ�Ϊ��
{
	if (st->_size == 0)
		return 1;
	return 0;
}

bool isValid(char * s) {
	Stack st;//����ջ
	stackInit(&st, 100);//��ʼ��ջ
	static char arr[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	while (*s != '\0')//����ѭ��
	{
		int i = 0;
		//Ѱ��������
		for (i = 0; i < 3; i++)
		{
			if (*s == arr[i][0])
			{
				stackPush(&st, *s);
				s++;
				break;
			}
		}
		//���������ţ�����
		if (i == 3)
		{
			if (stackEmpty(&st))
			{
				return false;
			}
			else
			{
				//�鿴������
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