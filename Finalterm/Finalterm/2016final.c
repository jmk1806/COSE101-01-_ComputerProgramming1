#include<stdio.h>
void fun1(void);
void fun2(void);
void fun3(void);
int x = 2;
int main(void) {
	int x = 3;
	printf("%d, ", x);
	{
		int x = 5;
		printf("%d, ", x);
	}
	printf("%d, ", x);
	fun1();fun2();fun3();
	fun1();fun2();fun3();
	printf("%d\n", x);

	return 0;
}

void fun1() {
	int x = 7;
	printf("%d, ", x);
	x++;
	printf("%d, ", x);
}

void fun2() {
	static int x = 11;
	printf("%d, ", x);
	x++;
	printf("%d, ", x);
}

void fun3() {
	printf("%d, ", x);
	x += 13;
	printf("%d, ", x);
}