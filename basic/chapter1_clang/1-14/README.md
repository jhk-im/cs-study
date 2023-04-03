# 함수 포인터

```txt
1) c언어 에서는 함수의 이름을 이용해 특정한 함수를 호출한다.
2) 함수 이름은 메모리 주소를 반환한다.
```

---

## 함수포인터 예제

```c
#include <stdio.h>

void function() {
    printf("It's my fuction.");
}

int main() {
    printf("%d\n", function);
    return 0;
}
```

```cmd
730653056
```

- 함수의 주소값을 출력한다.

### 함수포인터

1. 함수포인터는 특정한 함수의 반환 자료형을 지정하는 방식으로 선언할 수 있다.
2. 함수 포인터를 이용하면 형태가 같은 서로 다른 기능의 함수를 선택적으로 사용할 수 있다.

```c
반환 자료형 (*함수명)(매개변수) = 함수명;
```

- 하나의 포인터를 만들어서 특정한 함수를 기리키도록 한 것이다.

---

### 매개변수 및 반환 자료형이 없는 함수 포인터

```c
#include <stdio.h>

void myFunction() {
    printf("It's my fuction.\n");
}

void yourFunction() {
    printf("It's your function.\n");
}


int main() {
    void(*fp)() = myFunction;
    fp();
    fp = yourFunction;
    fp();
    return 0;
}
```

```cmd
It's my fuction.
It's your function.
```

- 포인터 함수가 myFunction 함수를 가리키도록 한 후 출력
- 출력 이후에 yourFunction을 가리키도록 변경

---

### 매개변수 및 반환자료형이 있는 포인터

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {
    int(*fp)(int, int) = add;
    printf("%d\n", fp(10, 3));
    fp = sub;
    printf("%d\n", fp(10, 3));
    return 0;
}
```

```cmd
13
7
```

- 반환 자료형이 int인 함수포인터 fp를 만들고 매개변수를 지정한 후 add 함수를 기리키도록 한다.
- 출력 후 sub 함수를 가리키도록 변경한다.

---

### 함수 포인터를 반환하여 사용하기

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int (*process(char* a))(int,int) {
    printf("%s\n", a);
    return add;
}

int main() {
    printf("%d\n", process("10과 20을 더해보겠습니다.")(10,20));
    return 0;
}
```

```cmd
10과 20을 더해보겠습니다.
30
```

- process라는 포인터에 자체 매개변수가 있다.
- process포인터가 add 함수를 가리키므로 int 자료형 2개를 매개변수로 받도록 한다.
- 함수포인터는 잘 사용되지않는다.

---

### 내용 정리하기

1. c언어 프로그램의 모든 함수는 내부적으로 포인터 형태로 관리할 수 있다.
2. 함수 포인터는 자주 사용되지 않지만 알고 있으면 컴퓨터의 구조를 이해하는데 도움을 준다. ㄴ
