typedef int Type;
typedef struct Stack
{
	Type* _array;
	int _size;
	int _capacity;
}Stack;
typedef struct {
	Stack _pop;
	Stack _push;
} MyQueue;

void stackInit(Stack* st, int n)
{
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;
}
void stackPush(Stack* st, Type data)
{
	//�������
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
//	β��
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
	//βɾ
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)
{
	return st->_array[st->_size - 1];
}
int stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)
{
	if (st->_size == 0)
		return 1;
	return 0;
}


bool isValid(char * s) {
	Stack st;
	stackInit(&st, 100);
	static char arr[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	while (*s != '\0')
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