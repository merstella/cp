#include <stdio.h>
#include <math.h>
int a[10000];

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void quicksort(int a[], int low, int high) {
	if (low < high) {
		int index = partition(a, low, high);
		quicksort(a, low, index - 1);
		quicksort(a, index + 1, high);
	}
}
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
		if (a[j] < pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return i + 1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n; ++i) {
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
}