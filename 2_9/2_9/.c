#define CRT_SECURE_NO_WARNINGS_ 1

//#include<stdio.h>
//int main()
//{
//	short i = 65537;
//	int j = i + 1;
//	printf("i=%d,j=%d\n", i, j);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	unsigned int a = 0 * 1234;
//	unsigned char b = *(unsigned char *)&a;
//	printf("%x", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int nums[20][20] = { 0 };
//	for (i = 0; i < 20; i++)
//	{
//		nums[i][0] = 1;
//		nums[i][i] = 1;
//	}
//	for (i = 2; i < 20; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
//		}
//	}
//	for (i = 0; i < 20; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%5d ", nums[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

#include<stdio.h>
int main()
{
	int m;
	for (m = 'a'; m < 'd'; m++)
	{
		if ((m != 'a') + (m == 'c') + (m == 'd') + (m != 'd') == 3)
		{
			printf("%c", m);
		}
	}
	return 0;
}