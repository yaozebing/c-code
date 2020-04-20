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
////交换
//void swap(HPDataType* num1, HPDataType* num2)
//{
//	HPDataType tmp = 0;
//	tmp = *num1;
//	*num1 = *num2;
//	*num2 = tmp;
//}
////向下调整
//void Down(HPDataType* num, int Size, int root)
//{
//	int parent = root;
//	int child = 2 * parent + 1;
//	while (child < Size)//当根节点小于size
//	{
//		if (child + 1 < Size && num[child] > num[child + 1])//确保右孩子存在并且小于左孩子
//		{
//			child++;//将置换的孩子确定为右孩子
//		}
//		if (num[child] < num[parent])//确保左孩子存在并且孩子小于父亲节点
//		{
//			swap(&num[child], &num[parent]);//交换
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
////扩容
//void HeapAdd(Heap* hp)
//{
//	if (hp->_size == hp->_capacity)
//	{
//		hp->_capacity *= 2;
//		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
//	}
//}
//// 堆的构建
//void HeapCreate(Heap* hp, HPDataType* a, int n)
//{
//	int i = 0;
//	assert(hp && a);
//	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
//	hp->_size = n;//初始化hp
//	
//	//int root = (n - 2) / 2;//确定最后一个父亲节点
//	//while (root >= 0)//从最后到初始根节点进行向下调整
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
//// 堆的销毁
//void HeapDestory(Heap* hp)
//{
//	//free(hp->_a);
//	hp->_capacity = 0;
//	hp->_size = 0;
//}
////向上调整
//void Up(Heap* hp, int child)
//{
//	int parent = (child - 1) / 2;//找到新加的节点的父亲节点
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
//// 堆的插入
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
//// 堆的删除
//void HeapPop(Heap* hp)
//{
//	if (HeapEmpty(hp))
//	{
//		return;
//	}
//	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//首元素与最后元素交换
//	hp->_size--;
//	Down(hp->_a, hp->_size, 0);//将首元素向下调整
//	int i = 0;
//	//while (i < hp->_size)
//	//{
//	//	printf("%d ", hp->_a[i]);
//	//	i++;
//	//}
//}
//// 取堆顶的数据
//HPDataType HeapTop(Heap* hp)
//{
//	if (HeapEmpty(hp))
//	{
//		return;
//	}
//	return hp->_a[0];
//}
//// 堆的数据个数
//int HeapSize(Heap* hp)
//{
//	return hp->_size;
//}
//// 堆的判空
//int HeapEmpty(Heap* hp)
//{
//	return hp->_size == 0;
//}
//
//// 对数组进行堆排序
//void HeapSort(int* a, int n);
//
//// TopK问题：找出N个数里面最大/最小的前K个问题。
//// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
//// 需要注意：
//// 找最大的前K个，建立K个数的小堆
//// 找最小的前K个，建立K个数的大堆
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

