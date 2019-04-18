#include<stdio.h>
#pragma warning(disable : 4996)

int main(void) {
	int Arr[1000] = {0,};
	int n,temp,i,j;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &Arr[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (Arr[i] > Arr[j]) {
				temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", Arr[i]);
	}
	return 0;
}