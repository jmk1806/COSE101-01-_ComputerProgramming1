#include<stdio.h>
#pragma warning(disable : 4996)

int perfect(int n) {
	int i=1,sum=0;
	while (n > i) {
		if (n%i == 0) sum = sum + i;
		i++;
	}
	if (sum == n) return 1;
	else return 0;
}

int main(void) {
	printf("For the integers from 1 to 1000: \n");
	for (int i = 2; i <= 1000; i++) {
		if(perfect(i)==1) printf("%d is perfect\n",i);
	}
	
	return 0;
}