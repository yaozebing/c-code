#include<stdio.h>
#include<assert.h>
void* memmove(void* des, const void* sou, size_t num)
{
	assert(des != NULL && sou != NULL);
	char* d = (char*)des + num - 1;
	char* s = (char*)sou + num - 1;
		while (num--)
		{
			*d = *s;
			d--;
			s--;
		}
	return des;
}
void* memcpy(void* des, const void* sou, size_t num)
{
	assert(des != NULL && sou != NULL);
	char* d = (char*)des;
	char* s = (char*)sou;
	while (num--)
	{
		*d = *s;
		d++;
		s++;
	}
	return des;
}
const char* strstr(const char* str, const char* aim)
{
	assert(str != NULL && aim != NULL);
	if (aim == '\0')
	{
		return NULL;
	}
	const char* black = str;
	while (*black != '\0')
	{
		const char* red = black;
		const char* a = aim;
		while (*red == *a && *a != '\0' && *black != '\0')
		{
			red++;
			a++;
		}
		if (*a == '\0')
		{
			return black;
		}
		else if (*black == '\0')
		{
			return NULL;
		}
		else
		{
			black++;
		}
	}
	return NULL;
}
int strcmp(const char* str1, const char* str2)
{
	assert(str1 != '\0' && str2 != '\0');
	while (str1 != '\0' && str2 != '\0')
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 < *str2)
	{
		return -1;
	}
	else if (str1 > str2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	//char str[] = "memmove can be very useful";
	//memmove(str + 20, str + 15, 5);
	//printf("%s", (char*)str);

	//char str2[] = "hello my world";
	//char str3[] = "the holiday is bad";
	//memcpy(str2, str3, 10);
	//printf("%s", (char*)str2);

	//char str[] = "everything is possible";
	//char* p = strstr(str, "is");
	//printf("%s", p);
	//return 0;

	char* str1 = "wake from sleep";
	char* str2 = "wake from sle";
	int a = strcmp(str1, str2);
	printf("%d", a);
}