#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//初始化
void Init(Heap* hp)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	hp->_size = 0;
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	Init(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
}
//交换
void swap(HPDataType* num1,HPDataType* num2)
{
	HPDataType tmp = 0;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
//向下调整
void Down(HPDataType* num, int Size, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (parent < Size)//当根节点小于size
	{
		if (child + 1 < Size && num[child] > num[child + 1])//确保右孩子存在并且小于左孩子
		{
			child++;//将置换的孩子确定为右孩子
		}
		if (child < Size && num[child] < num[parent])//确保左孩子存在并且孩子小于父亲节点
		{
			swap(&num[child], &num[parent]);//交换
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// 对数组进行堆排序
void HeapSort(int* a, int n);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();
