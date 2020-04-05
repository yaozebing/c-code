#pragma once
typedef int SLTDateType;

typedef struct SListNode

{

	SLTDateType data;

	struct SListNode* next;

}SListNode;

SListNode* BuySListNode(SLTDateType x)

{

	SListNode* s = (SListNode*)malloc(sizeof(SListNode));

	s->data = x;

	s->next = NULL;

	return s;

}

// 单链表打印

void SListPrint(SListNode* plist)

{

	SListNode* cur = plist;

	while (cur)

	{

		printf("%d ", cur->data);

		cur = cur->next;

	}

	printf("NULL\n");

}

// 单链表尾插

void SListPushBack(SListNode** pplist, SLTDateType x)

{

	SListNode* cur = BuySListNode(x);

	if (*pplist == NULL)

	{

		*pplist = cur;

	}

	else

	{

		SListNode* tail = *pplist;

		while (tail->next != NULL)

		{

			tail = tail->next;

		}

		tail->next = cur;

	}

}

// 单链表的头插

void SListPushFront(SListNode** pplist, SLTDateType x)

{

	SListNode* cur = BuySListNode(x);

	if (*pplist == NULL)

	{

		*pplist = cur;

	}

	else

	{

		cur->next = *pplist;

		*pplist = cur;

	}

}

// 单链表的尾删

void SListPopBack(SListNode** pplist)

{

	SListNode* cur = NULL;

	SListNode* tail = *pplist;

	if (*pplist == NULL || tail->next == NULL)

	{

		free(pplist);

		*pplist = NULL;

	}

	else

	{

		while (tail->next != NULL)

		{

			cur = tail;

			tail = tail->next;

		}

		free(tail);

		tail = NULL;

		cur->next = NULL;

	}

}

// 单链表头删

void SListPopFront(SListNode** pplist)

{

	SListNode* cur = *pplist;

	if (cur == NULL)

	{

		return 0;

	}

	else if (cur->next == NULL)

	{

		free(cur);

		*pplist = NULL;

	}

	else

	{

		SListNode* next = cur->next;

		*pplist = next;

		free(cur);

	}

}

// 单链表查找

SListNode* SListFind(SListNode* plist, SLTDateType x)

{

	SListNode* cur = plist;

	//if (cur == NULL || cur->next == NULL)

	//{

	//	printf("no this num\n");

	//}

	//else

	//{

	while (cur)

	{

		if (cur->data == x)

		{

			return cur;

		}

		cur = cur->next;

	}

	printf("no this num\n");

	//}

}

// 单链表在pos位置之后插入x

// 分析思考为什么不在pos位置之前插入？

//找不见

void SListInsertAfter(SListNode* pos, SLTDateType x)

{

	assert(pos);

	SListNode* cur = BuySListNode(x);

	cur->next = pos->next;

	pos->next = cur;

}

// 单链表删除pos位置之后的值

// 分析思考为什么不删除pos位置？

//找不见

void SListEraseAfter(SListNode* pos)

{

	assert(pos);

	if (pos->next != NULL)

	{

		SListNode* cur = pos->next;

		pos->next = cur->next;

		free(cur);

	}

}