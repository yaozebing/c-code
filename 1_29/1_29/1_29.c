#define _CRT_SECURE_NO_WARNINGS_

//#include<stdio.h>
//int main()
//{
//	char str[] = "ABCD", *p = str;
//	printf("%d\n", *(p + 4));
//	return 0;
//}
//
//#include<stdio.h>
//float func(float a, int b)
//{
//	float m=1, n=1;
//	int i;
//	for (i=1; i <b; i ++)
//	{
//		m*= a/i;
//		n+=m;
//	}
//	return n;
//}
//int main()
//{
//	float a = 2;
//	int b = 12;
//	float c = func(a, b);
//	printf("%f", c);
//	return 0;
//}

//#include<stdio.h>
//int* sortArrayByParity(int* A, int ASize, int* returnSize) 
//{
//	int *l = A;
//	int *r = A + ASize - 1;
//	int tem = 0;
//	while (l < r)
//	{
//		while (*l % 2 == 0 && l < A + ASize - 1)
//		{
//			l++;
//		}
//		while (*r % 2 != 0 && r > A)
//		{
//			r--;
//		}
//		if (l >= r)
//		{
//			break;
//		}
//		else if (l < r)
//		{
//			tem = *r;
//			*r = *l;
//			*l = tem;
//			r--;
//			l++;
//		}
//	}
//	*returnSize = ASize;
//	return A;
//}
//int main()
//{
//	int A[] = { 0,1 };
//	int i = 0;
//	int sz = sizeof(A) / sizeof(A[0]);
//	int returnsize[100];
//	int *p = sortArrayByParity(A, sz, returnsize);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	return 0;
//}


#include<stdio.h>
int pivotIndex(int* nums, int numsSize) 
{
	int i = 0;
	int s = 0;
	int sm = 0;
	int m = 0;
	for (i = 0; i < numsSize; i++)
	{
		sm += nums[i];
	}
	for (i = 0; i < numsSize ; i++)
	{
		m = sm - s - nums[i];
		if (m == s)
		{
			return i;
		}
		s += nums[i];
	}
	return -1;
}
int main()
{
	int nums[] = { 1, 7, 3, 6, 5, 6 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int a = pivotIndex(nums, sz);
	printf("%d", a);
	return 0;
}