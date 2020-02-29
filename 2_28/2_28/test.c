#define _CRT_SECURE_NO_WARNINGS_ 1

//#include <stdio.h>
//int main()
//{
//	char a = 128;
//	printf("%u\n", a);
//	return 0;
//}

//#include<stdbool.h>
//#include<stdio.h>
//#include<string.h>
//bool judge(char *str1, char *str2)
//{
//	char* p1 = str1;
//	char* p2 = str2;
//	while (*p1 != *p2&&*p2 != '\0')
//	{
//		p2++;
//	}
//	if (*p2 == '\0')
//	{
//		return 0;
//	}
//	p1++;
//	p2++;
//	while (*p1 == *p2&&*p1 != '\0'&&*p2 != '\0')
//	{
//		p1++;
//		p2++;
//	}
//	if (*p1 != *p2&&*p2 != '\0')
//	{
//		return 0;
//	}
//	p2 = str2;
//	while (*p1 == *p2&&*p1 != '\0'&&*p2 != '\0')
//	{
//		p1++;
//		p2++;
//	}
//	if (*p1 != '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	char str1[] = "bcde";
//	char str2[] = "cdeb";
//	int a = judge(str1, str2);
//	printf("%d", a);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int rotate(char* in, int sz, int k)
//{
//	char* p = (char*)malloc((2 * sz + 1) * sizeof(char));
//	strcpy(p, in);
//	strcat(p, in);
//	strncpy(in, p + k, sz);
//	return 0;
//}
//int main()
//{
//	char in[] = "abcde";
//	int k = 3;
//	int sz = strlen(in);
//	rotate(in, sz, k);
//	printf("%s", in);
//	return 0;
//}


#include<stdio.h>

int main()
{
	int nums[][4] = { {1234},{2345},{3456},{4567} };
	int target = 0;
	int a = judge(nums, target);
	int col = sizeof(nums) / sizeof(nums[1]);
	return 0;
}
