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
		//�����ǰ�ڵ�����Ҫɾ���Ľڵ�
		if (cur->val == val)
		{
			//���ȱ�����һ���ڵ�
			struct ListNode* next = cur->next;
			//���ɾ����Ϊͷ�ڵ㣬����ͷ�ڵ�
			//�����õ�ǰ�ڵ��ǰ���ڵ�����next�ڵ�
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			//�ͷŵ�ǰ�ڵ㣬��curָ��next
			free(cur);
			cur = next;
		}
		else
		{
			//���cur������Ҫɾ���Ľڵ㣬�����prev,cur
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}
