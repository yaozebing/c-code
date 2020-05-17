#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
 //带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;//数据域
	struct ListNode* _next;//后驱指针
	struct ListNode* _prev;//前驱指针
}ListNode;
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));//创建一个ListNode类型的指针，并为这个指针指向的位置开辟一个ListNode大小的空间
	pHead->_next = pHead;//后驱指向头节点自己
	pHead->_prev = pHead;//前驱指向头节点
	return pHead;//返回头指针，头指针指向的空间指是头节点
}
//创建节点
ListNode* NodeCreate(LTDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->_next = NULL;
	Node->_prev = NULL;
	Node->_data = x;
	return Node;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	if (pHead->_next == pHead)//检查是否为空链表
	{
		return NULL;
	}
	ListNode* cur = pHead->_next;//创建一个移动的指针
	while (cur != pHead)//pHead是固定的，cur不停向后移动，会因为循环而相等
	{
		printf("%d ", cur->_data);
		cur = cur->_next;//将指针不断向后移动
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* node = NodeCreate(x);//创建新节点
	ListNode* prev = pHead->_prev;//保存原来的尾节点
	prev->_next = node;//将原来的尾节点的后驱指向新的尾节点
	node->_next = pHead;//将新尾节点的后驱指向头节点
	node->_prev = prev;//将新尾节点的前驱指向原来的尾节点
	pHead->_prev = node;//将头节点的前驱指向新的尾节点
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	if (pHead->_next == pHead)//判断是否为空链表
	{
		return NULL;
	}
	ListNode* tail = pHead->_prev;//保存原尾节点
	pHead->_prev = tail->_prev;//将头节点的前驱指向原尾节点的前驱
	tail->_prev->_next = pHead;//将原尾节点的前驱的后驱指向头节点
	free(tail);//释放原尾节点的空间
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* next = pHead->_next;//保存头节点的下一个节点地址
	ListNode* node = NodeCreate(x);//创建节点
	node->_next = pHead->_next;//将插入节点的前后驱指向头节点和头节点的下一个节点
	node->_prev = pHead;
	next->_prev = node;//将之前的首元节点的前驱指向新的首元节点
	if (pHead->_next == pHead)//判断是否为空链表
	{
		pHead->_prev = node;//空链表要把头节点的前驱改变
	}
	pHead->_next = node;//改变头节点的后驱
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	if (pHead->_next == pHead)//判断是否为空链表
	{
		return NULL;
	}
	ListNode* head = pHead->_next;//保存原首元节点
	pHead->_next = head->_next;//将头结点的后驱指向新首元节点
	head->_next->_prev = pHead;//将新首元节点的前驱指向头节点
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	if (pHead->_next == pHead)
	{
		return NULL;
	}
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			printf("got it\n");
			return cur;
		}
		cur = cur->_next;
	}
	printf("no this num\n");
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->_prev;//保存pos前的节点地址
	ListNode* node = NodeCreate(x);//创建新节点
	prev->_next = node;//将prev的后驱指向新节点
	node->_next = pos;//将新节点的后驱指向pos
	node->_prev = prev;//将新节点的前驱指向prev
	pos->_prev = node;//将pos的前指向新节点
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;//保存pos的前驱节点的地址
	ListNode* next = pos->_next;//保存pos的后驱节点的地址
	prev->_next = pos->_next;//将prev的后驱指向pos的后驱
	next->_prev = pos->_prev;//将next的前驱指向pos的前驱
	free(pos);//释放pos
}
//typedef struct Queue
//{
//	struct Queue *front;
//	struct Queue *rear;
//}Queue;
//void queuepop(Queue* q)
//{
//	if (q->front == NULL)
//	{
//		return NULL;
//	}
//	Qnode* next = q->front->next;
//	free(q->front);
//	q = next;
//	q->front = q;
//}

void delete(ListNode* pnode) {
	if (pnode->_next == NULL) {
		return false;
	}
	ListNode* next = pnode->_next;
	free(pnode);
	pnode = next;
	return true;
}