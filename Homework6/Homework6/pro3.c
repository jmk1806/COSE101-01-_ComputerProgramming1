#include<stdio.h>
#pragma warning(disable : 4996)

int compare(char *string1, char *string2) {
	int check = 0;
	for (int i = 0; i < 80; i++) {
		if (*(string1 + i) != *(string2 + i)) check = 1;
	}
	if (check == 0) return 0;
	else return 1;
}
int main() {
	char string1[80], string2[80];
	int check;
	printf("Enter two strings: ");
	scanf("%s %s", string1, string2);
	check=compare(string1, string2);
	if (check == 0) printf("%s and %s are equal.\n", string1, string2);
	else printf("%s and %s are not equal.\n",string1,string2);
}