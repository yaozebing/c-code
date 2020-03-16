#define _CRT_SECURE_NO_WARNINGS 
#define Max 1000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct personInfo
{
	char name[128];
	char sex;
	int age;
	char phone[128];
	char home[128];
}personInfo;
typedef struct addrbook
{
	int num;
	personInfo person[Max];
}addrbook;
void Init(addrbook* book)
{
	book->num = 0;
	int i = 0;
	for (i = 0; i < 128; i++)
	{
		strcpy(book->person[i].name, " ");
		book->person[i].age = 0;
		book->person[i].sex = 0;
		strcpy(book->person[i].phone, " ");
		strcpy(book->person[i].home, " ");
	}
}
int menu()
{
	int choice = 0;
	printf("----------------------\n");
	printf("input your choice\n");
	printf("1.Add\n");
	printf("2.Delete\n");
	printf("3.Find\n");
	printf("4.Modify\n");
	printf("5.Show\n");
	printf("6.Clear\n");
	printf("7.Sort\n");
	printf("0.close\n");
	printf("----------------------\n");
	scanf("%d", &choice);
	return choice;
}
void Add(addrbook* book)
{
	if (book->num >= Max)
	{
		printf("the book is full\n");
		return 0;
	}
	personInfo* Info = &book->person[book->num];
	printf("Add personInfo!\n");
	printf("input name\n");
	scanf("%s", Info->name);
	getchar();
	printf("input sex:M\W\n");
	scanf("%c", &Info->sex);
	printf("input age\n");
	scanf("%d", &Info->age);
	printf("input phone\n");
	scanf("%s", Info->phone);
	printf("input home\n");
	scanf("%s", Info->home);
	book->num++;
}
void Delete(addrbook* book)
{
	if (book->num == 0)
	{
		printf("the addrbook is empty\n");
		return 0;
	}
	personInfo* lastInfo = &book->person[book->num - 1];
	printf("Delete ppersonInfo!\n");
	printf("input his\her name\n");
	char name[128] = " ";
	scanf("%s", name);
	for (int i = 0; i < book->num; i++)
	{
		personInfo* Info = &book->person[i];
		int ret = strcmp(Info, name);
		if (ret != 0)
		{
			printf("no this preson\n");
		}
		else
		{
			*Info = *lastInfo;
			book->num--;
			printf("delete successfully\n");
		}
	}
}
void Find(addrbook* book)
{
	if (book->num == 0)
	{
		printf("the addrbook is empty\n");
		return 0;
	}
	printf("Find personInfo\n");
	char name[128] = " ";
	printf("input his\her name\n");
	scanf("%s", name);
	for (int i = 0; i < book->num; i++)
	{
		personInfo* Info = &book->person[i];
		int ret = strcmp(Info, name);
		if (ret != 0)
		{
			printf("no this preson\n");
		}
		else
		{
			printf("found it\n");
			printf("%s %c %d %s %s\n", Info->name, Info->sex, Info->age, Info->phone, Info->home);
		}
	}
}
void Modify(addrbook* book)
{
	if (book->num == 0)
	{
		printf("the addrbook is empty\n");
		return 0;
	}
	printf("Modify personInfo\n");
	int id = 0;
	printf("input your target num\n");
	scanf("%d", &id);
	if (id < 0 || id >= book->num)
	{
		printf("input wrong\n");
		return 0;
	}
	else
	{
		personInfo* Info = &book->person[id];
		printf("input new name\n");
		scanf("%s", Info->name);
		printf("input new sex\n");
		getchar();
		scanf("%c", &Info->sex);
		printf("input new age\n");
		scanf("%d", &Info->age);
		printf("input new phone\n");
		scanf("%s", Info->phone);
		printf("input new home\n");
		scanf("%s", Info->home);
		printf("modify successfully\n");
	}
}
void Show(addrbook* book)
{
	printf("Show personInfo!\n");
	if (book->num == 0)
	{
		printf("the addrbook is empty\n");
		return 0;
	}
	int i = 0;
	for (i = 0; i < book->num; i++)
	{
		personInfo* Info = &book->person[i];
		printf("[%d] %s %c %d %s %s\n", i, Info->name, Info->sex, Info->age, Info->phone, Info->home);
	}
}
void Clear(addrbook* book)
{
	printf("Clear all person!\n");
	printf("really?  Y\N\n");
	char choice[100];
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0)
	{
		book->num = 0;
		printf("Clear successfully!\n");
	}
	else
	{
		printf("the operate has been canceled\n");
		return 0;
	}
}
void Sort(addrbook* book)
{
	printf("Sort personInfo!\n");
	if (book->num == 0)
	{
		printf("the addrbook is empty\n");
		return 0;
	}
	if (book->num == 1)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < book->num - 1; i++)
		{
			for (int j = 0; j < book->num - 1 - i; j++)
			{
				personInfo*  p1 = &book->person[j];
				personInfo*  p2 = &book->person[j + 1];
				personInfo tem;
				if (strcmp(p1->name, p2->name) > 0)
				{
					tem = *p1;
					*p1 = *p2;
					*p2 = tem;
				}
			}
		}
	}
	printf("sort successfully\n");
}
int main()
{
	addrbook my_book;
	Init(&my_book);
	typedef (*func)(addrbook*);
	func oprate[] = { NULL,Add,Delete,Find,Modify,Show,Clear,Sort };
	while (1)
	{
		int choice = menu();
		if (choice == 0)
		{
			break;
		}
		else if (choice < 0 || choice>7)
		{
			printf("input wrong\n");
			continue;
		}
		oprate[choice](&my_book);
	}
	return 0;
}

