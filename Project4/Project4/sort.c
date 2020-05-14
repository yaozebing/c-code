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
// ��������hoare�汾
int PartSort1(int* a, int left, int right) {

}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);
