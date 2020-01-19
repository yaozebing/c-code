#define _CRT_SECURE_NO_WARNINGS_ 1

//#include<stdio.h>
//int* sortedSquares(int* A, int ASize, int* returnSize) 
//{
//	*returnSize = ASize;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < ASize; i++)
//	{
//		A[i] *= A[i];
//	}
//	for (i = 0; i < ASize - 1; i++)
//	{
//		for (j = 0; j < ASize - 1 - i; j++)
//		{
//			if (A[j] > A[j + 1])
//			{
//				A[j] += A[j + 1];
//				A[j + 1] = A[j] - A[j + 1];
//				A[j] -= A[j + 1];
//			}
//		}
//	}
//	for (i = 0; i < ASize; i++)
//	{
//		printf("%d", A[i]);
//	}
//	return A;
//}
//int main()
//{
//	int A[] = { -4,-1,0,3,10 };
//	int sz = sizeof(A) / sizeof(A[0]);
//	int *returnSize=A;
//	sortedSquares(A, sz, returnSize);
//	return 0;
//}

#include<stdio.h>
char * reverseOnlyLetters(char * S)
{
	char *p1 = S;
	char *p2 = S;
	char ex = 0;
	while (*p2 != '\0')
	{
		p2++;
	}
	p2--;
	while (p1 < p2)
	{
		if (!((*p1 >= 'a'&&*p1 <= 'z') || (*p1 >= 'A'&&*p1 <= 'Z')))
		{
			p1++;
			continue;
		}
		if (!((*p2 >= 'a'&&*p2 <= 'z') || (*p2 >= 'A'&&*p2 <= 'Z')))
		{
			p2--;
			continue;
		}
		ex = *p1;
		*p1 = *p2;
		*p2 = ex;
		p1++;
		p2--;
	}
	return S;
}
int main()
{
	char arr[] = "as - cjd!";
	char *p = reverseOnlyLetters(arr);
	printf("%s", p);
	return 0;
}