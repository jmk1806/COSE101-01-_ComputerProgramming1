#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int dice100() {
	return rand() % 100 + 1;
}
int unique(int x, int output[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (x == output[i]) return 0;
	}
	return 1;
}
int main() {
	int i, j, p = 0;
	int output[30];
	for (i = 0; i < 30; i++) {
		int x = dice100();
		while (!unique(x, output, i))
			x = dice100();
		output[p++] = x;
	}
	for (i = 0; i < 30; i++) {
		printf("%d\n", output[i]);
	}
	return 0;
}