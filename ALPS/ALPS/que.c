#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int a[10000], f, b;

void push(int n) {
	a[b++] = n;
}

void pop() {
	if (f == b)
		printf("-1\n");
	else

		printf("%d\n", a[f++]);
}

void size() {
	printf("%d\n", b - f);
}

void empty() {
	if (f == b) 
		printf("1\n");
	else
		printf("0\n");
	
}

void front() {
	if (f == b)
		printf("-1\n");
	else
		printf("%d\n", a[f]);
}

void back() {
	if (f == b)
		printf("-1\n");
	else
		printf("%d\n", a[b - 1]);
}

int main(void) {
	int n, m;
	char k[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", k);

		if (!strcmp(k, "pop")) {
			pop();
		}
		else if (!strcmp(k, "size")) {
			size();
		}
		else if (!strcmp(k, "empty")) {
			empty();
		}
		else if (!strcmp(k, "front")) {
			front();
		}
		else if (!strcmp(k, "back")) {
			back();
		}
		else {
			scanf("%d", &m);
			push(m);
		}
	}
	return 0;
}