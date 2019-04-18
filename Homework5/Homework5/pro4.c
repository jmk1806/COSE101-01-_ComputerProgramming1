#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma  warning(disable : 4996)

int result[5][6];

void printArray(int matrix[][6]){
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			matrix[i][j] = rand() % 100 + 1;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void addArray(int matrix1[][6], int matrix2[][6]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

int main() {
	int m1[5][6] = { 0, };
	int m2[5][6] = { 0, };
	srand(time(NULL));
	printf("matrix1: \n");
	printArray(m1);
	printf("\nmatrix2: \n");
	printArray(m2);
	printf("\nresult: \n");
	addArray(m1, m2);
	printArray(result);
}