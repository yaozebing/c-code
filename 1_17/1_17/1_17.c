#define _CRT_SECURE_NO_WARNINGS_ 1


#include<stdio.h>
#include<string.h>
void merge(int* nums1, int m, int* nums2, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		j = m - 1;
		for (; j >= 0; j--)
		{
			if (nums1[j] > nums2[i])
			{
				nums1[j + 1] = nums1[j];
			}
			else 
			{
				break;
			}
		}
		nums1[j + 1] = nums2[i];
		m++;
	}
	for (i = 0; i < m; i++)
	{
		printf("%d ", nums1[i]);
	}
}
//void merge(int* nums1, int m, int* nums2, int n)
//{
//	int i = 0;
//    for (i = 0; i < n; i++)
//	{
//		int j = m - 1;
//		for (; j >= 0; j--)
//		{
//			if (nums2[i] < nums1[j])
//			{
//				nums1[j + 1] = nums1[j];
//			}
//			else
//			{
//				break;
//			}
//		}
//		nums1[j + 1] = nums2[i];
//		m++;
//	}
//}
int main()
{
	int nums1[9] = { 9,7,5,3,1 };
	int *p = nums1;
	int nums2[] = { 2,4,6,8 };
	int nums1Size = 0;
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	while (*p++ != 0)
	{
		nums1Size++;
	}
	merge(nums1, nums1Size, nums2, nums2Size);
	return 0;
}
//int lengthOfLastWord(char * s)
//{
//	int len = strlen(s);
//	if (len == 0)
//	{
//		return 0;
//	}
//	int i = len - 1;
//	while (i >= 0 && s[i] == ' ')
//	{
//		i--;
//	}
//	len = i;
//	while (i >= 0 && s[i] != ' ')
//	{
//		i--;
//	}
//	return len - i;
//}
//int main()
//{
//	char arr[] = "hello world";
//	int len = lengthOfLastWord(arr);
//	printf("%d", len);
//	return 0;
//}