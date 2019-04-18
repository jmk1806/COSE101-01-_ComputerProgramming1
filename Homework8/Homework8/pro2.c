#include<stdio.h>
#include<math.h>

int main() {
	int a, b;
	printf("Enter two integers: ");
	scanf_s("%d %d", &a, &b);
	printf("number:\n");
	printf("     %d = ", a);
	int num = pow(2, 16);
	for (int i = 0; i < 16; i++) {
		if (a%num == 0) printf("0");
		else printf("1");
		num /= 2;
	}
}