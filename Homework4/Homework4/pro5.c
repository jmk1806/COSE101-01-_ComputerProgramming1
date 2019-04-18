#include<stdio.h>
#pragma warning(disable : 4996)

void reverse(int n) {
	printf("%d", n % 10);

	if (n / 10 > 0) reverse(n / 10);
}

int main(void) {
	unsigned int n;
	printf("Enter a number 1 and 999999999: ");
	scanf("%d", &n);
	printf("The number with its digits reversed is: ");
	reverse(n);
	printf("\n");
	return 0;
}
