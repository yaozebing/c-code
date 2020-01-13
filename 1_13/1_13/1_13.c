#define _CRT_SECURE_NO_WARNINGS_ 

//#include<stdio.h>
//int main()
//{
//	int x = 10;
//	int y = 10;
//	x = y = ++y;
//	printf("%d %d ",x, y);
//	return 0;
//}
//int main()
//{
//	int a = 'A' + 1.6;
//	printf("%d", a);
//	return 0;
//}

#include<stdio.h>
//int removeElement(int* nums, int numsSize, int val)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == val)
//		{
//			for (j = i; j < numsSize - 1; j++)
//			{
//				nums[j] = nums[j + 1];
//			}
//			numsSize--;
//			i--;
//		}
//	}
//	return numsSize;
//}
//int removeElement(int* nums, int numsSize, int val) 
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != val)
//		{
//			nums[count++] = nums[i];
//		}
//	}
//	return count;
//}
//int main()
//{
//	int nums[] = { 3,2,2,3,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int val = 3;
//	int n = removeElement(nums, sz, val);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", nums[i]);
//	}
//	return 0;
//}

#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target)
{
	int low = 0;
	int high = numsSize - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else if (nums[mid] > target)
			{
				high = mid - 1;
			}
	}
	return low;
}

int main()
{
	int nums[] = { 1,3,5,6 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int target = 7;
	int n = searchInsert(nums, sz, target);
	printf("%d", n);
	return 0;
}