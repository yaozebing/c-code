#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int  main()
{
	int num[10000] = { 0 };
	num[1] = 1;
	int n = 0;
	scanf("%d", &n);
	int i = 2;
	for (i = 2; i < 10000; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
		if (num[i] >= n)
		{
			break;
		}
	}
	if (num[i] == n)
	{
		printf("0");
	}
	else
	{
		int c1 = num[i] - n;
		int c2 = n - num[i - 1];
		printf("%d", c1 > c2 ? c2 : c1);
		return 0;
	}
}