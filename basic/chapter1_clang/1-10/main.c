#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char *a = "Hello World";
	printf("%s\n", a);
	printf("%c\n", a[0]);
	printf("%c\n", a[1]);
	printf("%c\n", a[2]);

	char b[100];
	//gets(b);
	//printf("%s\n", b);

	char c[100];
	//gets_s(c, sizeof(c));
	//printf("%s\n", c);

	char d[20] = "JeongHoon Kim";
	char e[20] = "C Language";
	char f[20] = "";
	char g[20] = "Language";
	//printf("문자열의 길이: %d\n", strlen(d));
	//printf("문자열의 길이: %d\n", strlen(e));
	printf("두 배열의 사전 순 비교: %d\n", strcmp(d, e));
	strcpy(f, d);
	printf("복사된 문자열: %s\n", f);
	//strcat(f, e);
	//printf("합쳐진 문자열: %s\n", f);
	//printf("찾은 문자열: %s\n", strstr(e, g));

	return 0;
}