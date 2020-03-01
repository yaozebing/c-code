#include<stdio.h>
#include<stdlib.h>
typedef int(*rule)(void*, void*);
int int_cmp(const void* p1, const void* p2)
{
	return (*(int *)p1 - *(int *)p2);
}//int ”√
int char_cmp(const void* p1, const void* p2)
{
	return (*(char *)p1 - *(char *)p2);
}//char ”√
void swap(void *p1, void *p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void bsort(void* base, int sz, int size, rule cmp)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
			{
				swap((char*)base + j * size, (char*)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	int nums[] = { 1,8,4,7,2,9 };
	char str[] = "acgfgdf";
	int i = 0;
	bsort(nums, sizeof(nums) / sizeof(nums[0]), sizeof(int),int_cmp);
	for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	i = 0;
	bsort(str, sizeof(str) / sizeof(str[0]), sizeof(char), char_cmp);
	for (i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		printf("%c ", str[i]);
	}
	return 0;
}

int main()
{
	int nums[] = { 8,2,9,8,5,3 };
	char arr[] = "aioundv";
	int i = 0;
	qsort(nums, sizeof(nums) / sizeof(nums[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", nums[i]);
	}
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char), char_cmp);
	i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%c ", arr[i]);
	}
	return 0;
}