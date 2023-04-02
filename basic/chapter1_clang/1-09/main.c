#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char a = 65;
	printf("%c\n", a);

	char b = getchar();
	printf("%c\n", b);

	int c;
	char d;
	scanf("%d", &c);
	printf("%d\n", c);
	int temp;
	// 한자 씩 받아서 파일의 끝이거나 개행 문자를 만나면 입력을 멈추어 입력버퍼를 비운다. 
	while ((temp = getchar()) != EOF && temp!= '\n') {}
	scanf("%c", &d);
	printf("%c\n", d);
}