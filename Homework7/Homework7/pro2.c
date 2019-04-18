#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void) {
	char text[3][80] = { "The regret after not doing something is bigger than that of doing something.", "Have fun this time, because it will never come again.", "If you don't walk today, you will have to run tomorrow." };
	int cnt[26] = { 0, };
	char *ptr = NULL;
	printf("Given string:\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", text[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; text[i][j]; j++) {
			text[i][j] = tolower(text[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 26;j++) {
			for (ptr = text[i];;) {
				ptr = strchr(ptr, 'a' + j);
				if (ptr == NULL) break;
				cnt[j]++;
				ptr++;
			}
		}
	}
	printf("\nThe total occurrences of each character:\n");
	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", 'a' + i, cnt[i]);
	}
	return 0;
}