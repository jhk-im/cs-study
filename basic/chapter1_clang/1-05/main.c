#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	for (int i = 0; i <= 100; i++) {
		printf("%d\n", i);
	}
	int n, sum = 0;

	scanf("%d", &n);
	for (int j = 1; j <= n; j++) {
		sum = sum + j;
	}
	printf("%d\n", sum);

	int minus = 0;
	for (; 1;) {
		int x;
		scanf("%d", &x);
		if (x == -1) break;
		sum += x;
	}
	printf("%d\n", minus);

	int b;
	char c;
	scanf("%d %c", &b, &c);
	while (b--) {
		printf("%c", c);
	}

	int ii = 1;
	while (ii <= 9) {
		int j = 1;
		while (j <= 9) {
			printf("%d * %d = %d\n", ii, j, ii * j);
			j++;
		}
		printf("\n");
		ii++;
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}