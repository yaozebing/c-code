#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reverse(nums, 0, numsSize - 1);
//}int removeElement(int* nums, int numsSize, int val)
//{
//	int idx = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != val)
//		{
//			nums[idx] = nums[i];
//			idx++;
//		}
//	}
//	return idx;
//}
//int removeDuplicates(int* nums, int numsSize)
//{
//	int src1 = 0;
//	int src2 = 1;
//	int des = 0;
//	while (src2 < numsSize)
//	{
//		nums[des] = nums[src1];
//		des++;
//		if (nums[src1] != nums[src2])
//		{
//			src1++;
//			src2++;
//		}
//		else
//		{
//			while (src2 < numsSize && nums[src1] == nums[src2])
//			{
//				src2++;
//			}
//			src1 = src2;
//			src2++;
//		}
//	}
//	return des;
//}
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int e1 = m - 1;
//	int e2 = n - 1;
//	int e = m + n - 1;
//	while (e1 > 0 && e2 > 0)
//	{
//		if (nums1[e1] >= nums2[e2])
//		{
//			nums1[e] = nums1[e1];
//			e--;
//			e1--;
//		}
//		else
//		{
//			nums1[e] = nums2[e2];
//			e--;
//			e2--;
//		}
//	}
//	while (e1 >= 0)
//	{
//		nums1[e--] = nums1[e1--];
//	}
//	while(e2 >= 0)
//	{
//		nums1[e--] = nums2[e2--];
//	
//}
//}
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int ret = nums[left];
		nums[left] = nums[right];
		nums[right] = ret;
		left++;
		right--;
	}
}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//��ȡ���λ��
	int knum = 0;
	int tmp = K;
	while (tmp)
	{
		knum++;
		tmp /= 10;
	}
	//���ռ䣬�������λ��λ
	int arrysize = knum > ASize ? knum + 1 : ASize + 1;
	int* newarry = (int*)malloc(sizeof(int)*arrysize);
	//ģ��ӷ����㣬�ӵ�λ��ʼ���
	int next = 0;
	int i = 0;
	int asize = ASize - 1;
	while (K > 0 || asize >= 0)
	{
		//��ǰλ�ļӷ�
		newarry[i] = next;
		if (asize >= 0)
		{
			newarry[i] += A[asize];
		}
		if (K > 0)
		{
			newarry[i] += K % 10;
		}
		if (newarry[i] > 9)
		{
			newarry[i] -= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		K /= 10;
		i++;
		asize--;
	}
	if (next == 1)
	{
		newarry[i++] = 1;
	}
	reverse(newarry, 0, i - 1);
	*returnSize = i;
	return newarry;
}
// slist.h
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
// �������ӡ
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
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* cur = BuySListNode(x);
	if (*pplist==NULL)
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
// �������ͷ��
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
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	SListNode* cur = NULL;
	SListNode* tail = *pplist;
	if (*pplist==NULL||tail->next==NULL)
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	SListNode* cur = *pplist;
	if (cur == NULL )
	{
		return 0;
	}
	else if(cur->next==NULL)
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
// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
//�Ҳ���
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* cur = BuySListNode(x);
	cur->next = pos->next;
	pos->next = cur;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
//�Ҳ���
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
// �����������
//void SListDestory(SListNode* plist)
//{
//	SListNode* cur = plist;
//	while (cur -> next)
//	{
//		free(cur);
//		cur = cur->next;
//	}
//}