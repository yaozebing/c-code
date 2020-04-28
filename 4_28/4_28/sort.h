void swap(int* num1, int* num2);
void shiftdown(int* a, int sz, int parent) {
	int child = 2 * parent + 1;
	while (child < sz) {
		if (a[child + 1] < a[child] && child + 1 < sz) {
			child++;
		}
		if (a[parent] > a[child]) {
			swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else {
			break;
		}
	}
}
