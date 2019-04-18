#include <stdio.h>
#pragma warning(disable : 4996)

int is_prime(int num) {
	if (num <= 1) return 1;
	for (int i = 2; i*i <= num; i++) {
		if (!(num%i)) return 1;
	}
	return 0;
} // 소수면 0,아니면 1 리턴

int closest_prime(int n) {
	if (!is_prime(n))
		return 0;
	else {
		if (n <= 1) return 2-n;
		int next_prime, prev_prime;
		for (int i = 2; i < n; i++) {
			if (!is_prime(i)) prev_prime = i;
		}
		for (int i = n;; i++) {
			if ((!is_prime(i))) {
				next_prime = i;
				break;
			}
		}
		if ((n - prev_prime) > (next_prime - n))
			return next_prime - n;
		else
			return n - prev_prime;
	}
}

void main(void){
	int n = 37;
	int p;
	printf("Enter number: ");
	scanf("%d", &n);
	p = closest_prime(n);
	if (p == 0)
		printf("Would you believe it; %d is a prime!\n", n);
	else
		printf("%d is not prime; you missed it by that much (%d)!\n\n", n, p);
}