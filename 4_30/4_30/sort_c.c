#pragma once
#include"sort.h"

void swap(int* array,int num1, int num2) {
	int tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
}
void InsertSort(int* a, int n) {
	int end = 0;
	//�����ݲ���
	//end�������������һ��Ԫ��
	for (end = 0; end < n - 1; end++) {
		//key�����������Ԫ��
		int key = a[end + 1];
		//�ҵ���һ��С�ڵ��ڲ���Ԫ�ص�Ԫ��
		while (end >= 0 && a[end] > key) {
			//��ǰ��������ƶ�
			a[end + 1] = a[end];
			end--;
		}
		//�����������ڲ�����Ԫ��
		a[end + 1] = key;
	}
}
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap < 1) {
		//ȷ�����������ұ�֤���һ�ν������򲽳�Ϊ1
		gap = gap / 3 + 1;
		//���в�������
		//ͨ��������Ԫ�ؽ��з���
		//����ͬ��Ԫ�ؽ�������
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
//��Сֵѡ��
void SelectSort(int* a, int n){
	for (int i = 0; i < n; i++) {
		//startΪҪ���������Ԫ���±�
		int start = i;
		//minΪ��Сֵ�±�
		int min = start;
		//Ѱ����Сֵ�±�
		for (int j = start + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		//����Сֵ�ŵ�������ȷλ��
		swap(a, start, min);
	}
}
//���ֵѡ��
void SelectSortmax(int* a, int n) {
	for (int i = n - 1; i > 0; i--) {
		//endΪҪ���������Ԫ���±�
		int end = i;
		//maxΪ���Ԫ���±�
		int max = end;
		//Ѱ�����Ԫ��
		for (int j = end - 1; j >= 0; j--) {
			if (a[max] < a[j]) {
				max = j;
			}
		}
		//�����Ԫ�طŵ���ȷλ����
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
	//ɾ�����
	while (n) {
		swap(a, 0, n - 1);
		n--;
		ShiftDown(a, n, 0);
	}
}

void BubbleSort(int* a, int n) {
	while (n) {
		//��һ��ð�����������û��Ԫ�ؽ�������ͨ����ǩ�˳�����
		int flag = 1;
		int end = n;
		for (int i = 1; i < end; i++) {
			//����Ԫ�رȽϣ���ķ��ں���
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
		//Ѱ�ҵ���keyС��Ԫ���±�
		while (begin < right && a[right] >= key) {
			right--;
		}
		//Ѱ�ҵ���key���Ԫ���±�
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
		//�Ӻ���ǰ��
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
	//���һ��С�ڻ�׼ֵ��λ��
	int prev = left;
	//�·��ֵ���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;
	//��׼ֵ
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