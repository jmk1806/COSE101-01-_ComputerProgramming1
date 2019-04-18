#include<stdio.h>
#pragma warning(disable : 4996)
int solve(int, int*);
int flipadd(int);
int ispalin(int);

int flipadd(int num) {
	int cnt = 0; // �ڸ��� ����
	int sum = 0; // ���� �� ����
	int before, after = 0; // �Լ� ��,�� �� ����
	int divide[30] = { 0, }; // �ڸ��� �и�
	int digit = 1; // �ڸ���(1, 10, 100, ...)
	before = num; // ù �ʱ�ȭ
	while (num != 0) {
		divide[cnt] = num % 10;
		num /= 10;
		cnt++;
	} // �ڸ��� ����
	for (int i = cnt - 1; i >= 0; i--) {
		after += divide[i] * digit;
		digit *= 10;
	} // after�� ������ �� ����
	sum = before + after; // ���� ��
	return sum;
}

int ispalin(int num) {
	if (num == flipadd(num) / 2)
		return 1; // ����� ���� ���� 1 ��ȯ
	else
		return 0; // �ƴϸ� 0 ��ȯ
}

int solve(int n, int* count) {
	int res = n; // ��ó�� �� �ʱ�ȭ
	int i;// �ݺ��� ����
	for (i = 1; i < 1001; i++) {
		if (ispalin(res)) break; // ȸ�����̸� break
		else if (res < 0) continue; // �����÷ο� ����
		else {
			res = flipadd(res); // ȸ���� �ɶ����� �ݺ�
			(*count)++; // �� �� �ݺ��Ǿ����� ����
		}
	}
	if (i == 1001) (*count) = i; // 1000�� �ݺ��ؼ� �ȵ����� ��ȯ
	return res;
}

void main() {
	FILE* fp;
	int num;
	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &num); // �� ó�� �� : �� ���� �� ����
	for (int i = 0; i < num; i++) {
		int n, res;
		int count;
		count = 0; // �ʱ�ȭ���Ѿߵ�.
		fscanf(fp, "%d", &n); // ���� �� �ҷ�����
		res = solve(n, &count);
		printf("%d %d %d\n", n, count, res);
	}
	fclose(fp);
}