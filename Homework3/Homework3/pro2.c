#include<stdio.h>

int main() {
	int n;
	printf("Decinal\t\tBinary\n");
	for (int i = 0; i <= 15; i++) {
		printf("%d\t\t", i);
		n = i;
		printf("%c", n < 16 && n >= 8 ? '1' : '0');
		n %= 8;
		printf("%c", n < 8 && n >= 4 ? '1' : '0');
		n %= 4;
		printf("%c", n < 4 && n >=2 ? '1' : '0');
		n %= 2;
		printf("%c\t", n==1 ? '1' : '0');
		printf("\n");
	}
	return 0;
}

