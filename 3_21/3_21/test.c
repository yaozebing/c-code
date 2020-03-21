#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//int My_atoi(const char* str)
//{
//	int flag = 1;
//	int ret = 0;
//	if (str == NULL || *str == '\0')
//	{
//		return 0;
//	}
//	while (isspace(*str))
//	{
//		str++;
//	}
//	if (*str == '+')
//	{
//		str++;
//	}
//	if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	while (*str != '\0')
//	{
//		if (isdigit(*str))
//		{
//			ret = ret * 10 + (*str - '0');
//		}
//		else
//		{
//			return ret;
//		}
//		str++;
//	}
//	return flag * ret;
//}
//int MyAtoi(const char* str) {
//	int flag = 1;   // 辅助处理负数的情况
//	int ret = 0;	 // 保存最终结果
//	if (str == NULL || *str == '\0') {
//		return 0;
//	}
//	// 1. 处理空白字符(空格, 换行, 回车, 制表符, 垂直制表符, 翻页符...)
//	while (isspace(*str)) {
//		str++;
//	}
//	// 2. 处理 + - 号的情况
//	if (*str == '-') {
//		flag = -1;
//		str++;
//	}
//	if (*str == '+') {
//		str++;
//	}
//	// 3. 处理正常字符
//	while (*str != '\0') {
//		if (isdigit(*str)) {
//			// 字符串转数字的核心操作
//			ret = ret * 10 + (*str - '0');
//		}
//		else {
//			return ret;
//		}
//		str++;
//	}
//	return ret * flag;
//}
//char* MyStrncpy(char* des,const char* sou, size_t num)
//{
//	while (sou == NULL || *sou == '\0')
//	{
//		return 0;
//	}
//	char* p = des;
//	int i = 0;
//	while (*sou != '\0' && i < num)
//	{
//		*p = *sou;
//		p++;
//		sou++;
//		i++;
//	}
//	*p = '\0';
//	return des;
//}
//char* MyStrncat(char* des, const char* sou, size_t num)
//{
//	if (sou == NULL || *sou == '\0')
//	{
//		return 0;
//	}
//	char* p = des;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	int i = 0;
//	while (*sou != '\0' && i < num)
//	{
//		*p = *sou;
//		p++;
//		sou++;
//		i++;
//	}
//	*p = '\0';
//}
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