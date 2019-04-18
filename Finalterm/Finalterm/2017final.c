#include<stdio.h>
#pragma warning(disable : 4996)
int solve(int, int*);
int flipadd(int);
int ispalin(int);

int flipadd(int num) {
	int cnt = 0; // 자릿수 저장
	int sum = 0; // 최종 합 변수
	int before, after = 0; // 함수 전,후 값 저장
	int divide[30] = { 0, }; // 자릿수 분리
	int digit = 1; // 자릿수(1, 10, 100, ...)
	before = num; // 첫 초기화
	while (num != 0) {
		divide[cnt] = num % 10;
		num /= 10;
		cnt++;
	} // 자릿수 세기
	for (int i = cnt - 1; i >= 0; i--) {
		after += divide[i] * digit;
		digit *= 10;
	} // after에 뒤집은 수 저장
	sum = before + after; // 최종 합
	return sum;
}

int ispalin(int num) {
	if (num == flipadd(num) / 2)
		return 1; // 뒤집어서 같은 수면 1 반환
	else
		return 0; // 아니면 0 반환
}

int solve(int n, int* count) {
	int res = n; // 맨처음 값 초기화
	int i;// 반복문 변수
	for (i = 1; i < 1001; i++) {
		if (ispalin(res)) break; // 회문수이면 break
		else if (res < 0) continue; // 오버플로우 보정
		else {
			res = flipadd(res); // 회문수 될때까지 반복
			(*count)++; // 몇 번 반복되었는지 세기
		}
	}
	if (i == 1001) (*count) = i; // 1000번 반복해서 안됫을때 반환
	return res;
}

void main() {
	FILE* fp;
	int num;
	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &num); // 맨 처음 수 : 몇 개의 수 지정
	for (int i = 0; i < num; i++) {
		int n, res;
		int count;
		count = 0; // 초기화시켜야됨.
		fscanf(fp, "%d", &n); // 시작 수 불러오기
		res = solve(n, &count);
		printf("%d %d %d\n", n, count, res);
	}
	fclose(fp);
}