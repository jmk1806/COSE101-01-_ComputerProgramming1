#include<stdio.h>
#pragma warning(disable : 4996)

void replace(char* original, char* target);

int main(void) {
	char original[300] = "I love programming, but I am not good at programming. I will practice hard to do programming well. I will attend class hard to be good at programming. I will study hard and get good score in midterm exam.";
	char target[15];
	printf("Type the string to remove : ");
	scanf("%s", target);
	printf("\nBefore replace :\n");
	printf("%s\n\n", original);
	printf("After replace : \n");
	replace(original, target);
	printf("%s\n\n", original);
}

void replace(char* original, char* target) {
	char *i, *j, *k;
	int check = 0, cnt = 0;

	for (i = target; *i; i++) cnt++;

	for (i = original; *i; i++) {
		check = 1;
		for (j = i, k = target; *j&&*k; j++, k++) {
			if (*j == *k || *j == *k - 32 || *j == *k + 32) {
				check = 1;
			}
			else {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			for (j = i; j < i + cnt; j++) {
				*j = ' ';
			}
		}
	}
}