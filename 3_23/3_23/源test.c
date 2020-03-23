#define _CRT_SECURE_NO_WARNINGS_ 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#include<stdio.h>
//void FindNum(int* num, int sz, int* num1, int* num2)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		sum ^= num[i];
//	}
//	int pos = 0;
//	for (pos = 0; pos < 32; pos++)
//	{
//		if ((sum&(1 << pos)) != 0)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if ((num[i] & (1 << pos)) == 0)
//		{
//			*num1 ^= num[i];
//		}
//		else
//		{
//			*num2 ^= num[i];
//		}
//	}
//}
//int main()
//{
//	int num[] = { 1,1,2,2,3,4,4,6 };
//	int sz = sizeof(num) / sizeof(num[0]);
//	int num1 = 0;
//	int num2 = 1;
//	FindNum(num, sz, &num1, &num2);
//	printf("%d ", num1);
//	printf("%d ", num2);
//	return 0;
//}
//#include<string.h>
//#include<stdio.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	return 0;
//}
//void Getmemory(char** p,int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	Getmemory(&str,100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//

void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL);
	{
		strcpy(str, "world");
		printf(str);
	}
}
int main()
{
	Test();
	return 0;
}