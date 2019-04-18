#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable : 4996)

int main(){
	int arr[10];
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) arr[i] = rand() % 100 + 1;
	for (i = 0; i < 10; i++) printf("%d ", *(arr + i));
	printf("\n");
	while (--i >=0) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	return 0;
}