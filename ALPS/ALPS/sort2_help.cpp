#include<stdio.h>
#pragma warning(disable : 4996)
int a[1000000];
int left[500000], right[500000];

void merge(int a[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	for (i = 0; i < n1; i++) left[i] = a[l + i];
	for (j = 0; j < n2; j++) right[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1&&j < n2) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		}
		else {
			a[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = right[j];
		j++;
		k++;
	}
}

void mergesort(int a[], int l, int r) {
	if (l < r) {
		int m = (l + (r - 1)) / 2; //same as (l+r)/2
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge(a, l, m, r);

	}
}



int main(void) {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergesort(a, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}