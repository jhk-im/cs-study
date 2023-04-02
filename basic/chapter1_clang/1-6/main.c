#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dice(int input) {
	printf("던진 주사위: %d\n", input);
}

int add(int a, int b) {
	return a + b;
}

void calculator(int c, int d) {
	printf("%d + %d = %d\n", c, d, c + d);
	printf("%d - %d = %d\n", c, d, c - d);
	printf("%d * %d = %d\n", c, d, c * d);
	printf("%d / %d = %d\n", c, d, c / d);
}

int factorial(int e) {
	if (e == 1) return 1;
	else return e * factorial(e - 1);
}

int main(void) {
	dice(3);
	dice(5);
	dice(1);

	printf("%d\n", add(10, 20));

	calculator(10, 3);
	
	int n;
	printf("n 팩토리얼을 계산합니다.");
	scanf("%d", &n);
	printf("%d\n", factorial(n));
}