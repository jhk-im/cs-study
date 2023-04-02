# 문자열

```txt
1) C언어에서 문자열을 다루는 방법에 대하여 학습
2) 문자열 관련 함수를 익히고 학습  
```

---

## 문자열의 개념

1) 문자들의 배열을 의미한다.
2) 컴퓨터 메모리 구조상에서 마지막에 null 값을 포함한다.

|0|1|2|3|4|5|6|7|8|9|10|11|
|-|-|-|-|-|-|-|-|-|-|-|-|
|h|e|l|l|o| |w|o|r|l|d|\0|

---

### 문자열과 포인터

1) 문자열 형태로 포인터를 사용하면 포인터에 특정한 문자열의 주소를 넣게된다.
2) 다음 코드는 "Hello World"문자열을 읽기 전용으로 메모리공간에 넣은 뒤 위치를 처리한다.
3) 이러한 문자열을 '문자열 리터럴' 이라한다. 컴파일러가 알아서 메모리 주소를 결정한다.

example 1

```c
#include <stdio.h>

int main(void) {
 char a = 65;
 printf("%c\n", a);
 system("pause");
}
```

```cmd
Hello World
```

* 이렇게 포인터로 지정된 문자열은 변경이 불가능하다.

example 2

* 포인터로 문자열을 선언했다고 하더라도 기존의 배열처럼 처리할 수 있다.

```c
 char *a = "Hello World";
 printf("%c\n", a[0]);
 printf("%c\n", a[1]);
 printf("%c\n", a[2]);
```

```cmd
H
e
l
```

---

### 문자열 입출력 함수

* scanf() 함수는 공백을 만날 때 까지만 입력받지만 gets() 함수는 공백까지 포함하여 한줄을 입력받는다.

example 1

```c
 char b[100];
 gets(b);
 printf("%s\n", b);
```

```cmd
my name is kim(입력)
my name is kim(출력)
```

* gets() 함수는 버퍼의 크기를 벗어나도 입력을 받는다는 단점이있다.
* C11 표준부터 버퍼의 크기를 철저히 지키는 gets_s()함수가 추가되었다.

example 2

```c
 char c[100];
 gets_s(c, sizeof(c));
 printf("%s\n", c);
```

* sizeof() 는 특정 배열의 전체 크기를 알려준다.
* 문자열의 크기를 지정하여 그 이상 입력을 받지 않도록 한다.

```txt
문자가 100자이상이 넘어가면 런타임 오류가 발생하여 프로그램이 종료됨 
```

---

### 문자열의 다양한 함수

* <string.h> 라이브러리에 포함되어 있다.
`strlen()` -> `문자열 길이 반환`
`strcmp()` -> `문자열 1이 2보다 사전적으로 앞에있으면 -1, 아니면 1 반환`
`strcpy()` -> `문자열을 복사`
`strcat()` -> `문자열 1에 문자열 2 더하기`
`strstr()` -> `문자열 1에 문자열 2가 어떻게 포함되어있는지를 반환`

```c
#include <string.h>

int main(void) {
 char d[20] = "JeongHoon Kim";
 char e[20] = "C Language";
 char f[20] = "";
 char g[20] = "Language";
 printf("문자열의 길이: %d\n", strlen(d));
 printf("문자열의 길이: %d\n", strlen(e));
 printf("두 배열의 사전 순 비교: %d\n", strcmp(d, e));
 strcpy(f, d);
 printf("복사된 문자열: %s\n", f);
 strcat(f, e);
 printf("합쳐진 문자열: %s\n", f);
 printf("찾은 문자열: %s\n", strstr(e, g));
 system("pause");
 return 0;
}
```

```cmd
문자열의 길이: 13
문자열의 길이: 10
두 배열의 사전 순 비교: 1
복사된 문자열: JeongHoon Kim
합쳐진 문자열: JeongHoon KimC Language
찾은 문자열: Language
```

---

### 배운내용 정리하기

* C언어의 문자열은 배열이므로 포인터 형태로 사용할 수 있다.
* C언어에서 문자열 비교, 연산, 탑색 등의 알고리즘은 각각 함수 형태로 제공된다.
