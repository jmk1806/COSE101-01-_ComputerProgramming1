#include<stdio.h>
#pragma warning(disable : 4996)

int is_palin(int num) {
	int temp = num;
	int rev = temp % 10;
	while ((temp /= 10) > 0) {
		rev *= 10;
		rev += temp % 10;
	}
	return rev == num;
}

int main() {
	int num;
	printf("Enter number: ");
	scanf("%d", &num);
	if (is_palin(num))
		printf("%d is a palindrome\n", num);
	else
		printf("%d is NOT a palindrome\n", num);
}