#include"sort_c.c"

int main() {
	int a[] = { 4,1,7,2,8,1,9,3,5,6 };
	int sz = sizeof(a) / sizeof(a[0]);

	int* a1 = (int*)malloc(sizeof(a));
	memcpy(a1, a, sizeof(a));
	InsertSort(a1, sz);
	int n = sz;
	while (n) {
		printf("%d ", a1[10 - n]);
		n--;
	}
	printf("\n");

	int* a2 = (int*)malloc(sizeof(a));
	memcpy(a2, a, sizeof(a));
	InsertSort(a2, sz);
	n = sz;
	while (n) {
		printf("%d ", a2[10 - n]);
		n--;
	}
	printf("\n");

	int* a3 = (int*)malloc(sizeof(a));
	memcpy(a3, a, sizeof(a));
	SelectSort(a3, sz);
	n = sz;
	while (n) {
		printf("%d ", a3[10 - n]);
		n--;
	}
	printf("\n");

	int* a4 = (int*)malloc(sizeof(a));
	memcpy(a4, a, sizeof(a));
	SelectSortmax(a4, sz);
	n = sz;
	while (n) {
		printf("%d ", a4[10 - n]);
		n--;
	}
	printf("\n");

	int* a5 = (int*)malloc(sizeof(a));
	memcpy(a5, a, sizeof(a));
	HeapSort(a5, sz);
	n = sz - 1;
	while (n >= 0) {
		printf("%d ", a5[n]);
		n--;
	}
	printf("\n");

	int* a6 = (int*)malloc(sizeof(a));
	memcpy(a6, a, sizeof(a));
	BubbleSort(a6, sz);
	n = sz - 1;
	while (n >= 0) {
		printf("%d ", a6[n]);
		n--;
	}
	printf("\n");

	int* a7 = (int*)malloc(sizeof(a));
	memcpy(a7, a, sizeof(a));
	QuickSort(a7, 0, sz - 1);
	n = sz - 1;
	while (n >= 0) {
		printf("%d ", a7[n]);
		n--;
	}
	printf("\n");

	return 0;
}