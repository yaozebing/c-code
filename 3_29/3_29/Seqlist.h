//// SeqList.h
//#pragma once
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//
//typedef int SLDateType;
//typedef struct SeqList
//{
//	SLDateType* a;
//	size_t size;
//	size_t capacity; // unsigned int
//}SeqList;
//
//// 对数据的管理:增删查改 
//void SeqListInit(SeqList* ps)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//		{
//			return 0;
//		}
//	ps->a = (SLDateType*)malloc(2 * sizeof(SLDateType));//开辟1000个数据类型的空间
//	ps->size = 0;//目前数量为0
//	ps->capacity = 1000;//容量1000
//}
//void SeqListDestory(SeqList* ps)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//	{
//		return 0;
//	}
//	ps->size = 0;//将数量调为0
//}
//
//void SeqListPrint(SeqList* ps)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//	{
//		return 0;
//	}
//	if (ps->size > 0)
//	{
//		for (int i = 0; i < ps->size; i++)
//		{
//			printf("%d ", ps->a[i]);
//		}
//		printf("\n");
//	}
//}
//void SeqlistCapcity(SeqList* ps)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//	{
//		return 0;
//	}
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity += 1;//改变结构体的a的容量
//		ps->a = (SLDateType*)realloc(*ps->a, (ps->capacity) * sizeof(SLDateType));//用ralloc函数对a进行扩容
//
//		////用malloc进行扩容
//		//ps->capacity += 100;
//		//SLDateType* sl = (SLDateType*)malloc(ps->capacity * sizeof(SLDateType));
//		//free(ps->a);//释放原来的空间
//		//ps->a = sl;
//	}
//}
//void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//	{
//		return 0;
//	}
//	if (pos <= ps->size)//判断位置是否合理
//	{
//		SeqlistCapcity(ps);
//		for (int i = ps->size; i > pos; i--)//将pos及pos之后的元素向后移动一位
//		{
//			ps->a[i] = ps->a[i - 1];
//		}
//		ps->a[pos] = x;
//		ps->size++;
//	}
//	else
//	{
//		printf("input wrong\n");
//	}
//}
//void SeqListErase(SeqList* ps, size_t pos)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//	{
//		return 0;
//	}
//	if (pos < ps->size)//判断位置是否合理
//	{
//		SeqlistCapcity(ps);
//		for (int i = pos; i < ps->size - 1; i++)
//		{
//			ps->a[i] = ps->a[i + 1];
//		}
//		ps->size--;
//	}
//}
//void SeqListPopBack(SeqList* ps)
//{
//	//if (ps == NULL)//对传入的顺序表进行判空
//	//{
//	//	return 0;
//	//}
//	if (ps->size > 0)
//	{
//		//ps->size--;
//		SeqListErase(ps, --ps->size);
//	}
//}
//void SeqListPushBack(SeqList* ps, SLDateType x)
//{
//	//if (ps == NULL)//对传入的顺序表进行判空
//	//{
//	//	return 0;
//	//}
//	//SeqlistCapcity(ps);
//	//ps->a[ps->size] = x;
//	//ps->size++;
//	SeqListInsert(ps, ps->size, x);
//}
//void SeqListPushFront(SeqList* ps, SLDateType x)
//{
//	//if (ps == NULL)//对传入的顺序表进行判空
//	//{
//	//	return 0;
//	//}
//	//SeqlistCapcity(ps);//判断顺序表是否已满并进行扩容
//	//for (int i = ps->size; i >0; i--)
//	//{
//	//	ps->a[i] = ps->a[i - 1];//将元素进行移动
//	//}
//	//ps->a[0] = x;//首元素赋值
//	//ps->size++;//顺序表大小+1
//	SeqListInsert(ps, 0, x);
//}
//void SeqListPopFront(SeqList* ps)
//{
//	//if (ps == NULL)//对传入的顺序表进行判空
//	//{
//	//	return 0;
//	//}
//	//for (int i = 0; i < ps->size - 1; i++)
//	//{
//	//	ps->a[i] = ps->a[i + 1];
//	//}
//	//ps->size--;
//	SeqListErase(ps, 0);
//}
//
//// 顺序表查找
//int SeqListFind(SeqList* ps, SLDateType x)
//{
//	if (ps == NULL)//对传入的顺序表进行判空
//	{
//		return 0;
//	}
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->a[i] == x)
//		{
//			printf("第%d个\n", i + 1);//若是有此数，则输出此数的位置
//			return 0;
//		}
//	}
//	printf("no this num\n");
//}
//// 顺序表在pos位置插入x
//
////int* addToArrayForm(int* A, int ASize, int K, int* returnSize) 
////{
////	int idx = ASize - 1;
////	int step = 0;
////	int i = 0;
////	int* p = (int*)malloc((ASize + 1) * sizeof(int));
////	while (i < ASize)
////	{
////		p[i] = A[ASize - i - 1];
////		i++;
////	}
////	p[ASize] = 0;
////	i = 0;
////	while (i < ASize)
////	{
////		p[i] = p[i] + K % 10 + step;
////		step = p[i] / 10;
////
////	}
////}
//
//// 