#define _CRT_SECURE_NO_WARNINGS_

//#include<stdio.h>
//int* plusOne(int* digits, int digitsSize, int* returnSize) 
//{
//	int i = digitsSize - 1;
//	int overflow = 1;
//	while (i >= 0)
//	{
//		if (digits[i] < 9)
//		{
//			digits[i]++;
//			overflow = 0;
//			break;
//		}
//		else
//		{
//			digits[i] = 0;
//			i--;
//		}
//	}
//	int* result = NULL;
//	if (overflow)
//	{
//		*returnSize = digitsSize + 1;
//		result = (int*)malloc(sizeof(int)*(digitsSize + 1));
//		result[0] = 1;
//		for (i = 1; i <= digits; i++)
//		{
//			result[i] = 0;
//		}
//	}
//	else
//	{
//		*returnSize = digitsSize;
//		result = digits;
//	}
//	return result;
//}
//int main()
//{
//	int digits[] = { 1,0,9,9 };
//	int sz = sizeof(digits) / sizeof(digits[0]);
//	int returnSize[1] = { 0 };
//	int *p = plusOne(digits, sz, returnSize);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", digits[i]);
//	}
//	return 0;
//}

#include<stdio.h>
int thirdMax(int* nums, int numsSize)
{
	int i = 0;
	int j = 0;
	int tem = 0;
	int flag = 0;
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < numsSize - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				nums[j + 1] += nums[j];
				nums[j] = nums[j + 1] - nums[j];
				nums[j + 1] -= nums[j];
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int main()
{
	int nums[] = { 2, 2, 3, 1  };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int num = thirdMax(nums, sz);
	return 0;
}