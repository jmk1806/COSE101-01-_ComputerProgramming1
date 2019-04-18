#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)


int main() {
	FILE *fp;
	fp = fopen("student_file.txt", "w");

	char name[10];
	int num, grade;
	char major[100];
	char find[10];
	char buffer[80];
	int line = 0;
	for (int i = 0; i < 5; i++) {
		printf("Name Student_number Grade Major: ");
		fscanf(stdin, "%s %d %d %s", name, &num, &grade, major);
		fprintf(fp, "%s %d %d %s\n", name, num, grade, major);
		rewind(stdin);
	}
	fclose(fp);

	fp = fopen("student_file.txt", "r");
	printf("Insert the student number to find: ");
	gets_s(find, 10);
	while (!feof(fp)) {
		line++;
		fgets(buffer, 80, fp);
		if (strstr(buffer, find) != NULL) {
			sscanf(buffer, "%s %d %d %s", name, &num, &grade, major);
			fprintf(stdout, "The major of student with ID %d is %s\n", num, major);
			break;
		} 
	}
	
	fclose(fp);
}