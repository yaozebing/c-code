#include<stdio.h>
#include<stdlib.h>
//typedef struct ListNode {
//	int val;
//	struct ListNode *next;
//}ListNode;
//ListNode* partition(ListNode* pHead, int x) {
//	ListNode* lh = (ListNode*)malloc(4);
//	ListNode* mh = (ListNode*)malloc(4);
//	ListNode* cur = pHead;
//	while (cur) {
//		if (cur->val < x) {
//			lh->next = cur;
//			lh = lh->next;
//		}
//		else {
//			mh->next = cur;
//			mh = mh->next;
//		}
//		cur = cur->next;
//	}
//	lh->next = mh;
//	return lh;
//}
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	int a = 0, b = 0;
//	struct ListNode* cura = headA;
//	struct ListNode* curb = headB;
//	while (cura) {
//		cura = cura->next;
//		a++;
//	}
//	cura = headA;
//	while (curb) {
//		curb = curb->next;
//		b++;
//	}
//	curb = headB;
//	if (a > b) {
//		int c = a - b;
//		while (c > 0) {
//			cura = cura->next;
//			c--;
//		}
//	}
//	else {
//		int c = b - a;
//		while (c > 0) {
//			curb = curb->next;
//			c--;
//
//	}
//
//}
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode; 
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;
	while (k--) {
		if (fast) {
			fast = fast->next;
		}
		else {
			return NULL;
		}
	}
	while (fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}