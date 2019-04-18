#include<stdio.h>

int sum_digit(char str[]) {
	int i;
	int sum = 0;
	for (i = 0; str[i]; i++) {
		if (str[i] >= '0'&&str[i] <= '9')
			sum += str[i] - '0';
	}
	return sum;
}

int main() {
	char str[1000];
	int sum;
	scanf_s("%s", str,1000);
	sum = sum_digit(str);
	printf("%d\n", sum);
}