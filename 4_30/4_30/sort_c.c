#pragma once
#include"sort.h"

typedef int QuDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QueueNode;
// 队列的结构 
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

QueueNode * BuyQueueNode(QuDataType x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}

void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}

void QueuePush(Queue* q, QuDataType x)
{
	QueueNode * cur = BuyQueueNode(x);

	if (q->_front == NULL)
	{
		q->_front = q->_rear = cur;
	}
	else
	{
		q->_rear->_next = cur;
		q->_rear = cur;
	}
}

void QueuePop(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}
	QueueNode* tmp = q->_front->_next;
	free(q->_front);
	q->_front = tmp;
}

QuDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}

QuDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}

int QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}

int QueueSize(Queue* q)
{
	QListNode * cur;
	int count = 0;
	for (cur = q->_front; cur; cur = cur->_next)
	{
		count++;
	}
	return count;
}

void QueueDestory(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}

	while (q->_front)
	{
		QueuePop(q);
	}
}

void swap(int* array,int num1, int num2) {
	int tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
}
void InsertSort(int* a, int n) {
	int end = 0;
	//新数据插入
	//end；有序数列最后一个元素
	for (end = 0; end < n - 1; end++) {
		//key；即将排序的元素
		int key = a[end + 1];
		//找到第一个小于等于插入元素的元素
		while (end >= 0 && a[end] > key) {
			//当前数据向后移动
			a[end + 1] = a[end];
			end--;
		}
		//在有序数列内插入新元素
		a[end + 1] = key;
	}
}
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap < 1) {
		//确定步长，并且保证最后一次进行排序步长为1
		gap = gap / 3 + 1;
		//进行插入排序
		//通过步长将元素进行分组
		//将不同组元素进行排序
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int key = a[end + 1];
			while (end >= 0 && a[end] > key) {
				a[end + 1] = a[end];
				end--;
			}
			a[end + 1] = key;
		}
	}
}
//最小值选择
void SelectSort(int* a, int n){
	for (int i = 0; i < n; i++) {
		//start为要进行排序的元素下标
		int start = i;
		//min为最小值下标
		int min = start;
		//寻找最小值下标
		for (int j = start + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		//将最小值放到它的正确位置
		swap(a, start, min);
	}
}
//最大值选择
void SelectSortmax(int* a, int n) {
	for (int i = n - 1; i > 0; i--) {
		//end为要进行排序的元素下标
		int end = i;
		//max为最大元素下标
		int max = end;
		//寻找最大元素
		for (int j = end - 1; j >= 0; j--) {
			if (a[max] < a[j]) {
				max = j;
			}
		}
		//将最大元素放到正确位置上
		swap(a, max, end);
	}
}
void ShiftDown(int* a, int n, int root) {
	int child = root * 2 + 1;
	while (child < n) {
		if (a[child] > a[child + 1] && child + 1 < n) {
			child++;
		}
		if (a[root]>a[child]) {
			swap(a, root, child);
			root = child;
			child = root * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* a, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--) {
		ShiftDown(a, n, i);
	}
	//删除输出
	while (n) {
		swap(a, 0, n - 1);
		n--;
		ShiftDown(a, n, 0);
	}
}

void BubbleSort(int* a, int n) {
	while (n) {
		//若一轮冒泡排序过程中没有元素交换，则通过标签退出排序
		int flag = 1;
		int end = n;
		for (int i = 1; i < end; i++) {
			//相邻元素比较，大的放在后面
			if (a[i] < a[i - 1]) {
				swap(a, i, i - 1);
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
		n--;
	}
}

int PartSort1(int* a, int left, int right) {
	int key = a[left];
	int begin = left;
	while (begin < right) {
		//寻找到比key小的元素下标
		while (begin < right && a[right] >= key) {
			right--;
		}
		//寻找到比key大的元素下标
		while (begin < right && a[begin] <= key) {
			begin++;
		}
		swap(a, begin, right);
	}
	swap(a, left, begin);
	return begin;
}
int PartSort2(int* a, int left, int right) {
	int key = a[left];
	while (left < right) {
		//从后向前找
		while (left < right && a[right] >= key) {
			right--;
		}
		a[left] = a[right];
		while (left <right && a[left] <= key) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
int PartSort3(int* a, int left, int right) {
	//最后一个小于基准值的位置
	int prev = left;
	//新发现的下一个小于基准值的位置
	int cur = prev + 1;
	//基准值
	int key = a[left];
	while (cur <= right) {
		if (a[cur] < key && ++prev != cur) {
			swap(a, prev, cur);
		}
		cur++;
	}
	swap(a, left, prev);
	return prev;
}

void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	int keypos = PartSort3(a, left, right);
	QuickSort(a, left, keypos - 1);
	QuickSort(a, keypos + 1, right);
}

void QuickSort(int* a, int left, int right) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, left);
	QueuePush(&q, right);
	int keypos = PartSort3(a, left, right);
	while (QueueEmpty(&q)) {
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueBack(&q);
		QueuePop(&q);
		int key = PartSort3(a, begin, end);
		if (begin < key - 1) {
			QueuePush(&q, begin);
			QueuePush(&q, key - 1);
		}
		if (end > key + 1) {
			QueuePush(&q, key + 1);
			QueuePush(&q, end);
		}
	}
}
