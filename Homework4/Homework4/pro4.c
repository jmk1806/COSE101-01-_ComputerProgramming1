#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable : 4996)

int flip(void) {
	int n;
	n = rand() % 2;
	return n;

}

int main(void) {
	srand(time(NULL));
	int n, h = 0, t = 0;
	for (int i = 1; i <= 100; i++) {
		n = flip();
		
		if (n == 1) {
			printf("Heads ");
			h++;
		}
		else {
			printf("Tails ");
			t++;
		}
		if (i % 10 == 0) printf("\n");
	}
	printf("\nThe total number of Heads was %d\n", h);
	printf("The total number of Tails was %d\n", t);
	return 0;
}