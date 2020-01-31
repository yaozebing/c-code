#define _CRT_SECURE_NO_WARNINGS_ 1

//#include<stdio.h>
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
//{
//	int i = 0;
//	int j = 0;
//	int s = 0;
//	*returnSize = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		for (j = i+1; j < numsSize; j++)
//		{
//			s = nums[i] + nums[j];
//			if (target == s)
//			{
//				int *p = (int*)malloc(sizeof(int) * 2);
//				if (p == NULL)
//				{
//					return NULL;
//				}
//				*returnSize = 2;
//				p[0] = i;
//				p[1] = j;
//				return p;
//			}
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	int nums[] = { 2,7,11,15 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int target = 9;
//	int returnsize[1] = { 0 };
//	int *p = twoSum(nums, sz, target, returnsize);
//	return 0;
//}

#include<stdio.h>
#include<string.h>
char * addBinary(char * a, char * b) 
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int len = lena > lenb ? lena + 2 : lenb + 2;
	char *res = (char*)malloc(len * (sizeof(char)));
	memset(res, '\0', len);
	len -= 2;
	while (lena > 0 || lenb > 0)
	{
		int an = lena > 0 ? a[--lena] - '0' : 0;
		int bn = lenb > 0 ? b[--lena] - '0' : 0;
		if (an + bn + res[len] + '0' == '1')
		{
			res[len--] = '1'-'0';
		}
		else if (an + bn + res[len] + '0' == '0')
		{
			res[len--] = '0';
		}
		else if (an + bn + res[len] + '0' == '2')
		{
			res[len--] = '0';
			res[len] = '1';
		}
		else
		{
			res[len--] = '1';
			res[len] = '1' - '0';
		}
	}
	res += '0';
	if(res[0] == '1')
	{
		res++;
	}
	return res;
}
int main()
{
	char a[] = { 1,0,1,0 };
	char b[] = { 1,0,1,1 };
	char *c = addBinary(a, b);
}