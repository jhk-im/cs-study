# 변수와 상수

```txt
1) 변수와 상수의 개념을 이해
2) 변수와 상수를 활용한 기본 프로그램 작성
3) 정수와 실수의 표현 방법
4) 변수로 사용할 수 있는 기본적인 자료형
```

---

## Hello World 분석

* 처음부터 Hello world에 들오간 모든 소스코드를 이해하려하지 말자.
* 반복적인 학습을 통해 모든 소스코드의 내용을 이해하도록 하자.

```txt
#include <stdio.h>

int main(void) {
printf("Hello World! \n");
system("pause");
return 0;
}
```

1) #include 명령어를 이용해 다양한 라이브러리를 불러올 수 있다.
2) stdio.h는 여러가지 기본적인 기능을 담고 있다.
-> standard input/output
3) 프로그램은 항상 main() 함수로부터 시작된다.
4) 함수의 반환값이 없을 수 도 있으나 메인함수에서는 0을 반환하는 것이 일반적이다.
5) 문자를 출력하기 위해 printf()함수를 사용
-> printf()는 stdio.h 헤더 파일에 포함되어 있다.
6) 하나의 명령어가 끝났으면 세미콜론을 붙인다.
7) system() 함수를 사용하여 운영체제의 기본적인 기능을 사용할 수 있다.
-> 명령 프롬프트에서 pause 명령어는 키보드를 입력하기 전까지 대기하는 기능을 수행한다.

---

### 변수와 상수

1) 변수(Variable) -> 변할 수 있는 데이터

* 변수의 선언
    * 변수를 선언할 때 자료형과 변수명을 입력한다.
    * 원하는 경우 초기값을 적용
	* 가장 많이 사용되는 변수는 Integer 변수이다.

```c
int a;
int a = 7;
```

```c
int main(void) {
    int a = 7;
    printf("The number is %d. \n", a);
    system("pause");
    return 0;
}
```

* 초기화 되지 않은 변수는 쓰레기값이 할당된다.
* Visual Studio 에서는 초기화되지 않은 변수를 감지하고 빌드 오류를 출력한다. 

```c
#include <stdio.h>

int a;

int main(void) {
    printf("The number is %d. \n", a);
    system("pause");
    return 0;
}
```

* 만약 a가 main() 내부가 아닌 바깥에 선언되면 정적 변수가 되고 c에서 정적변수는 기본적으로 0값이 할당된다.

---

### 기본적인 자료형

* `int` -> 정수형을 표현할 때 사용 (억단위) / 4byte
* `long long` -> 숫자가 긴 정수형을 표현할 때 사용 / 8byte
* `double` -> 일반적인 실수형을 표현할 때 사용 / 8byte
* `string` -> 문자열을 표현할 때 사용 /   c++에서 등장
* `bool` -> 참/거짓을 표현할 때 사용 / 1bit  
* `char` -> 한 문자를 표현할 때 사용 / 1byte

---

### 예약어와 식별자

* 식별자 (identifier)란 변수나 함수 등의 고유한 이름을 지정할 때 사용
* C문법으로 정해진 예약어는 식별자로 사용할 수 없다.
-> string, for, void, bool, if, while, char, return, double ..

---

### 정수의 표현방법

* 컴퓨터는 내부적으로 2진수로 숫자를 표현한다.

#### 9는 다음과 같이 나타낸다

|0|0|0|0|1|0|0|1|
|--|--|--|--|--|--|--|--|
|부호|64|32|16|**8**|4|2|**1**|

* 오른쪽에서부터 숫자를 더한다.
* 결과적으로 9라는 숫자를 가지게 된다.
* 8개의 비트만으로 127까지 표시할 수 있다.

#### -9는 다음과 같이 나타낸다

|1|0|0|0|1|0|0|1|
|--|--|--|--|--|--|--|--|
|**부호**|64|32|16|**8**|4|2|**1**|

* 부호 절대값 방식
* 가장 왼쪽 비트를 부호 비트로 사용하여 음수와 양수를 구분한다.
* 부호 절대값 방식은 다양한 값의 연산을 수행하기 적합하지 않다.
  
#### 대신 2의 보수를 사용하고 이는 다음과 같다

|1|1|1|1|0|1|1|1|
|--|--|--|--|--|--|--|--|
|부호|64|32|16|8|4|2|1|

* 2의 보수 = 1의보수 + 1
* 1의 보수란 모든 비트를 뒤집는 것을 의미한다.
* 2의 보수를 이용하면 덧셈 연산만을 이용하여 양수와 음수를 연산할 수 있다.
-> 가장 왼쪽에서 올림수가 발생하면 무시한다.

```txt
00001001 (9) + 11110111 (-9) = 00000000 (0)
```

* 이러한 이유로 컴퓨터 내부에서 부호 절대값 방식 대신 2의 보수 방식을 채택하고 있다.

---

### 실수의 표현방법

* 일반적으로 컴퓨터는 오차 없이 정확한 실수를 표현할 수 없다.
* 넓은 범위의 실수를 표현하는 방식을 사용한다.

#### 부호, 지수, 유효숫자를 이용한다

<table>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>...</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>...</td>
    <td>0</td>
  </tr>
  <tr>
	<td>부호</td>
    <td colspan="3" align="center">지수</td>
    <td colspan="4" align="center">유효숫자</td>
  </tr>
</table>

* 해당 내용은 컴퓨터 구조와 이산수학과 관계가 깊기 때문에 여기서는 가볍게 이해하는 정도로 넘어가도 좋다.

---

### 내용정리

1) 변수는 변할 수 있는 데이터, 상수는 변하지 않는 데이터
2) 컴퓨터가 정수를 표현할 때는 2의 보수 방식을 이용