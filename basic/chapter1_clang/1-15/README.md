# 구조체

```txt
1) 구조체를 활용하여 자신만의 자료형을 만드는 방법을 학습한다.
2) 구조체를 활용한 다양한 예제를 다루어보자.
```

---

## 구조체란?

1. 여러 개의 변수를 묶어 하나의 객체를 표현하고자 할 때 구조체를 사요할 수 있다.
2. 캐릭터, 몬스터, 학생, 좌표 등 다양한 객체를 모두 프로그래밍 언어를 이용해 표현할 수 있다.

### 구조체 정의와 선언1

```cmd
struct 구조체명 {
    자료형1 변수명1;
    자료형2 변수명2;
}
```

### 구조체 변수의 선언과 접근

1. 기본적으로 구조체의 변수에 접근할때는 온점을 사용한다.

```c
#include <stdio.h>

struct Student {
    char studentId[10];
    char name[10];
    char major[100];
    int grade;
};

int main(void) {
    struct Student s; // 구조체 변수 선언
    strcpy(s.studentId, "20153157"); // 구조체 변수 접근
    strcpy(s.name, "원빈");
    s.grade = 4;
    strcpy(s.major, "연극영화과");
    printf("학번: %s\n", s.studentId);
    printf("이름: %s\n", s.name);
    printf("학년: %d\n", s.grade);
    printf("학과: %s\n", s.major);
    return 0;
}
```

```cmd
학번: 20153157
이름: 원빈
학년: 4
학과: 연극영화과
```

### 구조체 정의와 선언2

1. 하나의 구조체 변수만 사용하는 경우 정의와 동시에 선언할 수 있다.
2. 이 경우 변수는 전역변수로 사용된다.

```c
struct Student {
    char studentId[10];
    char name[10];
    char major[100];
    int grade;
} s;

int main(void) {
    ~~struct Student s; // 구조체 변수 선언~~
    strcpy(s.studentId, "20153157"); // 구조체 변수 접근
    strcpy(s.name, "원빈");
    s.grade = 4;
    strcpy(s.major, "연극영화과");
    printf("학번: %s\n", s.studentId);
    printf("이름: %s\n", s.name);
    printf("학년: %d\n", s.grade);
    printf("학과: %s\n", s.major);
    return 0;
}
```

---

### 구조체 초기화

1) 구조체의 변수를 한 번에 초기화하기 위해서는 중괄호에 차례대로 변수의 값을 넣는다.

```c
#include <stdio.h>

struct Student {
    char studentId[10];
    char name[10];
    char major[100];
    int grade;
};

int main(void) {
    struct Student s = {"20153157", "원빈", "연극영화과", 4};
    printf("학번: %s\n", s.studentId);
    printf("이름: %s\n", s.name);
    printf("학과: %s\n", s.major);
    printf("학년: %d\n", s.grade);
    return 0;
}
```

```cmd
학번: 20153157
이름: 원빈
학과: 연극영화과
학년: 4
```

* 중괄호를 사용하여 선언과 동시에 초기화한다.

---

### 더 짧게 구조체 정의하기 1

1) typedef 키워드를 이용하면 임의의 자료형을 만들 수 있으므로 선언이 더 짧아진다.

```c
#include <stdio.h>

typedef struct Student {
    char studentId[10];
    char name[10];
    char major[100];
    int grade;
} Student;

int main(void) {
    *Student s = {"20153157", "원빈", "연극영화과", 4};*
    printf("학번: %s\n", s.studentId);
    printf("이름: %s\n", s.name);
    printf("학과: %s\n", s.major);
    printf("학년: %d\n", s.grade);
    return 0;
}
```

* typedef로 선언한 구조체는 struct 키워드를 입력하지 않아도 된다.

---

### 더 짧게 구조체 정의하기 2

1) 익명 구조체의 개념이 등장하여 구조체 이름을 비워놓아도 된다.

```c
#include <stdio.h>

*typedef struct {*
    char studentId[10];
    char name[10];
    char major[100];
    int grade;
} Student;
```

---

### 구조체 포인터 변수에 접근하기

1) 구조체가 포인터 변수로 사용되는 경우 내부 변수에 접근할 때 -> 기호를 사용한다.

```c
#include <stdio.h>

typedef struct {
    char studentId[10];
    char name[10];
    char major[100];
    int grade;
} Student;

int main(void) {
    Student *s = malloc(sizeof(Student));
    strcpy(s->studentId, "20153157");
    strcpy(s->name, "원빈");
    strcpy(s->major, "연극영화과");
    s->grade = 4;
    printf("학번: %s\n", s->studentId);
    printf("이름: %s\n", s->name);
    printf("학과: %s\n", s->major);
    printf("학년: %d\n", s->grade);
    return 0;
}
```

---

### 배운내용 정리하기

* 구조체는 현실 세계의 객체를 소스코드 상에서 매우 쉽게 표현할 수 있도록 해준다.
