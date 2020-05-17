#include"БъЭЗ.h"


int main() {
	int num[] = { 4,6,1,8,4,9,5,2,1,7,3 };
	int sz = sizeof(num) / sizeof(num[0]);

	int* num0 = (int*)malloc(sizeof(num));
	memcpy(num0, num, sizeof(num));
	printf("insertsort\n");
	InsertSort(num0, sz);
	int n = 0;
	while (n < sz) {
		printf("%d ", num0[n]);
		n++;
	}
	printf("\n");

	int* num1 = (int*)malloc(sizeof(num));
	memcpy(num1, num, sizeof(num));
	printf("shellsort\n");
	ShellSort(num1, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num1[n]);
		n++;
	}
	printf("\n");
	
	int* num2 = (int*)malloc(sizeof(num));
	memcpy(num2, num, sizeof(num));
	printf("selectsort\n");
	SelectSort(num2, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num2[n]);
		n++;
	}
	printf("\n");

	int* num3 = (int*)malloc(sizeof(num));
	memcpy(num3, num, sizeof(num));
	printf("selectsort2\n");
	SelectSort2(num3, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num3[n]);
		n++;
	}
	printf("\n");

	int* num4 = (int*)malloc(sizeof(num));
	memcpy(num4, num, sizeof(num));
	printf("heapsort\n");
	HeapSort(num4, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num4[n]);
		n++;
	}
	printf("\n");

	int* num5 = (int*)malloc(sizeof(num));
	memcpy(num5, num, sizeof(num));
	printf("bubblesort\n");
	BubbleSort(num5, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num5[n]);
		n++;
	}
	printf("\n");

	int* num6 = (int*)malloc(sizeof(num));
	memcpy(num6, num, sizeof(num));
	printf("quicksort\n");
	QuickSort(num6, 0, 10);
	n = 0;
	while (n < sz) {
		printf("%d ", num6[n]);
		n++;
	}
	printf("\n");

	int* num7 = (int*)malloc(sizeof(num));
	memcpy(num7, num, sizeof(num));
	printf("quickNonRsort\n");
	QuickSortNonR(num7, 0, 10);
	n = 0;
	while (n < sz) {
		printf("%d ", num7[n]);
		n++;
	}
	printf("\n");

	int* num8 = (int*)malloc(sizeof(num));
	memcpy(num8, num, sizeof(num));
	printf("insertsort\n");
	printf("quickNonRsort2\n");
	n = 0;
	while (n < sz) {
		printf("%d ", num7[n]);
		n++;
	}
	printf("\n");

	int* num9 = (int*)malloc(sizeof(num));
	memcpy(num9, num, sizeof(num));
	printf("mergesort\n");
	MergeSort(num9, n);
	n = 0;
	while (n < sz) {
		printf("%d ", num9[n]);
		n++;
	}
	printf("\n");

	int* num10 = (int*)malloc(sizeof(num));
	memcpy(num10, num, sizeof(num));
	printf("mergeNonRsort\n");
	MergeSortNonR(num10, n);
	n = 0;
	while (n < sz) {
		printf("%d ", num10[n]);
		n++;
	}
	printf("\n");

	int* num11 = (int*)malloc(sizeof(num));
	memcpy(num11, num, sizeof(num));
	printf("countsort\n");
	MergeSortNonR(num11, n);
	n = 0;
	while (n < sz) {
		printf("%d ", num11[n]);
		n++;
	}
	printf("\n");

	return 0;
}