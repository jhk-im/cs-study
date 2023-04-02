# 연산자

```txt
1) C언어의 기본적인 연산자
2) 연산자의 우선순위를 이해하여 다양한 연산을 수행
```

---

## 연산자

* 연산자(Operator)란 연산을 수행하는 기호를 의미한다.
* 피연산자(Operand)란 연산에 포함되는 변수나 상수를 의미한다.
* a + b에서 a와b는 피연산자, +는 연산자에 해당한다.

|피연산자|연산자|피연산자|
|:-:|:-:|:-:|
|A|+|B|

---

### 연산자의 종류

* C언어의 연산자 종류

|||
|-|-|-|
|대입연산자|=|
|산술연산자|+, -, *, /, %|
|관계연산자|==, !=, >, <, >=, <=|
|논리연산자|!, &&, ll|
|증감연산자|++, --|
|삼항연산자|? :|
|비트연산자|!, ~, &, ^, >>, <<|

#### 대입연산자

* 등호를 이용해서 우변항을 좌변항에 넣는다.
* 자료형에 부합하는 값을 좌변항에 있는 변수에 넣는다.

#### 산술연산자

* 기본적인 사칙연산을 사용할 수 있다.
* 나머지를 구하기 위해 모듈러 연산을 사용한다.
* `%` -> 나머지 연산자

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);
    system("pause");
}
```

```cmd
// cmd
10 5
10 + 5 = 15
10 - 5 = 5
10 * 5 = 50
10 / 5 = 2
10 % 5 = 0
계속하려면 아무 키나 누르십시오 . . .
```

#### Escape Sequence

* c언어에서 특정한 표현을 출력하기 위해 사용하는 문법
* `\n` -> 줄 바꾸기
* `\t` -> 수평 탭 넣기
* `\\` -> 백 슬래시 넣기
* `\"` -> 큰 따옴표 넣기
* `\b` -> 백 스페이스 넣기

```c
...
int main(void) {
    ...
    printf("\"A\tB\tC\tD\"\n");
    printf("\"A\tB\tC\tD\"\n");
    printf("\"A\tB\tC\tD\"\n");
    system("pause");
}
```

```cmd
// cmd
"A      B       C       D"
"A      B       C       D"
"A      B       C       D"
```

#### 관계연산자

* 컴퓨터는 0을 False, 그 외의 숫자를 True로 받아들인다.
* 출력할 때는 False = 0 , True = 1 을 출력한다.

```c
...
int main(void) {
    ...
    int c, d;
    scanf("%d %d", &c, &d);
    printf("%d\n", c > d);
    system("pause");
}
```

```cmd
//cmd
4 5
0
```

#### 논리연산자

* ! -> 부정, && -> 그리고 , || -> 또는

```c
...
int main(void) {
...
    int e, f, g;
    scanf("%d %d %d", &e, &f, &g);
    printf("%d\n", !e);
    printf("%d\n", e && f);
    printf("%d\n", (e > f) && (f > g));
    system("pause");
    return 0;
}
```

```cmd
//cmd
9 8 7
0
1
1
```

##### 증감연산자

* `++변수` -> 변수 값을 1 증가 시킨 후 반환
* `변수++` -> 변수 값을 1 증가시킨 후 증가되기 전 값을 반환
* `--변수` -> 변수 값을 1 감소시킨 후 감소된 값 반환
* `변수--` -> 변수값을 1 감소시킨 후 감소되기 전 값 반환

```c
...
int main(void) {
...
    int h = 7;
    printf("%d\n", ++h);
    printf("%d\n", --h);
    printf("%d\n", h++);
    printf("%d\n", h--);
    system("pause");
    return 0;
}
```

```cmd
//cmd
8
7
7
8
```

#### 삼항 연산자
* 세 개의 항을 이용해서 조건문을 수행할 수 있는 연산자

```c
    int i = 7, j = 7;
    printf("%d\n", (i == j) ? 100 : -100);
```

```cmd
//cmd
100
```

#### 비트 연산자

* `~` = 부정
-> ~(11000011)2 = (00111100)2 -> Not 뒤바꿈
* `&` = 그리고
-> (00001101)2 & (00000011)2 = (00000001)2 -> 모두 1인 위치만 1로
* `|` = 또는
-> (11001100)2 | (00110000)2 = (11111100)2 -> 둘중 하나가 1이면 1로
* `^` = 배타적
-> (11001111)2 ^ (00000011)2 = (11001100)2 -> 둘중 하나가 1이여야만 1로
* `<<`  = 왼쪽 시프트 (오른쪽도 있음)
-> (00001111)2 << 3 = (01111000)2 -> 1들을 왼쪽에 있는 숫자만큼 이동
* 시프트 연산자는 2의 배수를 처리하고자 할 때 효과적

숫자 9의 이진수 표현
|0|0|0|0|1|0|0|1|
|-|-|-|-|-|-|-|-|
-> 왼쪽 시프트 수행하여 1들을 왼쪽으로 1칸씩 이동
|0|0|0|1|0|0|1|0|
|-|-|-|-|-|-|-|-|
-> 18로 2배 증가

#### 연산자 우선순위

* 수학에서의 우선순위와 흡사하다.

|우선순위|연산자|
|-|-|
|1|++, --|
|2|!, ~|
|3|*, /, %|
|4|+, -|
|5|<<, >>|
|6|<. <=, >, >=|
|7|==, !=|
|8|비트, 논리, 삼항|
|9|삼항|

---