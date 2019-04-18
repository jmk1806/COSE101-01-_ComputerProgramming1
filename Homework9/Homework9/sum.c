#include<stdio.h>
#pragma warning(disable : 4996)

int main(){
	int num;
	int sum = 0;
	char factor[100] = { 0, };
	scanf("%d", &num);
	scanf("%s", factor);
	for (int i = 0; i < num; i++) {
		sum += (factor[i]-'1'+1);
	}
	printf("%d", sum);
}