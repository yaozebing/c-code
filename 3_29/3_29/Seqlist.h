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
//// �����ݵĹ���:��ɾ��� 
//void SeqListInit(SeqList* ps)
//{
//	if (ps == NULL)//�Դ����˳�������п�
//		{
//			return 0;
//		}
//	ps->a = (SLDateType*)malloc(2 * sizeof(SLDateType));//����1000���������͵Ŀռ�
//	ps->size = 0;//Ŀǰ����Ϊ0
//	ps->capacity = 1000;//����1000
//}
//void SeqListDestory(SeqList* ps)
//{
//	if (ps == NULL)//�Դ����˳�������п�
//	{
//		return 0;
//	}
//	ps->size = 0;//��������Ϊ0
//}
//
//void SeqListPrint(SeqList* ps)
//{
//	if (ps == NULL)//�Դ����˳�������п�
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
//	if (ps == NULL)//�Դ����˳�������п�
//	{
//		return 0;
//	}
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity += 1;//�ı�ṹ���a������
//		ps->a = (SLDateType*)realloc(*ps->a, (ps->capacity) * sizeof(SLDateType));//��ralloc������a��������
//
//		////��malloc��������
//		//ps->capacity += 100;
//		//SLDateType* sl = (SLDateType*)malloc(ps->capacity * sizeof(SLDateType));
//		//free(ps->a);//�ͷ�ԭ���Ŀռ�
//		//ps->a = sl;
//	}
//}
//void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
//{
//	if (ps == NULL)//�Դ����˳�������п�
//	{
//		return 0;
//	}
//	if (pos <= ps->size)//�ж�λ���Ƿ����
//	{
//		SeqlistCapcity(ps);
//		for (int i = ps->size; i > pos; i--)//��pos��pos֮���Ԫ������ƶ�һλ
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
//	if (ps == NULL)//�Դ����˳�������п�
//	{
//		return 0;
//	}
//	if (pos < ps->size)//�ж�λ���Ƿ����
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
//	//if (ps == NULL)//�Դ����˳�������п�
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
//	//if (ps == NULL)//�Դ����˳�������п�
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
//	//if (ps == NULL)//�Դ����˳�������п�
//	//{
//	//	return 0;
//	//}
//	//SeqlistCapcity(ps);//�ж�˳����Ƿ���������������
//	//for (int i = ps->size; i >0; i--)
//	//{
//	//	ps->a[i] = ps->a[i - 1];//��Ԫ�ؽ����ƶ�
//	//}
//	//ps->a[0] = x;//��Ԫ�ظ�ֵ
//	//ps->size++;//˳����С+1
//	SeqListInsert(ps, 0, x);
//}
//void SeqListPopFront(SeqList* ps)
//{
//	//if (ps == NULL)//�Դ����˳�������п�
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
//// ˳������
//int SeqListFind(SeqList* ps, SLDateType x)
//{
//	if (ps == NULL)//�Դ����˳�������п�
//	{
//		return 0;
//	}
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->a[i] == x)
//		{
//			printf("��%d��\n", i + 1);//�����д����������������λ��
//			return 0;
//		}
//	}
//	printf("no this num\n");
//}
//// ˳�����posλ�ò���x
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