#include<stdio.h>

int main(void) {
	int a=0x7FFFFFFF, n=0x7FFFFFFF;
	int fi = 1;

	
	while (1){
		printf("Enter the base number: ");
		scanf_s("%d", &a);
		if (a > 0) break;
	}
	
	while (1) {
		printf("Enter the exponent number : ");
		scanf_s("%d", &n);
		if (n >= 0) break;
	}
	
	
	if (n == 0) printf("%d^%d is %d\n", a, n, 1);

	else{
		for (int i = 1; i <= n; i++) {
			fi = fi * a;
		}
		printf("%d^%d is %d\n", a, n, fi);
	}
	return 0;
}