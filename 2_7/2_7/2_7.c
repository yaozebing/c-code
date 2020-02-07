#define _CRT_SECURE_NO_WARNINGS_ 1

//#include <stdio.h>
//int main()
//{
//	int a[] = { 2,4,6,8 }, *p = a, i;
//	for (i = 0; i < 4; i++)
//		a[i] = *p++;
//	printf("%d\n", a[2]);
//	return 0;
//}

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}
int findUnsortedSubarray(int* nums, int numsSize) 
{
	int *buf = NULL;
	int l = 0;
	int r = numsSize - 1;
	buf = (int *)calloc(numsSize, sizeof(int));
	if (buf == NULL)
	{
		return -1;
	}
	memcpy(buf, nums, numsSize * sizeof(int));
	qsort(buf, numsSize, sizeof(int), cmp);
	for (l = 0; l < numsSize; l++)
	{
		if (nums[l] != buf[l])
		{
			break;
		}
	}
	for (r = numsSize - 1; r >= 0; r--)
	{
		if (buf[r]>nums[r])
		{
			break;
		}
	}
	free(buf);
	return r > l ? r - l + 1 : 0;
}
int main()
{
	int nums[] = { 2, 6, 4, 8, 10, 9, 15 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int find = findUnsortedSubarray(nums, sz);
	printf("%d", find);
	return 0;
}