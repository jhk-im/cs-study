#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	printf("%d %% %d = %d\n", a, b, a % b);

	printf("\"A\tB\tC\tD\"\n");
	printf("\"A\tB\tC\tD\"\n");
	printf("\"A\tB\tC\tD\"\n");

	int c, d;
	scanf("%d %d", &c, &d);
	printf("%d\n", c > d);

	int e, f, g;
	scanf("%d %d %d", &e, &f, &g);
	printf("%d\n", !e);
	printf("%d\n", e && f);
	printf("%d\n", (e > f) && (f > g));

	int h = 7;
	printf("%d\n", ++h);
	printf("%d\n", --h);
	printf("%d\n", h++);
	printf("%d\n", h--);

	int i = 7, j = 7;
	printf("%d\n", (i == j) ? 100 : -100);

	return 0;
}