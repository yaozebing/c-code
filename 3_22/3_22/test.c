#define _CRT_SECURE_NO_WARNINGS_ 1
//#include <stdio.h>
//int main()
//{
//	int sum = 2, n = 0, x = 2;
//	printf("input num\n");
//	scanf("%d", &n);
//	if (n == 1)
//	{
//		printf("2");
//	}
//	else
//	{
//		n--;
//		while (n != 0)
//		{
//			x += 3;
//			sum += x;
//			n--;
//		}
//		printf("%d", sum);
//	}
//
//	return 0;
//}
//#include<stdio.h>
//int main() {
//	float i;
//	float f;
//	while (scanf("%f", &f) != EOF) {
//		i = (float)5 / 9 * (f - 32);
//		printf("%.2f\n", i);
//	}
//	return 0;
//}
//求出10至1000之内能同时被2、3、7整除的数，并输出。每行一个。
//#include<stdio.h>
//int main()
//{
//	int i = 10;
//	while (i <= 1000)
//	{
//		if (i % 7 == 0)
//		{
//			if (i % 3 == 0)
//			{
//				if (i % 2 == 0)
//				{
//					printf("%d\n", i);
//				}
//			}
//		}
//		i++;
//	}
//	return 0;
//}

#include<stdio.h>

#define maxn 100005
int i, n[maxn];

int main() {
	while (scanf("%d", &i) != EOF) 
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			scanf("%d", &n[j]);
		}
		for (int j = 0; j < i; j++) 
		{
			if (n[j] % 2 == 0)
				sum += n[j];
		}
		printf("%d\n", sum);
	}
	return 0;
}