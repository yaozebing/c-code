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
	//¼ì²éÈÝÁ¿
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
//	Î²²å
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
	//Î²É¾
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
		//Ñ°ÕÒ×óÀ¨ºÅ
		for (i = 0; i < 3; i++)
		{
			if (*s == arr[i][0])
			{
				stackPush(&st, *s);
				s++;
				break;
			}
		}
			//ÈôÊÇÓÒÀ¨ºÅ£¬Ìø³ö
		if (i == 3)
		{
			if (stackEmpty(&st))
			{
				return false;
			}
			else
			{
				//²é¿´ÓÒÀ¨ºÅ
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