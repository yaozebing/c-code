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
//	//创建链表表头
//	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* cur = pHead;
//	while (cur)
//	{
//		//小于x的尾插到lessTail
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = lessTail->next;
//		}
//		//大于等于x的尾插到greaterTail
//		else
//		{
//			greaterTail->next = cur;
//			greaterTail = greaterTail->next;
//		}
//		cur = cur->next;
//	}
//	//链接两个链表
//	lessTail->next = greaterHead->next;
//	greaterTail->next = NULL;
//	//获取表头
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
//	//申请快慢指针
//	ListNode* fast, *slow;
//	fast = slow = head;
//	//进行移位，以便判断是否有循环
//	while (fast && fast->next) {
//		slow = slow->next;
//		fast = fast->next->next;
//		//有环时
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
//	//无环返回null
//	return NULL;
//}
//struct Node* copyRandomList(struct Node* head) 
//{
//	//拷贝链表
//	ListNode* cur = head;
//	while (cur != NULL)
//	{
//		ListNode* next = cur->next;
//		ListNode* copy = (ListNode*)malloc(sizeof(ListNode));
//		copy->val = cur->val;
//		//插入
//		copy->next = cur->next;
//		cur->next = copy;
//		cur = next;
//	}
//	//连接random
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
//	//拆分
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
//	//创建排序链表
//	ListNode* sort = (ListNode*)malloc(sizeof(ListNode));
//	//头节点首先插入
//	sort->next = head;
//	head = head->next;
//	sort->next->next = NULL;
//	//插入剩余节点
//	ListNode* cur = head;
//	while (cur)
//	{
//		//首先保存next节点
//		ListNode* next = cur->next;
//		//从排序链表的头开始，给待插入的节点找到一个合适的位置
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
//		//把节点插到sortcur的前面
//		cur->next = sortcur;
//		sortprev->next = cur;
//		//进行下一个节点
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
//			//将next移到不等于cur的节点处
//			while (next != NULL && next->val == cur->val)
//			{
//				next = next->next;
//			}
//			//判断首元节点是否重复
//			if (prev == NULL)
//			{
//				pHead = next;
//			}
//			else
//			{
//				prev->next = next;
//			}
//			//删除重复节点
//			while (cur != next)
//			{
//				ListNode* next2 = cur->next;
//				free(cur);
//				cur = next2;
//			}
//			//更新节点
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