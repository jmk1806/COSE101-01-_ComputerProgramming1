#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int a[10000], t;

void push(int n) {
	a[t++]=n;
}

void pop(void) {
	if (t == 0) {
		printf("-1\n");
	}
		
	else {
		printf("%d\n", a[--t]);
	}
		
}

void size(void) {
	printf("%d\n", t);
}

void empty(void) {
	if (t == 0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
		
}

void top(void) {
	if (t==0) {
		printf("-1\n");
	}
		
	else {
		printf("%d\n",a[t-1]);
	}
		
}

int main(void) {
	int n,m;
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
		else if (!strcmp(k, "top")) {
			top();
		}
		else {
			scanf("%d", &m);
			push(m);
		}
	}
	return 0;
}