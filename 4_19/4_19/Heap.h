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

//��ʼ��
void Init(Heap* hp)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	hp->_size = 0;
}
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	Init(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
}
//����
void swap(HPDataType* num1,HPDataType* num2)
{
	HPDataType tmp = 0;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
//���µ���
void Down(HPDataType* num, int Size, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (parent < Size)//�����ڵ�С��size
	{
		if (child + 1 < Size && num[child] > num[child + 1])//ȷ���Һ��Ӵ��ڲ���С������
		{
			child++;//���û��ĺ���ȷ��Ϊ�Һ���
		}
		if (child < Size && num[child] < num[parent])//ȷ�����Ӵ��ڲ��Һ���С�ڸ��׽ڵ�
		{
			swap(&num[child], &num[parent]);//����
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����
void HeapSort(int* a, int n);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();
