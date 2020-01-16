#define _CRT_SECURE_NO_WARNINGS_ 1

//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//bool canConstruct(char * ransomNote, char * magazine)
//{
//	if (ransomNote == NULL || magazine == NULL)
//	{
//		return false;
//	}
//	int arr[26] = { 0 };
//	int ran_len = strlen(ransomNote);
//	int mag_len = strlen(magazine);
//	int i = 0;
//	for (i = 0; i < mag_len; i++)
//	{
//		arr[magazine[i] - 'a']++;
//	}
//	for (i = 0; i < ran_len; i++)
//	{
//		arr[ransomNote[i] - 'a']--;
//		if (arr[ransomNote[i] - 'a'] < 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	char str1[] = "agfds";
//	char str2[] = "affhiiicabhbdchbidghccijjbfjfhjeddgggbajhidhjchiedhdibgeaecffbbbefiabjdhggihccec";
//	int i = 0;
//	i = canConstruct(str1, str2);
//	printf("%d", i);
//	return 0;
//}

#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x) 
{
	if (x < 0 || (x % 10 == 0 && x != 0)) 
	{
		return false;
	}
	int s = 0;
	int i = 0;
	while (s < x)
	{
		i = x % 10;
		x /= 10;
		s = s * 10 + i;
		printf("%d ", s);
	}
	if (s / 10 == x || s == x)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int a = 10;
	int i = isPalindrome(a);
	printf("%d", i);
	return 0;
}