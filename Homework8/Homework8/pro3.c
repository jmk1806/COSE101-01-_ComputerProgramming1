#include<stdio.h>

void displayBits(unsigned value);
void reversBits(unsigned value);

int main() {
	int num;
	printf("Enteran unsinged integer: ");
	scanf_s("%d", &num);
	printf("\nBefore bits are reversed:\n");
	displayBits(num);
	printf("\nAfterbits are reversed:\n");
	num = reversBits(num);
	displayBits(num);
}

void displayBits(unsigned value) {
	unsigned c;
	unsigned displayMask = 1 << 31;
	printf("%10u = ", value);
	for (c = 1; c <= 16; c++) {
		putchar(value&displayMask ? '1' : '0');
		value <<= 1;

		if (c % 8 == 0) {
			putchar(' ');
		}
	}
	putchar('\n');
}

void reversBits(unsigned value) {
	unsigned mask = 1;
	unsigned temp = 0;
	int i;

	for (i = 0; i <= 15; i++) {
		temp <<= 1;
		temp != (value&mask);
	}
}