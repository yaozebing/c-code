#include"БъЭЗ.h"

int main() {
	int num[] = { 4,6,1,8,4,9,0,2,1,7,3 };
	int sz = sizeof(num) / sizeof(num[0]);

	int* num0 = (int*)malloc(sizeof(num));
	memcpy(num0, num, sizeof(num));
	InsertSort(num0, sz);
	int n = 0;
	while (n < sz) {
		printf("%d ", num0[n]);
		n++;
	}
	printf("\n");

	int* num1 = (int*)malloc(sizeof(num));
	memcpy(num1, num, sizeof(num));
	ShellSort(num1, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num1[n]);
		n++;
	}
	printf("\n");
	
	int* num2 = (int*)malloc(sizeof(num));
	memcpy(num2, num, sizeof(num));
	SelectSort(num2, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num2[n]);
		n++;
	}
	printf("\n");

	int* num3 = (int*)malloc(sizeof(num));
	memcpy(num3, num, sizeof(num));
	SelectSort2(num3, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num3[n]);
		n++;
	}
	printf("\n");

	int* num4 = (int*)malloc(sizeof(num));
	memcpy(num4, num, sizeof(num));
	HeapSort(num4, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num4[n]);
		n++;
	}
	printf("\n");

	int* num5 = (int*)malloc(sizeof(num));
	memcpy(num5, num, sizeof(num));
	BubbleSort(num5, sz);
	n = 0;
	while (n < sz) {
		printf("%d ", num5[n]);
		n++;
	}
	printf("\n");

	return 0;
}