#define _CRT_SECURE_NO_WARNINGS 1

//
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	while (p != arr + 10)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344;
//	char *pc = (char*)&a;
//	*pc = 0;
//	printf("%x\n", a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	short *p = (short*)arr;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//void Reverse(char str[])
//{
//	char *p = str;
//	int i = 0;
//	char arr[100];
//	while (*p != '\0')
//	{
//		p++;
//		i++;
//	}
//	i--;
//	p = str;
//	while (i >= 0)
//	{
//		arr[i] = *p;
//		p++;
//		i--;
//	}
//	p = str;
//	i = 0;
//	while (*p++ != '\0')
//	{
//		printf("%c", arr[i]);
//			i++;
//	}
//}
//int main()
//{
//	char str[] = "hello bit";
//	Reverse(str);
//	return 0;
//}


//#include<stdio.h>
//void col(int x)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 1; i <= x; i++)
//	{
//		printf("\n");
//		for (j = 0; j < x-i; j++)
//		{
//			printf(" ");
//		}
//		for (k = 0; k < 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//	}
//	for (i = x - 1; i > 0; i--)
//	{
//		printf("\n");
//		for (j = 1; j < x - i + 1; j++)
//		{
//			printf(" ");
//		}
//		for (k = 2 * i - 1; k > 0; k--)
//		{
//			printf("*");
//		}
//	}
//}
//int main()
//{
//	int x = 7;
//	col(x);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int flo(int i)
//{
//	int n = 0;
//	while (i != 0)
//	{
//		i /= 10;
//		n++;
//	}
//	return n;
//}
//int add(int i, int n)
//{
//	int s = 0;
//	int a = 0;
//	while (i != 0)
//	{
//		a = i % 10;
//		s = s + pow(a, n);
//		i /= 10;
//	}
//	return s;
//}
//int main()
//{
//	int x = 100000;
//	int i = 1;
//	int n = 0;
//	double s = 0;
//	while (i < x)
//	{
//		n = flo(i);
//		s = add(i, n);
//		if (s == i)
//		{
//			printf("%d ", i);
//		}
//		i++;
//	}
//	return 0;
//}

#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a = 2;
//	int s = 0;
//	int i = 0;
//	int sn = 0;
//	for (i = 0; i < 5; i++)
//	{
//		a = 2 * pow(10, i);
//		s += a;
//		sn += s;
//	}
//	printf("%d", sn);
//	return 0;
//}