#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int t, a[50], fi=1;
char vps[50];

void push(int n) {
	a[t++] = n;
}

void pop(void) {
	if (t > 0)
		a[--t] = 0;
	else
		fi = 0;
	
}


int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		t = 0;
		scanf("%s", vps);
		for (int j = 0; vps[j]; j++) {
			if (vps[j] == '(')
				push(1);
			else
				pop();
		}
		if (t == 0 && fi==1)
			printf("YES\n");
		else
			printf("NO\n");

		fi = 1;
	}
	return 0;
}