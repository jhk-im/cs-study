# 반복문

```txt
1) 반복문을 이용해 특정 조건이 부합할 때 특정한 명령어를 반복
2) 구구단 등의 예제를 작성해보며 반복문의 내부적 원리 이해 
```

---

## For

* For문 내부의 조건에 부합하면 계속해서 특정한 구문을 실행
* 반복문을 탈출하고자 하는 위치에 break구문 삽입

```c
for (초기화; 조건; 반복 끝 명령어) {
 // 반복 실행
}
```

example1

```c
for (int i = 0; i <= 100; i++) {
  printf("%d\n", i);
 }
```

example2

```c
 int n, sum = 0;
 printf("n을 입력하세요. ");
 scanf("%d", &n);
 for (int j = 1; j <= n; j++) {
  sum = sum + j;
 }
 printf("%d\n", sum);
```

---

### 무한루프

* Infinite Loop란 종료 조건 없이 한없이 반복되는 반복문을 의미한다.
* 일부러 무한 루프를 발생시키는 경우도 있지만 일반적인 경우 실수에 해당한다.

```c
for (초기화; 조건; 반복 끝 명령어) {
 // 조건이 참인경우 무한루프 발생 
}
```

example 1

```c
 for(;;) {
  printf("Infinite Loop!\n")
 }
```

example2

```c
for(int l = 0; l <= 100; l--) {
 printf("Infinite Loop!\n")
}
```

---

### -1이 입력될 때 까지 더하기

```c
int minus = 0;
 for (; 1;) {
  int x;
  scanf("%d", &x);
  if (x == -1) break;
  sum += x;
 }
 printf("%d\n", minus);
```

---

### While

* WHILE문의 조건에 부합하면 계속해서 특정한 구문을 실행
* 반복문을 탈출하고자 하는 위치에 break구문 삽입

```c
while (조건) {
 // 반복 실행
}
```

example 1 : 특정문자 N번 출력하기

```c
 int b;
 char c;
 scanf("%d %c", &b, &c);
 while (b--) {
  printf("%c", c);
 }
```

example 2: 특정 숫자 구구단 출력

```c
 int g; 
 scanf("%d", &g);
 int x = 1;
 while (x <= 9) {
  printf("%d * %d = %d\n", g, x, g * x);
  x++;
 }
```

---

### 중첩된 반복문

* 반복문 내부에 다른 반복문이 존재하는 형태
* 반복문이 중첩될수록 연산 횟수는 제곱으로 늘어남

example1: 구구단 출력 (while)

```c
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
```

example2: 구구단 출력 (for)

```c
 for (int i = 1; i <= 9; i++) {
  for (int j = 1; j <= 9; j++) {
   printf("%d * %d = %d\n", i, j, i * j);
  }
  printf("\n");
 }
```

### For문과 WHILE문

* For문은 While문으로 변경할 수 있으며 반대로도 가능하다.
* C언어의 소스코드가 최적화 되면서 어셈블리어 단에서는 동일한 명령어로 동작하기 때문이다.
