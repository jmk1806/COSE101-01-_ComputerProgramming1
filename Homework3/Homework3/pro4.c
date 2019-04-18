#include<stdio.h>

int main(void) {
	int n=4,k,i;
	while (n !=0) {
		k = 9 - n * 2;
		for (i = 1; i <= n; i++) {
			printf(" ");
		}
		for (i = 1; i <= k; i++) {
			printf("*");
		}
		for (i = 1; i <= n; i++) {
			printf(" ");
		}
		printf("\n");
		n--;
	}
	while (n <= 4) {
		k = 9 - n * 2;
		for (i = 1; i <= n; i++) {
			printf(" ");
		}
		for (i = 1; i <= k; i++) {
			printf("*");
		}
		for (i = 1; i <= n; i++) {
			printf(" ");
		}
		printf("\n");
		n++;
	}
	return 0;
}