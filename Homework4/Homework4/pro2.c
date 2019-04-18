#include<stdio.h>
#pragma warning(disable : 4996)

char ulcase(char a) {
	if (a >= 'A'&&a <= 'Z') return 1;
	else return 0;
}

int main(void) {
	char a;
	int n;
	printf("Enter the character: ");
	scanf("%c", &a);
	n=ulcase(a);
	(n == 1)?printf("%c: Uppercase\n", a): printf("%c: Lowercase\n", a);
	return 0;
}