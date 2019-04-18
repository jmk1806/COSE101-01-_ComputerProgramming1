#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)

typedef struct student {
	char name[80];
	int stdnum;
}Student;

int main() {
	char text[5][80];
	Student std[5];
	char *temp = NULL;

	for (int i = 1; i <= 5; i++) {
		printf("<%d> Enter studentname / student number: ");
		gets()
	}
}