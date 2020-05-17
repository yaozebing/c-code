#include"标头.h"

void swap(int* array, int num1, int num2) {
	int tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
}

// 插入排序
void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		//插入新元素
		int end = i;
		int key = a[end + 1];
		//寻找比key小的元素下标
		while (end >= 0 && a[end] > key) {
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = key;  
	}
}
void insertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//新数据插入
		//end: 有序序列的最后一个位置
		int end = i;
		//key: 待插入的数据
		int key = array[end + 1];
		//找到第一个小于等于key的位置
		while (end >= 0 && array[end] > key)
		{
			//当前数据向后移动
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}
// 希尔排序
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		//设置步长
		gap = gap / 3 + 1;
		//根据步长分成若干组
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int key = a[end + gap];
			//对分的组进行插入排序
			while (a[end] >= key && end >= 0) {
				a[end + gap] = a[end];
				end = end - gap;
			}
			a[end + gap] = key;
		}
	}
}

// 选择排序
void SelectSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		//未排序数据的最左边
		int start = i;
		//最小值下标
		int min = start;
		//寻找最小值下标
		for (int j = min + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		//将最小值与未排序数据最左端进行交换
		swap(a, start, min);
	}
}

void SelectSort2(int* a, int n) {
	int start = 0;
	int end = n - 1;
	while(start < end){
		//设置最大值和最小值
		int min = start;
		int max = start;
		for (int j = start + 1; j <= end; j++) {
			if (a[j] <= a[min]) {
				min = j;
			}
			if (a[j] >= a[max]) {
				max = j;
			}
		}
		//最小值放在start
		swap(a, min, start);
		//若最大值的小标是交换前的最小值下标，则把start和max的下标进行交换
		if (max == start) {
			max = min;
		}
		swap(a, max, end);
		start++;
		end--;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root){
		int parent = root;
		int child = 2 * parent + 1;
		while (child < n) {
			if (a[child] < a[child + 1]) {
				child++;
			}
			if (child < n && a[parent] < a[child]) {
				swap(a, parent, child);
			}
			parent = child;
			child = 2 * parent + 1;
		}
	}
void HeapSort(int* a, int n) {
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDwon(a, n, i);
	}
	//循环删除
	while (n) {
		swap(a, 0, n - 1);
		n--;
		AdjustDwon(a, n, 0);
	}
}

// 冒泡排序
void BubbleSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		//对已经有序的序列，通过标签提前结束排序过程
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j+1]) {
				//发生交换
				flag = 0;
				swap(a, j + 1, j);
			}
		}
		//没发生元素交换，元素已经有序
		if (flag == 1) {
			break;
		}
	}
}

// 快速排序递归实现

int getmid(int*array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	// begin, mid, end选择中间值的位置
	if (array[begin] < array[mid])
	{
		// begin <  mid;
		if (array[mid] < array[end])
			return mid;
		else {
			// begin < mid,  end <= mid
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
	else
	{
		// begin >= mid;
		if (array[mid] > array[end])
			return mid;
		else
		{
			//begin >= mid, end >= mid
			if (array[begin] < array[end])
				return begin;
			else
				return end;
		}
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right) {
	int begin = left;
	int key = a[begin];
	while (left < right) {
		while (right > left && a[right] >= key) {
			right--;
		}
		while (left < right && a[left] <= key) {
			left++;
		}
		swap(a, left, right);
	}
	swap(a, begin, left);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right) {
	int begin = left;
	int key = a[left];
	while (left < right) {
		while (left<right && a[right]>=key) {
			right--;
		}
		a[left] = a[right];
		while (left < right && a[left] <= key) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right) {
	int begin = left;
	int prev = begin;
	int key = a[left];
	int cur = prev + 1;
	while (cur <= right) {
		if (a[cur] < key && ++prev!=cur){
			swap(a, prev, cur);
		}
		cur++;
	}
	swap(a, begin, prev);
}
void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	int keypo = PartSort3(a, left, right);
	QuickSort(a, left, keypo - 1);
	QuickSort(a, keypo + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right) {
	Stack st;
	stackInit(&st, 100);
	//n为要排序的元素数量
	int n = right + left + 1;
	if (n > 1) {
		//将要排序的序列的末尾和开头下标存入栈
		stackPush(&st, right);
		stackPush(&st, left);
	}
	//当栈里还有元素，意味着还有未进行排序的序列
	while (stackEmpty(&st) != 1) {
		//将要排序的序列始末取出
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//确定基准值的下标
		int keypos = PartSort1(a, begin, end);
		//基准值位置的后半部分序列
		if (keypos + 1 < end) {
			stackPush(&st, end);
			stackPush(&st, keypos + 1);
		}
		//基准值位置的前半部分序列
		if (keypos - 1 > begin) {
			stackPush(&st, keypos - 1);
			stackPush(&st, begin);
		}
	}
}

void QuickSortNonR2(int* a, int left, int right) {
	Queue q;
	queueInit(&q);
	int n = right - left + 1;
	if (n > 1) {
		queuePush(&q, left);
		queuePush(&q, right);
	}
	while(queueEmpty(&q) != 1){
		int begin = queueFront(&q);
		queuePop(&q);
		int end = queueBack(&q);
		queuePop(&q);
		int keypos = PartSort2(a, begin, end);
		if (keypos - 1 > begin) {
			queuePush(&q, begin);
			queuePush(&q, keypos - 1);
		}
		if (keypos + 1 < end) {
			queuePush(&q, keypos + 1);
			queuePush(&q, end);
		}
	}
}
// 归并排序递归实现
void merge(int* a, int* tmp, int begin, int mid, int end) {
	//
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] <= a[begin2]) {
			tmp[idx++] = a[begin1++];
		}
		else {
			tmp[idx++] = a[begin2++];
		}
	}
	//看是否有剩下的元素序列没有循环，接到之前已经排好序的序列里
	if (begin1 <= end1) {
		memcpy(tmp + idx, a + begin1, sizeof(int)*(end1 - begin1 + 1));
	}
	if (begin2 <= end2) {
		memcpy(tmp + idx, a + begin2, sizeof(int)*(end2 - begin2 + 1));
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

void MergeSortR(int* tmp, int* a, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int mid = begin + (end - begin) / 2;

	//首先保证子区间有序，首先子区间排序
	MergeSortR(tmp, a, begin, mid);
	MergeSortR(tmp, a, mid + 1, end);

	//合并有序区间
	merge(a, tmp, begin, mid, end);
}
void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	MergeSortR(tmp, a, 0, n - 1);
	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	int k = 1;
	while (k < n) {
		for (int i = 0; i < n; i += 2 * k) {
			int begin = i;
			int mid = i + k - 1;
			if (mid >= n - 1) {
				continue;
			}
			int end = i + 2 * k - 1;
			if (end >= n) {
				end = n - 1;
			}
			merge(a, tmp, begin, mid, end);
		}
		k *= 2;
	}
}

// 计数排序
void CountSort(int* a, int n) {
	//寻找最小值，最大值
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	//开辟辅助空间
	int range = max - min + 1;
	int* help_a = (int*)malloc(sizeof(int)*range);
	memset(help_a, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++) {
		help_a[a[i] - min]++;
	}
	//还原原来数据
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (help_a[i]--) {
			a[idx++] = min + i;
		}
	}
	free(help_a);
}
