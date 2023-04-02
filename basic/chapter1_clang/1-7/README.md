## 배열

```txt
1) 동일한 자료형을 여러 개 담는 기술
2) 배열을 사용하면 동일한 성격의 데이터를 다수 표현할 수 있다.
```

|인덱스|0|1|2|3|4|5|6|7|8|
|-|-|-|-|-|-|-|-|-|-|-|
|데이터|6|4|2|1|14|23|9|0|4|

* 배열의 초기화

```txt
자료형 배열명[배열의 크기] = {초기화};
```

example1
```c
#include <stdio.h>

int main(void) {
	int a[10] = { 6,5,4,3,9,8,0,1,2,7 };
	for (int i = 0; i < 10; i++) {
		printf("%d", a[i]);
	}
	system("pause");
}
```

example2 : 최대값 찾기
```c
	int maxValue = INT_MIN;
	for (int i = 0; i < 10; i++) {
		if (maxValue < a[i]) maxValue = a[i];
	}
	printf("%d\n", maxValue);
```

#### INT_MIN

* 최대값을 구하기 위해 자주 사용되는 기능
* <limits.h>헤더파일에 정의되어 있으며 int형 범위의 최소값을 반환
* INT_MAX 또한 사용 가능

---

### 문자열과 배열

* 원시적 c언어는 기본적으로 문자열을 제공하지 않았다.
* C언어에서는 Character를 여러개 묶어놓는 형태로 문자열을 표현하였다.
* C++에서는 이러한 불편함을 없애고자 자체적 string 자료형을 제공한다.
* 하나의 문자는 1바이트만을 담으므로 다음과 같은 문자의 배열을 사용한다.

```c
char a[20] = "Hello world"
```

example1  : %s -> 문자열 형식 지정자

```c
	char c[20];
	scanf("%s", &c);
	printf("%s\n", c);
```

example2 : 특정 인덱스의 문자에 바로 접근할 수 있다.

```c
	char d[20] = "Hello World";
	d[5] = ',';
	printf("%s\n", d);
```

example3: 특정 문자 개수 출력

```c
	char d[20] = "Hello World";
	int count = 0;
	for (int i = 0; i <= 10; i++) {
		if (d[i] == 'l') count++;
	}
	printf("%d\n", count);
```

---

### 배운내용 정리하기

* 배열을 이용하여 많은 양의 데이터를 쉽게 처리한다.
* c언어의 문자열은 내부적으로 문자의 배열이다.
