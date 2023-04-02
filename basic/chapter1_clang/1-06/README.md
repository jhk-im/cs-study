# 함수

```txt
1) 함수의 개념을 이해하고 사용법을 숙지한다.
2) 함수의 정의와 호출 방법을 알아본다.
3) 재귀함수에 대해 알아본다. 
```

---

## 함수의 정의

* 입력을 받아 처리한 뒤에 출력하는 구조를 가진다.
`입력` -> `함수` -> `출력`
* 특정한 기능에 대한 소스코드가 반복되는 것을 줄여준다.

```c
반환자료형 함수명 (매개변수) {
 // 수행
 return 반환값;
}
```

example1

```c
#include <stdio.h>

void dice(int input) {
 printf("던진 주사위: %d\n", input);
}

int main(void) {
 dice(3);
 dice(5);
 dice(1);
 system("pause");
}
```

example2 : 더하기 함수

```c
int add(int a, int b) {
 return a + b;
}

int main(void) {
 printf("%d\n", add(10, 20));
 system("pause");
}
```

example3: 사칙연산 함수

```c
void calculator(int c, int d) {
 printf("%d + %d = %d\n", c, d, c + d);
 printf("%d - %d = %d\n", c, d, c - d);
 printf("%d * %d = %d\n", c, d, c * d);
 printf("%d / %d = %d\n", c, d, c / d);
}

int main(void) {
 calculator(10, 3);
 system("pause");
}
```

---

### 재귀함수

* 자기 자신을 포함하는 함수
* 기본적으로 자기 자신을 계속 호출한다.
* 반드시 재귀종료 조건이 필요하다.

```c
for (초기화; 조건; 반복 끝 명령어) {
 // 조건이 참인경우 무한루프 발생 
}
```

example

```c
int factorial(int e) {
 if (e == 1) return 1;
 else return e * factorial(e - 1);
}

int main(void) {
 int n;
 printf("n 팩토리얼을 계산합니다.");
 scanf("%d", &n);
 printf("%d\n", factorial(n));
 system("pause");
}
```

### 배운내용 정리

1) C언어는 함수로 시작해서 함수로 끝나는 언어이다.
2) 재귀함수는 반복적으로 자기 자신을 불러내므로 경우에 따라 연산 횟수가 급격히 증가할 수 있다.
