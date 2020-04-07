//#include<stdio.h>
//#include<stdlib.h>
////typedef struct ListNode {
////	int val;
////	struct ListNode *next;
////}ListNode;
//////ListNode* partition(ListNode* pHead, int x) {
//////	if (pHead == NULL)
//////		return NULL;
//////	struct ListNode* lowh,* lowt,* highh,* hight;
//////	//创建链表表头
//////	lowh = lowt = (struct ListNode*)malloc(sizeof(struct ListNode));
//////	highh = hight = (struct ListNode*)malloc(sizeof(struct ListNode));
//////	struct ListNode* cur = pHead;
//////	while(cur) 
//////	{
//////		//小于x的尾插到lowt
//////		if (cur->val < x) 
//////		{
//////			lowt->next = cur;
//////			lowt = lowt->next;
//////		}
//////		//大于等于x的尾插到hight
//////		else 
//////		{
//////			hight->next = cur;
//////			hight = hight->next;
//////		}
//////		cur = cur->next;
//////	}
//////	//链接两个链表
//////	lowt->next = highh->next;
//////	hight->next = NULL;
//////	//获取表头
//////	pHead = lowh->next;
//////	free(lowh);
//////	free(highh);
//////	return pHead;
//////}
////typedef struct ListNode Node;
////struct ListNode *detectCycle(struct ListNode *head) {
////	Node* slow = head;
////	Node* fast = head;
////
////	while (fast && fast->next)
////	{
////		slow = slow->next;
////		fast = fast->next->next;
////		//走到相遇点
////		if (slow == fast)
////		{
////			// 求环的入口点
////			Node* meet = slow;
////			Node* start = head;
////
////			while (meet != start)
////			{
////				meet = meet->next;
////				start = start->next;
////			}
////
////			return meet;
////		}
////	}
////
////	return NULL;
////}
////
////int main()
////{
////	int i = 10;
////	while (i) 
////	{
////		int num = 10;
////		num = num - i;
////		printf("%d ", num);
////		i--;
////	}
////	return 0;
////}
//
//Node* copyRandomList(Node* head) {
//	// 1.拷贝链表，并插入到原节点的后面
//	Node* cur = head;
//	while (cur)
//	{
//		Node* next = cur->next;
//
//		Node* copy = (Node*)malloc(sizeof(Node));
//		copy->val = cur->val;
//
//		// 插入
//		cur->next = copy;
//		copy->next = next;
//
//		// 迭代往下走
//		cur = next;
//	}
//
//	// 2.置拷贝节点的random
//	cur = head;
//	while (cur)
//	{
//		Node* copy = cur->next;
//		if (cur->random != NULL)
//			copy->random = cur->random->next;
//		else
//			copy->random = NULL;
//
//		cur = copy->next;
//	}
//
//	// 3.解拷贝节点，链接拷贝节点
//	Node* copyHead = NULL, *copyTail = NULL;
//	cur = head;
//	while (cur)
//	{
//		Node* copy = cur->next;
//		Node* next = copy->next;
//
//		// copy解下来尾插
//		if (copyTail == NULL)
//		{
//			copyHead = copyTail = copy;
//		}
//		else
//		{
//			copyTail->next = copy;
//			copyTail = copy;
//		}
//
//		cur->next = next;
//
//		cur = next;
//	}
//
//	return copyHead;
//}
//};
//
//
//struct ListNode* insertionSortList(struct ListNode* head) {
//	if (head == NULL || head->next == NULL)
//		return head;
//	//创建排序链表
//	Node* sortHead = (Node*)malloc(sizeof(Node));
//	//头节点首先插入
//	sortHead->next = head;
//	head = head->next;
//	sortHead->next->next = NULL;
//	//插入剩余节点
//	Node* cur = head;
//	while (cur)
//	{
//		//首先保存next节点
//		Node* next = cur->next;
//
//		// 从排序链表的头开始，给待插入的节点找到一个合适的位置
//		Node* sortPrev = sortHead;
//		Node* sortCur = sortHead->next;
//
//		while (sortCur)
//		{
//			if (cur->val > sortCur->val)
//			{
//				sortPrev = sortCur;
//				sortCur = sortCur->next;
//			}
//			else
//			{
//				break;
//			}
//		}
//		//在合适位置进行插入
//		sortPrev->next = cur;
//		cur->next = sortCur;
//
//		cur = next;
//	}
//
//	Node* sortList = sortHead->next;
//	free(sortHead);
//
//	return sortList;
//}
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	if (pHead == NULL || pHead->next == NULL)
//		return pHead;
//
//	struct ListNode* n0 = NULL;
//	struct ListNode* n1 = pHead;
//	struct ListNode* n2 = n1->next;
//	while (n2 != NULL)
//	{
//		//如果相邻节点不相同，则不需要删除，更新节点，继续向后遍历
//		if (n1->val != n2->val)
//		{
//			n0 = n1;
//			n1 = n2;
//			n2 = n2->next;
//		}
//		else
//		{
//			//如果相邻节点相同
//			//则n2去找第一个不相同的节点
//			while (n2 && n2->val == n1->val)
//			{
//				n2 = n2->next;
//			}
//			//重新链接，如果要删除的包括头节点，则更新头节点
//			if (n0)
//				n0->next = n2;
//			else
//				pHead = n2;
//
//			// 删除掉重复的节点
//			while (n1 != n2)
//			{
//				struct ListNode* next = n1->next;
//				free(n1);
//				n1 = next;
//			}
//			//更新节点
//			n1 = n2;
//			if (n2)
//				n2 = n2->next;
//		}
//	}
//
//	return pHead;
//}