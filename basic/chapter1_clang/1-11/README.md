# 컴퓨터의 변수 처리방법

```txt
1) C언어에서 다양한 변수를 처리하는 방법을 학습
2) 지역변수, 전역변수, 레지스터 변수 학습
3) 특정한 함수에 값을 전달하거나 주소를 전달하는 방법을 이해한다. 
```

---

## 프로그램 메모리 주소

1) 프로그램이 실행되기 위해서는 프로그램이 메모리에 적재(Load)되어야 한다.
2) 프로그램의 크기를 충당할 수 있을 만큼의 메모리 공간이 필요하다.
3) 일반적인 컴퓨터 운영체제는 메모리 공간을 네 가지로 구분하여 관리한다.

|코드영역|데이터영역|힙영역|스택영역|
|-|-|-|-|
|소스코드|정적변수, 전역변수|동적할당변수|지역변수, 매개변수|

---

### 전역변수

1) Global Variable
2) 프로그램 어디서든 접근 가능한 변수를 말한다.  
3) main 함수가 실행되기 전에 프로그램의 시작과 동시에 메모리에 할당된다.
4) 프로그램이 커질수록 전역변수로 인해 복잡해질 수 있다.
5) 메모리 데이터 영역에 적재된다.

example

```c
#include <stdio.h>

int a = 5;

void changeValue() {
 a = 10;
}

int main(void) {
 printf("%d\n", a);
 changeValue();
 printf("%d\n", a);
 system("pause");
 return 0;
}
```

```cmd
5
10
```

* 전역변수는 어느 곳에서도 접근이 가능하다.

---

### 지역변수

1) Local Variable
2) 프로그램에서 특정한 블록에서만 접근할 수 있는 변수를 말한다.
3) 함수가 실행될 때 마다 메모리에 할당되어 함수가 종료되면 메모리에서 해제된다.
4) 메모리의 스택영역에 기록된다.

example

```c
 char b[100];
 gets(b);
 printf("%s\n", b);
```

```c
7
```

* if 와같은 블럭안에 선언된 변수는 지역변수이다.
* 블럭에서 선언된 변수는 블럭 안에서만 사용 가능하다.

---

### 정적변수

1) Static Variable
2) 특정한 블록에서만 접근할 수 있는 변수
3) 프로그램이 실행될 때 메모리에 할당되어 프로그램이 종료되면 해제된다.
4) 메모레 데이터 영역에 적재된다.

example

```c
#include <string.h>

void process() {
 static int c = 5;
 c = c + 1;
 printf("%d\n", c);
}

int main(void) {
 process();
 process();
 process();
 system("pause");
 return 0;
}
```

```cmd
6
7
8
```

* static 키워드로 인해 프로그램 시작과 동시에 적재가 된 이후에는 초기화하지 않는다.

---

### 레지스터 변수

1) Register Variable
2) 메인메모리 대신 CPU의 레지스터를 사용하는 변수
3) 레지스터는 매우 한정되어 있으므로 실제로 레지스터에서 치리될 지 장담할 수 없음

example

```c
 register int d = 10;
 for (int i = 0; i < d; i++) {
  printf("%d", i);
 }
 printf("\n");
```

```cmd
0123456789
```

---

### 함수의 매개변수가 처리 될 때

1) 함수를 호출할 때 함수에 필요한 데이터를 매개변수로 전달한다.
2) 전달 방식은 값에 의한 전달과 참조에 의한 전달 방식이 있다.
3) 값에 의한 전달방식은 단지 값을 전달하므로 함수내에서 변수가 새로 생성된다.
4) 참조에 의한 전달 방식은 주소를 전달하므로 원래의 변수 자체에 접근할 수 있다.

example1 : 값에의한 전달방식

1) 함수로 두 개의 값을 넣으면 새롭게 두 변수가 메모리 내에 할당되어 처리된다.
2) 원래 변수의 값에는 영향을 미치지 못한다.

```c
void add(int e, int f) {
 e = e + f;
}

int main(void) {
 int e = 7;
 add(e, 10);
 printf("%d\n", e);
 system("pause");
 return 0;
}
```

```cmd
7
```

* add() 함수 내부에 있는 변수 e는 외부에있는 e에 영향을 미칠 수 없다.

example 2 : 참조에의한 전달방식

1) 참조에 의한 전달방식은 함수의 매개변수로 값을 전달하는 것이 아니라 주소를 전달한다.
2) 이러한 방식을 이용하면 원래 변수의 값에 접근하여 값을 변경할 수 있다.

```c
void add2(int *g) {
 *g = (*g) + 10;
}

int main(void) {
 int g = 7;
 add2(&g);
 printf("%d\n", g);
 system("pause");
 return 0;
}
```

```cmd
17
```

* 단지 매개변수로 포인터 변수를 보낼 뿐 특별한 것은 없다.

---

### 배운내용 정리하기

* C언어에선 전역변수, 지역변수 등 다양한 변수가 사용된다.
* 함수의 데이터 전달 방법은 값을 전달하는 방법과 주소를 전달하는 방법이 있다.