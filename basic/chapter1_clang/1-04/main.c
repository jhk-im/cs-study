#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	printf("학점을 입력하세요.");
	char count;
	scanf("%c", &count);
	switch (count) {
	case 'A':
		printf("A 학점입니다.\n");
		break;
	case 'B':
		printf("B 학점입니다.\n");
		break;
	case 'C':
		printf("C 학점입니다.\n");
		break;
	default:
		printf("학점을 바르게 입력하세요.\n");
	}

	printf("월을 입력하세요.");
	int month;
	scanf("%d", &month);
	switch (month) {
	case 12:
	case 1: 
	case 2:
		printf("겨울입니다.\n");
		break;
	case 3: 
	case 4: 
	case 5:
		printf("봄입니다.\n");
		break;
	case 6: 
	case 7: 
	case 8:
		printf("여름입니다.\n");
		break;
	case 9: 
	case 10: 
	case 11:
		printf("가을입니다.\n");
		break;
	}

	printf("손님이 몇 명 왔나요?");
	int a;
	scanf("%d", &a);
	if (a == 1 || a == 2) {
		printf("2인석으로 안내합니다.\n");
	}
	else if (a == 3 || a == 4) {
		printf("4인석으로 안내합니다.\n");
	}
	else {
		printf("단체석으로 안내합니다.\n");
	}

	printf("메인 메모리 크기를 입력하세요. (GB)");
	int size;
	scanf("%d", &size);
	if (size >= 16) {
		printf("메인 메모리 크기가 충분합니다.\n");
	}
	else {
		printf("메인 메모리를 증설하세요.\n");
	}
    
	return 0;
}