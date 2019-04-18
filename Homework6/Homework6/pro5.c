#include<stdio.h>
#pragma warning(disable : 4996)
int add(int n1, int n2) {
	return n1 + n2;
}

int sub(int n1, int n2) {
	return n1 - n2;
}

int mul(int n1, int n2) {
	return n1 * n2;
}

int main(void) {
	int(*func[3])(int a, int b) = { add, sub, mul };
	int operation, n1, n2, result;
	char sign;
	do {
		printf("0. Addition\n");
		printf("1. Subtraction\n");
		printf("2. Multiplication\n");
		printf("3. End\n");
		printf("select the operation: ");
		scanf("%d", &operation);
		if (operation < 0 || operation>3) {
			printf("\n\n\n");
			continue;
		}
		if (operation == 3) {
			printf("Exit\n");
			return 0;
		}
		else {
			switch (operation) {
			case 0: sign = '+';
				break;
			case 1: sign = '-';
				break;
			case 2: sign = '*';
				break;
			}
			printf("Enter the two numbers: ");
			scanf("%d %d", &n1, &n2);
			result = (*func[operation])(n1, n2);
			printf("\n\t%d %c %d = %d\n\n", n1, sign, n2, result);
		}
	} while (1);


}