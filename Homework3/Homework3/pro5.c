#include<stdio.h>

int main(void) {
	int num, quan;
	double price, sum = 0, cnt = 0;
	printf("Enter pairs of item numbers and quantities.\n");
	printf("Enter -1 for the item number to end input.\n");
	while (1) {
		scanf_s("%d", &num);
		if (num == -1) break;
		scanf_s("%d", &quan);
		
			switch (num) {
			case 1: price = 2.98;
				sum = sum + price * quan;
				break;
			case 2: price = 4.50;
				sum = sum + price * quan;
				break;
			case 3: price = 9.98;
				sum = sum + price * quan;
				break;
			
			case 4: price = 4.49;
				sum = sum + price * quan;
				break;
			case 5: price = 6.87;
				sum = sum + price * quan;
				break;
			default : printf("Invalid product code: %d\n", num);
					printf("            Quantity: %d\n", quan);
				break;
		}
	}
	printf("The total retail value was:   %.2f\n", sum);
	return 0;
}
