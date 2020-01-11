#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<assert.h>
//void TolowerCase(char *arr, int sz)
//{
//	int i = 0;
//	assert(arr != NULL);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] >= 65 && arr[i] <= 90)
//		{
//			arr[i] += 32;
//		}
//	}
//	printf("%s", arr);
//}
//int main()
//{
//	char arr[] = { "I Love The Winter" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	TolowerCase(arr, sz);
//	return 0;
//}

//#include<stdio.h>
//void TolowerCase(char str[])
//{
//	while (str != '\0')
//	{
//		if (str >= 65 && str <= 90)
//		{
//			str += 32;
//		}
//			str++;
//	}
//	puts(str);
//}
//int main()
//{
//	char str[] = { "I Love The Winter" };
//	puts(str);
//	TolowerCase(str);
//	return 0;
//}


//#include<stdio.h>
//void rotate(int nums[], int k)
//{
//}
//int main()
//{
//	int nums[] = { 1,2,3,4,5,6,7,7,8 };
//	int k = 3;
//	rotate(nums, k);
//	return 0;
//}
//


//#include<stdio.h>
//void Adjust(int *num, int sz)
//{
//	int *left = num;
//	int *right = num + sz - 1;
//	int tem = 0;
//	while (left != right && (*left) % 2 != 0)
//	{
//		left++;
//	}
//	while (right != left && (*right) % 2 == 0)
//	{
//		right--;
//	}
//	if (left < right)
//	{
//		tem = *left;
//		*left = *right;
//		*right = tem;
//	}
//}
//int main()
//{
//	int num[] = { 1,2,54,64,5,8,9 };
//	int i = 0;
//	int sz = sizeof(num) / sizeof(num[0]);
//	Adjust(num, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", num[i]);
//	}
//	return 0;
//}
//
//#include<stdio.h>
//#include<assert.h>
//void My_strcpy(char *str2, const char *str1)
//{
//	assert(str1 && str2);
//	while (*str2++ = *str1++);
//}
//int main()
//{
//	char str1[] = { "I Love The Winter" };
//	char str2[80];
//	My_strcpy(str2, str1);
//	printf("%s", str2);
//	return 0;
//}
//


//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char *arr)
//{
//	assert(arr != NULL);
//	int count = 0;
//	while (*arr)
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = { "sdfghjk" };
//	int count = my_strlen(arr);
//	printf("%d", count);
//}