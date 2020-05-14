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
// 快速排序hoare版本
int PartSort1(int* a, int left, int right) {

}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);

// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);
