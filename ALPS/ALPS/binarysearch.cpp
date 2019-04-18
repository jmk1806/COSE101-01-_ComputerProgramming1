#include<stdio.h>
#include<algorithm>
#pragma warning(disable : 4996)

using namespace std;
int arr[100000] = { 0, };
int n;
int binary(int num) {
	int left=0, right=n-1, mid;
	while (right >= left) {
		mid = (left + right) / 2;
		if (num < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;

		if (num == arr[mid])
			return mid;
	}
	return -1;
}
int main(void) {
	int ret,m,i,k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &k);
		ret = binary(k);
		if (ret == -1) printf("0\n");
		else printf("1\n");
	}

	return 0;
}