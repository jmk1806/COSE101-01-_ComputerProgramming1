#include<stdio.h>

int main(void) {
	double pi = 0.0, num = 4.0, denom = 1.0;
	long int loop, accuracy = 900000;

	printf("Accuracy set at %d \n", accuracy);
	printf("term \t\t pi \n");

	for (loop = 1; loop <= accuracy; loop=loop++) {
		if(loop%2==1) pi = pi+ num * (1 / denom);
		else pi = pi - num * (1 / denom);
		denom = denom + 2.0;
		if (loop % 50000 == 0)
			printf("%d\t\t%.6f\n", loop, pi);
	}

	return 0;
}