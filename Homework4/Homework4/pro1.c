#include<stdio.h>
#include<math.h>
#pragma warning(disable : 4996)

void hypotenuse(double a, double b) {
	double n;
	n = sqrt(pow(a, 2) + pow(b, 2));
	printf("Hypotenuse : %.1f\n\n", n);
}

int main(void) {
	double a, b;
	for (int i = 1; i <= 3; i++) {
		printf("Enter the sides of the triangle: ");
		scanf("%lf %lf", &a, &b);
		hypotenuse(a, b);
	}
	return 0;
}