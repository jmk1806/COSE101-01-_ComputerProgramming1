#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)

int main() {
	FILE *fp;
	int countall = 0, countpart = 0;
	char filename[80];
	char word[50];
	char buffer[80];
	char* str=NULL;
	printf("Enter the file name and word : ");
	scanf("%s %s", filename, word);

	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("File Error!\n");
		return 0;
	}
	
	while (!feof(fp)) {
		fgets(buffer, sizeof(buffer), fp);
		str = buffer;
		for (int i = 0; str[i]; i++) {
			if (str[i] == ' ' || str[i] == '\n') countall++;
		}
		if (strstr(buffer, word) != NULL)
			countpart++;
	}

	printf("The finding ratio : %d/%d\n", countpart, countall + 1);

	fclose(fp);
}