#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
int main(void) {
	char text[3][80]= { "The regret after not doing something is bigger than that of doing something.", "Have fun this time because it will never come again.", "If you don't walk today you will have to run tomorrow." };
	int cnt[81] = { 0, };
	int n = 0;
	char *ptr = NULL;

	printf("Given string : \n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", text[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		ptr = strtok(text[i], " .");
		while (ptr != NULL) {
			n = strlen(ptr);
			cnt[n]++;
			ptr = strtok(NULL, " .");
		}
	}
	for (int i = 0; i < 81; i++) {
		if (cnt[i] == 0) continue;
		else {
			printf("%d words of length %d\n", cnt[i], i);
		}
	}
	return 0;
}