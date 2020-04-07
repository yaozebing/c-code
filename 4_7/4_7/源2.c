#include"List.h"
//typedef struct ListNode {
//	int val;
//	struct ListNode *next;
//	struct ListNode *random;
//}ListNode;
//typedef struct ListNode ListNode;
//ListNode* partition(ListNode* pHead, int x) {
//	if (pHead == NULL)
//		return NULL;
//	struct ListNode* lessHead, *lessTail, *greaterHead, *greaterTail;
//	//���������ͷ
//	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* cur = pHead;
//	while (cur)
//	{
//		//С��x��β�嵽lessTail
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = lessTail->next;
//		}
//		//���ڵ���x��β�嵽greaterTail
//		else
//		{
//			greaterTail->next = cur;
//			greaterTail = greaterTail->next;
//		}
//		cur = cur->next;
//	}
//	//������������
//	lessTail->next = greaterHead->next;
//	greaterTail->next = NULL;
//	//��ȡ��ͷ
//	pHead = lessHead->next;
//	free(lessHead);
//	free(greaterHead);
//
//	return pHead;
////}
//bool chkPalindrome(ListNode* A) {
//	int nums[900] = { 0 };
//	int n = 0;
//	while (A) {
//		nums[n] = A->val;
//		n++;
//		A = A->next;
//	}
//	int i = 0;
//	while (i < n / 2) {
//		if (nums[i] != nums[n - i - 1]) {
//			return false;
//		}
//		i++;
//	}
//	return true;
//}
//bool chkPalindrome(ListNode* A) {
//	if (A == NULL || A->next == NULL) {
//		return NULL;
//	}
//	ListNode *slow, *fast, *cur, *prev, *next;
//	slow = fast = A;
//	prev = NULL;
//	while (fast != NULL && fast->next != NULL) {
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	cur = slow;
//	while (cur) {
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	while (prev) {
//		if (A->val != prev->val) {
//			return false;
//		}
//		A = A->next;
//		prev = prev->next;
//	}
//	return true;
//}
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	if (headA == NULL || headB == NULL) {
//		return NULL;
//	}
//	int lena = 0, lenb = 0;
//	ListNode* cura = headA;
//	ListNode* curb = headB;
//	while (cura) {
//		lena++;
//		cura = cura->next;
//	}
//	while (curb) {
//		lenb++;
//		curb = curb->next;
//	}
//	int gap = abs(lena - lenb);
//	ListNode* lo, *sh;
//	if (lena > lenb) {
//		lo = headA;
//		sh = headB;
//	}
//	else {
//		lo = headB;
//		sh = headA;
//	}
//	while (gap--) {
//		lo = lo->next;
//	}
//	while (lo != sh && sh != NULL && lo != NULL) {
//		lo = lo->next;
//		sh = sh->next;
//	}
//	return lo;
//	}
//bool hasCycle(struct ListNode *head) {
//	if (head == NULL || head->next == NULL) {
//		return NULL;
//	}
//	ListNode* slow,* fast;
//	slow = fast = head;
//	while (fast != NULL  && fast->next != NULL) {
//		fast = fast->next->next;
//		slow = slow->next;
//		if (fast == slow) {
//			return true;
//		}
//	}
//	return true;
//}
//int main()
//{
//	return 0;
//}
//struct ListNode *detectCycle(struct ListNode *head) {
//	if (head || head->next) {
//		return NULL;
//	}
//	//�������ָ��
//	ListNode* fast, *slow;
//	fast = slow = head;
//	//������λ���Ա��ж��Ƿ���ѭ��
//	while (fast && fast->next) {
//		slow = slow->next;
//		fast = fast->next->next;
//		//�л�ʱ
//		if (slow == fast) {
//			ListNode* meet = slow;
//			ListNode* NewHead = head;
//			while (NewHead != meet) {
//				NewHead = NewHead->next;
//				meet = meet->next;
//			}
//			return meet;
//		}
//	}
//	//�޻�����null
//	return NULL;
//}
//struct Node* copyRandomList(struct Node* head) 
//{
//	//��������
//	ListNode* cur = head;
//	while (cur != NULL)
//	{
//		ListNode* next = cur->next;
//		ListNode* copy = (ListNode*)malloc(sizeof(ListNode));
//		copy->val = cur->val;
//		//����
//		copy->next = cur->next;
//		cur->next = copy;
//		cur = next;
//	}
//	//����random
//	cur = head;
//	while (cur != NULL)
//	{
//		ListNode* copy2 = cur->next;
//		if (cur->random == NULL)
//		{
//			copy2->random = NULL;
//		}
//		else
//		{
//			copy2->random = cur->random->next;
//		}
//		cur = copy2->next;
//	}
//	//���
//	ListNode* NewHead, *NewTail;
//	//NewHead = NewTail = (ListNode*)malloc(sizeof(ListNode));
//	NewHead = NewTail = NULL;
//	cur = head;
//	while (cur)
//	{
//		ListNode* copy3 = cur->next;
//		ListNode* next = copy3->next;
//		if (NewTail == NULL)
//		{
//			NewHead = NewTail = copy3;
//		}
//		else
//		{
//			NewTail->next = copy3;
//			NewTail = NewTail->next;
//		}
//		cur->next = next;
//		cur = next;
//	}
//	//NewTail->next = NULL;
//	return NewHead;
//}
//struct ListNode* insertionSortList(struct ListNode* head) 
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	//������������
//	ListNode* sort = (ListNode*)malloc(sizeof(ListNode));
//	//ͷ�ڵ����Ȳ���
//	sort->next = head;
//	head = head->next;
//	sort->next->next = NULL;
//	//����ʣ��ڵ�
//	ListNode* cur = head;
//	while (cur)
//	{
//		//���ȱ���next�ڵ�
//		ListNode* next = cur->next;
//		//�����������ͷ��ʼ����������Ľڵ��ҵ�һ�����ʵ�λ��
//		ListNode* sortprev = sort;
//		ListNode* sortcur = sort->next;
//		while (sortcur)
//		{
//			if (cur->val > sortcur->val)
//			{
//				sortprev = sortcur;
//				sortcur = sortcur->next;
//			}
//			else
//			{
//				break;
//			}
//		}
//		//�ѽڵ�嵽sortcur��ǰ��
//		cur->next = sortcur;
//		sortprev->next = cur;
//		//������һ���ڵ�
//		cur = next;
//	}
//	ListNode* NewH = sort->next;
//	free(sort);
//	return NewH;
//}
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	if (pHead == NULL || pHead->next == NULL)
//	{
//		return pHead;
//	}
//	ListNode* prev = NULL;
//	ListNode* cur = pHead;
//	ListNode* next = cur->next;
//	while (next)
//	{
//		if (cur->val == next->val)
//		{
//			//��next�Ƶ�������cur�Ľڵ㴦
//			while (next != NULL && next->val == cur->val)
//			{
//				next = next->next;
//			}
//			//�ж���Ԫ�ڵ��Ƿ��ظ�
//			if (prev == NULL)
//			{
//				pHead = next;
//			}
//			else
//			{
//				prev->next = next;
//			}
//			//ɾ���ظ��ڵ�
//			while (cur != next)
//			{
//				ListNode* next2 = cur->next;
//				free(cur);
//				cur = next2;
//			}
//			//���½ڵ�
//			if (next)
//			{
//				next = next->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = next;
//			next = next->next;
//		}
//	}
//	free(prev);
//	free(cur);
//	free(next);
//	return pHead;
//}
int main()
{
	ListNode* list = ListCreate();
	ListPushFront(list, 1);
	ListPrint(list);
	return 0;
}