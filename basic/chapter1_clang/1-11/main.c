#include <stdio.h>

int a = 5;

void changeValue() {
	a = 10;
}

void process() {
	static int c = 5;
	c = c + 1;
	printf("%d\n", c);
}

void add(int e, int f) {
	e = e + f;
}

void add2(int *g) {
	*g = (*g) + 10;
}

int main(void) {
	printf("%d\n", a);
	changeValue();
	printf("%d\n", a);

	int b = 7;
	if (1) {
		int b = 5;
	}
	printf("%d\n", b);

	process();
	process();
	process();

	register int d = 10;
	for (int i = 0; i < d; i++) {
		printf("%d", i);
	}
	printf("\n");

	int e = 7;
	add(e, 10);
	printf("%d\n", e);

	int g = 7;
	add2(&g);
	printf("%d\n", g);

	return 0;
}