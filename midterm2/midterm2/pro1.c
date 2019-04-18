#include<stdio.h>
#pragma warning(disable : 4996)

void fun1(void);
void fun2(void);
void fun3(void);
int x = 1;
int main(void) {
	int x = 5;
	printf("%d, ", x);
	{
		int x = 7;
		printf("%d, ", x);
	}
	printf("%d, ", x);
	fun1(); fun2(); fun3();
	fun1(); fun2(); fun3();
	printf("%d\n", x);
	return 0;
}

void fun1(void) {
	int x = 25;
	printf("%d, ", x);
	x++;
	printf("%d, ", x);
}
void fun2(void) {
	static int x = 50;
	printf("%d, ", x);
	x++;
	printf("%d, ", x);
}
void fun3(void) {
	printf("%d, ", x);
	x *= 10;
	printf("%d, ", x);
}