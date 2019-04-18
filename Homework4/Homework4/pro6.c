#include<stdio.h>
#pragma warning(disable : 4996)

void tower(int c, int start, int end, int temp) {
	if (c == 1)
		printf("%d --> %d\n", start, end);
	else {
		tower(c - 1, start, temp, end);
		printf("%d --> %d\n", start, end);
		tower(c - 1, temp, end, start);
	}
}

int main(void) {
	int n;
	printf("Enter the starting number of disks: ");
	scanf("%d", &n);
	tower(n, 1,3,2);
	return 0;
}