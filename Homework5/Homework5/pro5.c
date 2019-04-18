#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int result[4][3];
int m1[4][4];
int m2[4][3];
void multiplieArray(int m1[][4], int m2[][3]) {
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

int main(void) {
	int i, j;
	srand(time(NULL));
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			m1[i][j] = rand() % 10 + 1;
			m2[i][j] = rand() % 10 + 1;
		}
	}
	printf("matrix 1 :\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			m1[i][j] = rand() % 10 + 1;
			printf("%d\t", m1[i][j]);
		}
		printf("\n");
	}
	printf("\nmatrix 2 : \n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			m2[i][j] = rand() % 10 + 1;
			printf("%d\t", m2[i][j]);
		}
		printf("\n");
	}

	printf("\nresult matrix :\n\n");
	multiplieArray(m1, m2);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}