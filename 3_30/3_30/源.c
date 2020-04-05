#include"slist.h"
//
//int main()
//{
//	SListNode* plist;
//	plist = NULL;
//	//SListPrint(plist);
//
//	SListPushBack(&plist, 5);
//	SListPrint(plist);
//	SListPushBack(&plist, 6);
//	SListPrint(plist);
//	SListPushBack(&plist, 7);
//	SListPrint(plist);
//
//	SListPushFront(&plist, 3);
//	SListPrint(plist);
//	SListPushFront(&plist, 2);
//	SListPrint(plist);
//	SListPushFront(&plist, 1);
//	SListPrint(plist);
//
//	//SListPopBack(&plist);
//	//SListPrint(plist);
//	//SListPopBack(&plist);
//	//SListPrint(plist);
//
//	//SListPopFront(&plist);
//	//SListPrint(plist);
//	//SListPopFront(&plist);
//	//SListPrint(plist);
//
//	//SListFind(plist, 3);
//	//SListFind(plist, 6);
//	//SListFind(plist, 9);
//
//	//SListNode* cur = SListFind(plist, 3);
//	//
//	//SListInsertAfter(cur, 4);
//	//SListPrint(plist);
//
//	//SListEraseAfter(cur);
//	//SListPrint(plist);
//	//SListEraseAfter(cur);
//	//SListPrint(plist);
//	//SListEraseAfter(cur);
//	//SListPrint(plist);
//
//	//Test();
//	SListDestory(&plist);
//	SListPrint(plist);
//
//	return 0;
//}
////void SingleListInsertAfter(SListNode* node, int val)
////{
////	SListNode* cur = BuySListNode(x);
////	SListNode* next = node->next;
////	cur->next = next;
////	node->next = cur;
////}
////void SListEraseAfter(SListNode* pos)
////{
////	SListNode* cur = pos->next;
////	
////}
////
////SListNode* find(SListNode* plist, int data)
////{
////	SListNode* cur = plist;
////	while (cur->next)
////	{
////		if (cur->data == data)
////		{
////
////		}
////	}
////}
////
////
////
////struct ListNode* reverseList(struct ListNode* head) 
////{
////	ListNode* cur = head;
////	
////}
////ListNode* cur = plisthead;
////while (k > 0 && cur != NULL) {
////	cur = cur->next;
////	k--;
////}
////if (cur == NULL)
////{
////	return;
////}
////else {
////	ListNode* slow = plistHead;
////	while (k > 0)
////	{
////		cur = cur->next;
////		slow = slow->next;
////		k--;
////	}
////	return slow;
////}
////
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;

	struct ListNode* cur = head;
	struct ListNode* prev = NULL;

	while (cur)
	{
		//如果当前节点是需要删除的节点
		if (cur->val == val)
		{
			//首先保存下一个节点
			struct ListNode* next = cur->next;
			//如果删除的为头节点，更新头节点
			//否则让当前节点的前趋节点链接next节点
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			//释放当前节点，让cur指向next
			free(cur);
			cur = next;
		}
		else
		{
			//如果cur不是需要删除的节点，则更新prev,cur
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}
