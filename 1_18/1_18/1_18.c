#define _CRT_SECURE_NO_WARNINGS_ 1
//#include<stdio.h>
//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	} 
//	return b;
//}
//int main()
//{
//	int a = 1;
//	int b = func(a);
//	printf("%d", b);
//}

#include<stdio.h>
#include<stdbool.h>
//bool containsDuplicate(int* nums, int numsSize) 
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		for (j = numsSize - 1; j > i; j--)
//		{
//			if (nums[i] == nums[j])
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}

//bool containsDuplicate(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		flag = 0;
//		for (j = 0; j < numsSize - 1 - i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				flag = 1;
//				nums[j] += nums[j + 1];
//				nums[j + 1] = nums[j] - nums[j + 1];
//				nums[j] = nums[j] - nums[j + 1];
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int nums[] = { 0,4,5,0,3,6 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int con = containsDuplicate(nums, sz);
//	printf("%d", con);
//	return 0;
//}


#include<stdio.h>
#include<stdbool.h>
bool isLongPressedName(char * name, char * typed) 
{
	int nname = 0;
	int ntyped = 0;
	while (*name && *typed)
	{
		nname = 1;
		ntyped = 1;
		while (*(name+1) == *name)
		{
			name++;
			nname++;
		}
		while (*(typed + 1) == *typed)
		{
			typed++;
			ntyped++;
		}
		if (ntyped < nname || *name != *typed)
		{
			return false;
		}
		name++;
		typed++;
	}
	return (*name ? false : true);
}
int main()
{
	char name[] = "pyplrz";
	char typed[] = "ppyypllr";
	int i = isLongPressedName(name, typed);
	printf("%d", i);
	return 0;
}