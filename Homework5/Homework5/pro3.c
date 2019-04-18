#include<stdio.h>
#pragma warning(disable : 4996)

void stringReverse(char strArray[]) {
	if (*strArray == 0) return;
	else {
		stringReverse(strArray + 1);
		printf("%c", *strArray);
	}
}

int main(void) {
	char strArray[30] = "Print this string backward.";
	printf("%s\n", strArray);
	stringReverse(strArray);
	printf("\n");
	return 0;
}