#include"��ͷ.h"

void swap(int* array, int num1, int num2) {
	int tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
}

// ��������
void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		//������Ԫ��
		int end = i;
		int key = a[end + 1];
		//Ѱ�ұ�keyС��Ԫ���±�
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
		//�����ݲ���
		//end: �������е����һ��λ��
		int end = i;
		//key: �����������
		int key = array[end + 1];
		//�ҵ���һ��С�ڵ���key��λ��
		while (end >= 0 && array[end] > key)
		{
			//��ǰ��������ƶ�
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}
// ϣ������
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		//���ò���
		gap = gap / 3 + 1;
		//���ݲ����ֳ�������
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int key = a[end + gap];
			//�Էֵ�����в�������
			while (a[end] >= key && end >= 0) {
				a[end + gap] = a[end];
				end = end - gap;
			}
			a[end + gap] = key;
		}
	}
}

// ѡ������
void SelectSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		//δ�������ݵ������
		int start = i;
		//��Сֵ�±�
		int min = start;
		//Ѱ����Сֵ�±�
		for (int j = min + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		//����Сֵ��δ������������˽��н���
		swap(a, start, min);
	}
}

void SelectSort2(int* a, int n) {
	int start = 0;
	int end = n - 1;
	while(start < end){
		//�������ֵ����Сֵ
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
		//��Сֵ����start
		swap(a, min, start);
		//�����ֵ��С���ǽ���ǰ����Сֵ�±꣬���start��max���±���н���
		if (max == start) {
			max = min;
		}
		swap(a, max, end);
		start++;
		end--;
	}
}

// ������
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
	//����
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDwon(a, n, i);
	}
	//ѭ��ɾ��
	while (n) {
		swap(a, 0, n - 1);
		n--;
		AdjustDwon(a, n, 0);
	}
}

// ð������
void BubbleSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		//���Ѿ���������У�ͨ����ǩ��ǰ�����������
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j+1]) {
				//��������
				flag = 0;
				swap(a, j + 1, j);
			}
		}
		//û����Ԫ�ؽ�����Ԫ���Ѿ�����
		if (flag == 1) {
			break;
		}
	}
}

// ��������ݹ�ʵ��

int getmid(int*array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	// begin, mid, endѡ���м�ֵ��λ��
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

// ��������hoare�汾
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
// ���������ڿӷ�
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
// ��������ǰ��ָ�뷨
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

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right) {
	Stack st;
	stackInit(&st, 100);
	//nΪҪ�����Ԫ������
	int n = right + left + 1;
	if (n > 1) {
		//��Ҫ��������е�ĩβ�Ϳ�ͷ�±����ջ
		stackPush(&st, right);
		stackPush(&st, left);
	}
	//��ջ�ﻹ��Ԫ�أ���ζ�Ż���δ�������������
	while (stackEmpty(&st) != 1) {
		//��Ҫ���������ʼĩȡ��
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//ȷ����׼ֵ���±�
		int keypos = PartSort1(a, begin, end);
		//��׼ֵλ�õĺ�벿������
		if (keypos + 1 < end) {
			stackPush(&st, end);
			stackPush(&st, keypos + 1);
		}
		//��׼ֵλ�õ�ǰ�벿������
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
// �鲢����ݹ�ʵ��
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
	//���Ƿ���ʣ�µ�Ԫ������û��ѭ�����ӵ�֮ǰ�Ѿ��ź����������
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

	//���ȱ�֤������������������������
	MergeSortR(tmp, a, begin, mid);
	MergeSortR(tmp, a, mid + 1, end);

	//�ϲ���������
	merge(a, tmp, begin, mid, end);
}
void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	MergeSortR(tmp, a, 0, n - 1);
	free(tmp);
}
// �鲢����ǵݹ�ʵ��
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

// ��������
void CountSort(int* a, int n) {
	//Ѱ����Сֵ�����ֵ
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
	//���ٸ����ռ�
	int range = max - min + 1;
	int* help_a = (int*)malloc(sizeof(int)*range);
	memset(help_a, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++) {
		help_a[a[i] - min]++;
	}
	//��ԭԭ������
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (help_a[i]--) {
			a[idx++] = min + i;
		}
	}
	free(help_a);
}
