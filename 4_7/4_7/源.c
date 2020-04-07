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
//////	//���������ͷ
//////	lowh = lowt = (struct ListNode*)malloc(sizeof(struct ListNode));
//////	highh = hight = (struct ListNode*)malloc(sizeof(struct ListNode));
//////	struct ListNode* cur = pHead;
//////	while(cur) 
//////	{
//////		//С��x��β�嵽lowt
//////		if (cur->val < x) 
//////		{
//////			lowt->next = cur;
//////			lowt = lowt->next;
//////		}
//////		//���ڵ���x��β�嵽hight
//////		else 
//////		{
//////			hight->next = cur;
//////			hight = hight->next;
//////		}
//////		cur = cur->next;
//////	}
//////	//������������
//////	lowt->next = highh->next;
//////	hight->next = NULL;
//////	//��ȡ��ͷ
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
////		//�ߵ�������
////		if (slow == fast)
////		{
////			// �󻷵���ڵ�
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
//	// 1.�������������뵽ԭ�ڵ�ĺ���
//	Node* cur = head;
//	while (cur)
//	{
//		Node* next = cur->next;
//
//		Node* copy = (Node*)malloc(sizeof(Node));
//		copy->val = cur->val;
//
//		// ����
//		cur->next = copy;
//		copy->next = next;
//
//		// ����������
//		cur = next;
//	}
//
//	// 2.�ÿ����ڵ��random
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
//	// 3.�⿽���ڵ㣬���ӿ����ڵ�
//	Node* copyHead = NULL, *copyTail = NULL;
//	cur = head;
//	while (cur)
//	{
//		Node* copy = cur->next;
//		Node* next = copy->next;
//
//		// copy������β��
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
//	//������������
//	Node* sortHead = (Node*)malloc(sizeof(Node));
//	//ͷ�ڵ����Ȳ���
//	sortHead->next = head;
//	head = head->next;
//	sortHead->next->next = NULL;
//	//����ʣ��ڵ�
//	Node* cur = head;
//	while (cur)
//	{
//		//���ȱ���next�ڵ�
//		Node* next = cur->next;
//
//		// �����������ͷ��ʼ����������Ľڵ��ҵ�һ�����ʵ�λ��
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
//		//�ں���λ�ý��в���
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
//		//������ڽڵ㲻��ͬ������Ҫɾ�������½ڵ㣬����������
//		if (n1->val != n2->val)
//		{
//			n0 = n1;
//			n1 = n2;
//			n2 = n2->next;
//		}
//		else
//		{
//			//������ڽڵ���ͬ
//			//��n2ȥ�ҵ�һ������ͬ�Ľڵ�
//			while (n2 && n2->val == n1->val)
//			{
//				n2 = n2->next;
//			}
//			//�������ӣ����Ҫɾ���İ���ͷ�ڵ㣬�����ͷ�ڵ�
//			if (n0)
//				n0->next = n2;
//			else
//				pHead = n2;
//
//			// ɾ�����ظ��Ľڵ�
//			while (n1 != n2)
//			{
//				struct ListNode* next = n1->next;
//				free(n1);
//				n1 = next;
//			}
//			//���½ڵ�
//			n1 = n2;
//			if (n2)
//				n2 = n2->next;
//		}
//	}
//
//	return pHead;
//}