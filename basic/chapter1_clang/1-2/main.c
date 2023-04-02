#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);
	printf("입력한 숫자는 %d입니다.\n", a);

	int b, c;
	scanf("%d %d", &b, &c);
	printf("%d %d\n", c, b);

	double d;
	scanf("%lf", &d);
	printf("%.2f\n", d);

	int e, f, g;
	scanf("%1d%1d%1d", &e, &f, &g);
	printf("%d %d %d\n", e, f, g);

	return 0;
}