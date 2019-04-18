#include<stdio.h>
#pragma warning(disable : 4996)

int main() {
	int a, b, c, count = 0;
	for (a = 1; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			for (c = 0; c < 10; c++) {
				int num = a * 100 + b * 10 + c;
				int n3 = a*a*a +b*b*b + c*c*c;
				if (num == n3) {
					count++;
					printf("%d: %d\n", count, num);
				}
			}
		}

	}
	printf("Total %d numbers are found\n", count);
	return 0;
}