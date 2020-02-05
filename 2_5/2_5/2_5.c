#define _CRT_SECURE_NO_WARNINGS_ 1

//#include<stdio.h>
//int a, b;
//void fun()
//{
//	a = 100;
//	b = 200;
//} 
//int main()
//{
//	int a = 5, b = 7;
//	fun();
//	printf("% d % d / n", a, b);
//	return 0;
//}

//#include<stdio.h>
//int myAtoi(char * str) 
//{
//	int sign = 0;
//	long num = 0;
//	while (*str == ' ')
//	{
//		str++;
//	}
//	sign = (*str == '-') ? -1 : 1;
//	if (*str == '+' || *str == '-')
//	{
//		str++;
//	}
//	while (*str >= '0'&&*str <= '9')
//	{
//		num = num * 10 + ((*str) - '0');
//		if ((int)num != num)
//		{
//			return (sign == 1) ? _CRT_INT_MAX : _CRT_INT_MAX * -1;
//		}
//		str++;
//	}
//	num = sign * num;
//	return num;
//}
//int main()
//{
//	char str[] = "   -3479 is shirt";
//	int num = myAtoi(str);
//	printf("%d", num);
//	return 0;
//}

#include<stdio.h>
#include<malloc.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
	int low = 0, high = numsSize - 1, mid = 0;
	int *res = (int*)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	if (numsSize <= 0)
	{
		return res;
	}
	while (low <= high)
	{
		mid = (high + low) / 2;
		if (nums[mid] > target)
		{
			high = mid - 1;
		}
		else if (nums[mid]<target)
		{
			low = mid + 1;
		}
		else
		{
			int index = mid;
			while (nums[index] == nums[index - 1] && index > 0)
			{
				index--;
			}
			res[0] = index;
			index = mid;
			while (nums[index] == nums[index + 1] && index < numsSize - 1)
			{
				index++;
			}
			res[1] = index;
			break;
		}
	}
	*returnSize = 2;
	return res;
	}
int main()
{ 
	int nums[] = {1 };
	int target = 1;
	int sz = sizeof(nums) / sizeof(nums[0]);
	int *returnSize = (int*)malloc(sizeof(int) * 1);
	int *p = searchRange(nums, sz, target, returnSize);
	printf("%d", *p);
	p++;
	printf("%d", *p);

	return 0;
}