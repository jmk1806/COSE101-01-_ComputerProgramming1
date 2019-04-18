#include<stdio.h>
#include<string.h>

void replace(char* original, char* target);

int main(void) {
	char original[300] = "I love programming, but I am not good at programming. I will practice hard to do programming well. I will attend class hard to be good at programming. I will study hard and get good score in midterm exam.";
	char target[15];
	printf("Type the string to remove : ");
	scanf_s("%s", target,15);
	replace(original, target);
	return 0;
}

void replace(char* original, char* target) {
	char *ptr = NULL;
	char *first = original;
	int cnt = 0;
	for (int i = 0; target[i]; i++) cnt++;
	ptr = strstr(original, target);
	if (ptr == NULL) {
		printf("\n\"%s\" is not in given string.\n", target);
		return;
	}
	printf("\nBefore replacement :\n");
	printf("%s\n\n", original);
	printf("-----------------------------------------------------------------------------\n");
	while (original) {
		ptr = strstr(original, target);
		if (ptr == NULL) break;
		else {
			printf("Replacing : \n");
			for (int i = 0; i < cnt; i++) {
				*(ptr + i) = ' ';
			}
			printf("%s\n\n", first);
			original = original + cnt;

		}
	}
	printf("-----------------------------------------------------------------------------\n");
	printf("After replacement : \n");
	printf("%s\n", first);
}	