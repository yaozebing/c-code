#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

void my_len(const char *str)
{
	int count = 0;
	assert(str != NULL);
	while (str)
	{
		count++;
		str++;
	}
	printf("%d", count);
}
int main()
{
	char str[] = "my computer game over";
	//int len = 
	my_len(str);
	//printf("count=%d", len);
	return 0;
}