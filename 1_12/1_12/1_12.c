#define _CRT_SECURE_NO_WARNINGS_ 
//#include<stdio.h>
//char * toLowerCase(char * str) {
//	char *p = str;
//	while ((*str) != '\0')
//	{
//		if ((*str) >= 'A' && (*str) <= 'Z')
//		{
//			(*str) += 32;
//		}
//		str++;
//	}
//	return p;
//}
//int main()
//{
//	char str[] = { "AFGCD" };
//	char *p=toLowerCase(str);
//	printf("%s", p);
//	return 0;
//}
#include<stdio.h>
void rotate(int* nums, int numsSize, int k) {
	int i = 0;
	int tmp = 0;
	int j = 0;
	k %= numsSize;//只需要旋转小于numsSize的长度
	for (i = 0, j = numsSize - 1 - k; i < j; i++, j--)//对前半部分逆置
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = numsSize - k, j = numsSize - 1; i < j; i++, j--)//对后半部分逆置
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = 0, j = numsSize - 1; i < j; i++, j--)//对整体数组逆置
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
int main()
{
	int nums[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int k = 3;
	rotate(nums, sz, k);
	return 0;
}