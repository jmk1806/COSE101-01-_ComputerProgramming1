#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

int main() {
	char buffer[100];
	char filename[80];
	FILE *fp1, *fp2;

	printf("Enter the name of file to read : ");
	gets_s(filename, 80);

	fp1 = fopen(filename, "r");

	if (fp1 == NULL) 
		printf("File%s read error! \n", filename);

	printf("Enter the name of file to write : ");
	gets_s(filename, 80);

	fp2 = fopen(filename, "w");
	
	if (fp2 == NULL)
		printf("File%s read error! \n", filename);

	while (!feof(fp1)) {
		fgets(buffer, sizeof(buffer), fp1);
		if (*buffer == '\n') continue;
		else fputs(buffer, fp2);
	}
	printf("Copy txt complete!\n");
	fclose(fp1);
	fclose(fp2);
}