#include<stdio.h>
#pragma warning(disable : 4996)

int main() {
	int num;
	int n1, n2;
	FILE *fp1, *fp2, *fp3;

	fp1 = fopen("input1.txt", "r");

	printf("input1 matrix:\n");
	for (int i = 0; i < 6; i++) {
		fscanf(fp1, "%d", &num);
		if (i == 2) fprintf(stdout, "%d\n", num);
		else if (i == 5) fprintf(stdout, "%d\n", num);
		else fprintf(stdout, "%d\t", num);
	}
	
	fclose(fp1);

	fp2 = fopen("input2.txt", "r");

	printf("\ninput2 matrix:\n");
	for (int i = 0; i < 6; i++) {
		fscanf(fp1, "%d", &num);
		if (i == 2) fprintf(stdout, "%d\n", num);
		else if (i == 5) fprintf(stdout, "%d\n", num);
		else fprintf(stdout, "%d\t", num);
	}

	fclose(fp2);

	fp1 = fopen("input1.txt", "r");
	fp2 = fopen("input2.txt", "r");
	fp3 = fopen("result.txt", "w");

	printf("\nresult matrix:\n");
	for (int i = 0; i < 6; i++) {
		fscanf(fp1, "%d", &n1);
		fscanf(fp2, "%d", &n2);
		if (i == 2) {
			fprintf(fp3, "%d\n", n1 + n2);
			fprintf(stdout, "%d\n", n1 + n2);
		}
		else if (i == 5) {
			fprintf(fp3, "%d", n1 + n2);
			fprintf(stdout, "%d", n1 + n2);
		}
		else {
			fprintf(fp3, "%d\t", n1 + n2);
			fprintf(stdout, "%d\t", n1 + n2);
		}
	}
	printf("\n\n");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}