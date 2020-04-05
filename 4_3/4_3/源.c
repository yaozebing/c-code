#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			struct ListNode* next = cur->next;
//			if (prev == NULL)
//			{
//				head = next;
//			}
//			else
//			{
//				prev->next = next;
//			}
//			free(cur);
//			cur = next;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//struct ListNode* reverseList(struct ListNode* head) 
//{
//	struct ListNode* cur = head;
//	struct ListNode* NewHead = NULL;
//	while (cur) {
//		struct ListNode* next = cur->next;
//		cur->next = NewHead;
//		NewHead = cur;
//		cur = next;
//	}
//	return NewHead;
//}
//struct ListNode* middleNode(struct ListNode* head) {
//	if (head == NULL || head->next == NULL) {
//		return;
//	}
//	struct ListNode* q = head;
//	struct ListNode* s = head;
//	while (q != NULL && q->next != NULL) {
//		s = s->next;
//		q = q->next->next;
//	}
//	return s;
//}
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL) {
		return;
	}

}