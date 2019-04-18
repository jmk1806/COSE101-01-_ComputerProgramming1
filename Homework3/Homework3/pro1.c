#include<stdio.h>

int main(void){
	int max=0xFFFFFFFF,num,cnt=0;
	do{
		printf("Enter the number : ");
		scanf_s("%d", &num);
		if (max < num) max = num;
		cnt++;
	} while (cnt < 5);
		
	printf("Largest is %d\n", max);

	return 0;
}