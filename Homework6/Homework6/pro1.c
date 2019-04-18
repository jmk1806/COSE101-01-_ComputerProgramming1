#include<stdio.h>
#pragma warning(disable : 4996)

void point(int *a, int *b, int *c) {
	int temp = 0;
	(*a)++;
	(*b) *= (*c);
	temp = (*b);
	(*b) = (*c);
	(*c) = temp;

}
int main(void) {
	int a, b, c,temp;
	int *first=&a, *second=&b, *third=&c;
	printf("Enter three numbers: ");
	scanf("%d %d %d", &a,&b,&c);
	printf("Before: a = %d, b = %d, c = %d\n", a, b, c);
	point(&a, &b, &c);
	printf("After: a = %d, b = %d, c = %d\n", a, b, c);
}