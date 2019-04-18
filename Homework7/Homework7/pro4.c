#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
int main(void) {
	char array[10][50] ={ "Westborough","Wellesley","Natick","Waltham","Framingham","Marlborough","Boston","Ashland","Hopkington","Shrewsbury"};
	char temp[50];
	printf("Given strings : \n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", array[i]);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10 - i; j++) {
			if (strcmp(array[j], array[j + 1]) > 0) {
				strcpy(temp, array[j]);
				strcpy(array[j], array[j + 1]);
				strcpy(array[j + 1], temp);
			}
		}
	}
	printf("\nThe strings in sorted order are :\n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", array[i]);
	}
	return 0;
}