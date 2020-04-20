#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* _a;
//	int _size;
//	int _capacity;
//}Heap;
////����
//void swap(HPDataType* num1, HPDataType* num2)
//{
//	HPDataType tmp = 0;
//	tmp = *num1;
//	*num1 = *num2;
//	*num2 = tmp;
//}
////���µ���
//void Down(HPDataType* num, int Size, int root)
//{
//	int parent = root;
//	int child = 2 * parent + 1;
//	while (child < Size)//�����ڵ�С��size
//	{
//		if (child + 1 < Size && num[child] > num[child + 1])//ȷ���Һ��Ӵ��ڲ���С������
//		{
//			child++;//���û��ĺ���ȷ��Ϊ�Һ���
//		}
//		if (num[child] < num[parent])//ȷ�����Ӵ��ڲ��Һ���С�ڸ��׽ڵ�
//		{
//			swap(&num[child], &num[parent]);//����
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
////����
//void HeapAdd(Heap* hp)
//{
//	if (hp->_size == hp->_capacity)
//	{
//		hp->_capacity *= 2;
//		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
//	}
//}
//// �ѵĹ���
//void HeapCreate(Heap* hp, HPDataType* a, int n)
//{
//	int i = 0;
//	assert(hp && a);
//	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
//	hp->_size = n;//��ʼ��hp
//	
//	//int root = (n - 2) / 2;//ȷ�����һ�����׽ڵ�
//	//while (root >= 0)//����󵽳�ʼ���ڵ�������µ���
//	//{
//	//	Down(a, n, root);
//	//	root--;
//	//}
//	//hp->_a = a;
//
//	for (i = 0; i < n; i++)
//	{
//		hp->_a[i] = a[i];
//	}
//	for (i = (n - 2) / 2; i >= 0; i--)
//	{
//		Down(hp->_a, hp->_size, i);
//	}
//	//i = 0;
//	//while (i < n)
//	//{
//	//	printf("%d ", hp->_a[i]);
//	//	i++;
//	//}
//	//printf("\n");
//}
//
//// �ѵ�����
//void HeapDestory(Heap* hp)
//{
//	//free(hp->_a);
//	hp->_capacity = 0;
//	hp->_size = 0;
//}
////���ϵ���
//void Up(Heap* hp, int child)
//{
//	int parent = (child - 1) / 2;//�ҵ��¼ӵĽڵ�ĸ��׽ڵ�
//	while (child > 0)
//	{
//		if (hp->_a[parent] > hp->_a[child])
//		{
//			swap(&hp->_a[parent], &hp->_a[child]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//// �ѵĲ���
//void HeapPush(Heap* hp, HPDataType x)
//{
//	HeapAdd(hp);
//	hp->_a[hp->_size++] = x;
//	Up(hp, hp->_size - 1);
//	int i = 0;
//	while (i < hp->_size)
//	{
//		printf("%d ", hp->_a[i]);
//		i++;
//	}
//	printf("\n");
//}
//// �ѵ�ɾ��
//void HeapPop(Heap* hp)
//{
//	if (HeapEmpty(hp))
//	{
//		return;
//	}
//	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//��Ԫ�������Ԫ�ؽ���
//	hp->_size--;
//	Down(hp->_a, hp->_size, 0);//����Ԫ�����µ���
//	int i = 0;
//	//while (i < hp->_size)
//	//{
//	//	printf("%d ", hp->_a[i]);
//	//	i++;
//	//}
//}
//// ȡ�Ѷ�������
//HPDataType HeapTop(Heap* hp)
//{
//	if (HeapEmpty(hp))
//	{
//		return;
//	}
//	return hp->_a[0];
//}
//// �ѵ����ݸ���
//int HeapSize(Heap* hp)
//{
//	return hp->_size;
//}
//// �ѵ��п�
//int HeapEmpty(Heap* hp)
//{
//	return hp->_size == 0;
//}
//
//// ��������ж�����
//void HeapSort(int* a, int n);
//
//// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
//// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
//// ��Ҫע�⣺
//// ������ǰK��������K������С��
//// ����С��ǰK��������K�����Ĵ��
//void PrintTopK(int* a, int n, int k)
//{
//	Heap hp;
//	HeapCreate(&hp, a, n);
//	while (k > 0)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//		k--;
//		printf("\n");
//	}
//}
//
// 

