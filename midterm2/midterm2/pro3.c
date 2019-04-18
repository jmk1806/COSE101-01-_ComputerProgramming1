#include<stdio.h>
#pragma warning(disable : 4996)

int main() {
	char str[1000];
	int i, score = 0;
	printf("Enter string (w/o space): ");
	scanf("%s", str);
	for (i = 0; str[i]; i++) {
		int ch = str[i];
		if (ch >= 'A'&&ch <= 'Z') {
			score += (ch-'A'+1);
		}
		else if (ch >= 'a'&&ch <= 'z') {
			score += (ch - 'a' + 1);
		}
	}
	printf("%d\n", score);
	return 0;
}