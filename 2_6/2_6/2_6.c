#define _CRT_SECURE_NO_WARNINGS_ 1

//#include<stdio.h>
//#include<stdbool.h>
//bool isPalindrome(char * s) 
//{
//	int num = 0;
//	while (*s != '\0')
//	{
//		num++;
//		s++;
//	}
//	if (num == 1)
//	{
//		return 1;
//	}
//	char *r = s;
//	char *l = s - num;
//	printf("%c\n", *l);
//	printf("%c\n", *r);
//	while (l < r)
//	{
//		while (((*l < 'A') || (*l > 'Z'&&*l < 'a') || (*l > 'z')) && (l < s)||(*l<'0')||(*l>'9'&&*l<'A'))
//		{
//			l++;
//			continue;
//		}
//		while (((*r < 'A') || (*r > 'Z'&&*r < 'a') || (*r > 'z')) && r > (s - num) || (*r < '0') || (*r > '9'&&*r < 'A'))
//		{
//			r--;
//			continue;
//		}
//		if ((*l == *r)||(*l==*r+32)||(*l==*r-32))
//		{
//			l++;
//			r--;
//			continue;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char str[] = "race a ecar";
//	int a = isPalindrome(str);
//	printf("%d", a);
//	return 0;
//}

#include<stdio.h>
#include<string.h>
int compress(char* chars, int charsSize)
{
	if (charsSize == 1)
	{
		return 1;
	}
	char arr = *chars;
	char str[charsSize]
}
int main()
{
	char str[] = "abbbbbbbbbbbbbbbbb";
	int sz = strlen(str);
	int c = compress(str, sz);
	return 0;
}