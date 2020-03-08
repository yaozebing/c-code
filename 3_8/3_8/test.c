#include<stdio.h>
char* my_strcat(char* des, const char* sou)
{
	if (des == NULL || sou == NULL)
	{
		return NULL;
	}//检查传入的指针是否为空
	char* p = des;//函数只是为了修改des指针后面的指向，传出时还是要传des的起点的
	while (*des != '\0')
	{
		des++;
	}//将des的指向由数组的首元素跳到了末尾'\0'，之后的赋值会把目标数组的'\0'覆盖
	while (*sou != '\0')
	{
		*des = *sou;
		des++;
		sou++;
	}//将sou指向的值赋给des指向数组后面的区域
	*des = '\0';//将'\0'赋给des指向的区域
	return p;//返回的是des最初的位置
}
char* my_strcpy(char* des, const char* sou)
{
	if (des == NULL || sou == NULL)
	{
		return NULL;
	}//检查传入的指针是否为空
	char* p = des;//函数只是为了修改des指针后面的指向，传出时还是要传des的起点的
	while (*sou != '\0')
	{
		*des = *sou;
		des++;
		sou++;
	}//将sou指向元素赋给des指向区域
	//此时des指向的是sou指向字符串的末尾位置，但并没有'\0'
	*des = '\0';//将'\0'赋给des指向的区域
	return p;//返回的是des最初的位置
}
size_t my_strlen(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}//检查传入的指针是否为空
	int num = 0;
	while (*str != '\0')
	{
		num++;
		str++;
	}
	return num;
}
int main()
{
	char str1[100] = "haha";
	char str2[100] = "hehe";
	int num = 10;
	int num2 = 0;
	
	
	int* const p = num;
	//这种限制指针的指向不能改动（指针中存的内存地址不能改变）
	const int* p = num;
	int const* p = num;
	//这两种限制p指向的内存空间不能被修改
	
	//p = &num2;
	//*p = num2;

	return 0;
}