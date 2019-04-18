#include<stdio.h>
#pragma warning(disable : 4996)

void addstring(char *s1, char *s2) {
	while (*s1) s1++;
	while (*s2) {
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

int main() {
	char string1[80], string2[80];
	int i = 0, j = 0;
	printf("Enter two strings: ");
	scanf("%s %s", string1, string2);
	addstring(string1, string2);
	printf("%s\n", string1);
	
}