#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char str[6];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		printf("Enter an integer string: ");
		scanf_s("%s", str, 6);
		sum += atoi(str);
		rewind(stdin);
	}
	printf("\n");
	printf("The total of the values is %d\n", sum);
	return 0;
}