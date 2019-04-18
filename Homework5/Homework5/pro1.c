#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable : 4996)

int main(void) {
	int num[20] = { 0, }, check;
	int i,j;
	printf("Nonrepetitive array values are: \n");
	srand(time(NULL));
	for (i = 0; i < 20; i++) {
		while (1) {
			num[i] = rand() % 20 + 1;
			check = 0;
			for (j = 0; j < i; j++) {
				if (num[j] == num[i]) {
					check = 1;
					break;
				}
			}
			if (check != 1) break;
		}
		}
	for (i = 0; i < 20; i++) printf("Array[ %d ] = %d\n", i, num[i]);
	}
	
	
