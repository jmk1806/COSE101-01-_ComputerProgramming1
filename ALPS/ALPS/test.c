#include <stdio.h>
int main(void)
{
	int grade = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	printf("Enter pairs of item numbers and quantities.\n");
	printf("Enter -1 for the item number to end input.\n");
	while (1) {
		scanf_s("%d", &grade);
		if (grade == -1) break;
		switch (grade) {
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		case 3:
			count3++;
			break;
		case 4:
			count4++;
			break;
		case 5:
			count5++;
			break;
		default:
			printf("Invalid product code:%d\n", grade);
			printf("Quantity:1\n");

		}
	}

	printf("The total retail value was:%.2f\n", 2.98*count1 + 4.50*count2 + 9.98*count3 + 4.49*count4 + 6.87*count5);
	return 0;
}