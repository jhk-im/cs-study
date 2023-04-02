# 기본입출력

```txt
1) C언어의 기본 입출력 방법
2) 사용자로부터 입력 받은 데이터를 가공하여 출력
```

---

## scanf() 입력

* 특정한 변수에 값을 넣기 위해 scanf()를 사용한다. 

```c
#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    printf("입력한 숫자는 %d 입니다. \n", a);
    system("pause");
    return 0;
}
```

* Visual Studio는 기본적으로 취약한 함수를 사용할 수 없도록 제한한다.
* scanf()함수는 그냥 사용할 수 없도록 제한되어있다.
* 중요한 모듈에서는 scanf() 함수를 사용하지 않는다.

##### #define _CRT_SECURE_NO_WARNINGS 를 추가

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
...
```

* scanf() 안에 &는 특정 변수의 주소를 의미한다.
* 실제로 컴퓨터는 특정 메모리 주소에 접근하여 데이터를 수정한다.
* 메모리 주소에 얼마만큼 크기로 데이터를 사용할 지 결정해야한다.

#### 형식 지정자

* `int(4byte)` -> %d
* `long long(8bytes)` -> %lld
* `double(8bytes)` -> 입력 시 %lf, 출력시 %f
* `float(4bytes)` -> %f
* `string(제한없음)` -> %s
* `char(1bytes)`-> %c

1) double은 입력받을 때 특정 주소에 특정 크기만큼 입력을 수행한다.
 -> 출력때에는 주소가 아닌 값 자체를 출력하므로 크기를 지정하지 않아도 된다.
2) % 자체를 문자로 출력하고 싶은면 %%를 입력하여 출력한다.

---

### 다양하게 입력받아 출력하기

##### 두 숫자를 입력받아 순서 바꾸어 출력 

```c
    ...
    int b, c;
    scanf("%d %d", &b, &c);
    printf("%d %d\n", c, b);

    system("pause");
    return 0;
}
```

* 1과 2를 입력하면 21을 출력한다.

#### 실수형을 입력 받고 소숫점 셋째 자리에서 반올림하여 출력

```c
...
int main(void) {
    ...
    double d;
    scanf("%lf", &d);
    printf("%.2f\n", d);

    system("pause");
    return 0;
}
```

* 1.234를 입력하면 1.23을 출력한다.

##### 한 자리 씩 끊어서 입력받기

```c
...
int main(void) {
    ...
    int e, f, g;
    scanf("%1d%1d%1d", &e, &f, &g);
    printf("%d %d %d\n", e, f, g);

    system("pause");
    return 0;
}
```

* 123을 입력하면 1 2 3 으로 구분되어 출력한다.

---

### 내용 정리하기

1) C언어는 입출력 시 형식 지정자를 적절하게 입력해야한다.
2) printf()는 단순히 데이터를 넘기고 scanf()는 입출력을 하기 때문에 주소를 나타내기 위하여 &을 사용한다.
