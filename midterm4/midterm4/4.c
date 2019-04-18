#include <stdio.h>
#pragma warning(disable : 4996)
int is_pair_isogram(char str[]) {
	int count[26];
	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}
	for (int i = 0; str[i]; i++) {
		count[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] != 2 && count[i] != 0)
			return 0;
	}
	return 1;
}
void main()
{
	char str[100];
	printf("Enter word: ");
	scanf("%s", str);
	if (is_pair_isogram(str))
		printf("%s is a pair isogram\n", str);
	else
		printf("%s is NOT a pair isogram\n", str);
}