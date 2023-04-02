#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main(void) {
	int a[10] = { 6,5,4,3,9,8,0,1,2,7 };
	for (int i = 0; i < 10; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
	int maxValue = INT_MIN;
	for (int i = 0; i < 10; i++) {
		if (maxValue < a[i]) maxValue = a[i];
	}
	printf("%d\n", maxValue);

	char c[20];
	scanf("%s", &c);
	printf("%s\n", c);

	char d[20] = "Hello World";
	d[5] = ',';
	printf("%s\n", d);

	int count = 0;
	for (int i = 0; i <= 10; i++) {
		if (d[i] == 'l') count++;
	}
	printf("%d\n", count);
	
    return 0;
}