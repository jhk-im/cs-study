# 파일 입출력

```txt
1) 소프트웨어에서 파일 입출력이 필요한 이유에 대하여 이해한다. 
2) c언어를 이용해 파일 입출력하는 방법을 학습한다. 
```

---

## 파입 입출력의 필요성

1) 프로그램이 꺼진 이후에도 데이터를 저장하기 위해서는 파일 입출력이 필요하다.
2) 게임을 껏다 킬 때마다 다시 처음부터 캐릭터를 키우지 않도록 상태를 저장해야한다.
3) 파일이 실질적으로 저장되는 위치 -> SSD, HDD

---

### 파일 열고 닫기

1) 파일을 열 때는 fopen() 함수를 이용한다.
2) 파일을 닫을 때는 flose() 함수를 이용한다.
3) 입출력 변숭는 FILE 형식의 포인터 변수로 선언한다.

```c
FILE *fp;
fp = fopen(파일경로, 접근 방식);
// 파일 관련 처리
fclose(fp);
```

4)fopen() 함수에는 파일 경로와 접근 방식을 설정할 수 있다.
5)기본 경로는 현재 프로그램의 경로이다.
6)가장 많이 사용되는 접근방식은 다음과 같다.

`r` -> 파일에 접근하여 데이터를 읽는다.
`w` -> 파일에 접근하여 데이터를 기록한다. (이미 존재하는 파일은 덮어쓴다.)
`a` -> 파일에 접근하여 데이터를 뒤에서부터 기록한다.

---

### 파일 입출력 함수

1) 기본적인 입출력을 위해 printf(), scanf() 함수를 사용했다.
2) 파일 입출력에서는 fprintf(), fscanf() 가 사용된다.

```c
fprintf(파일 포인터, 서식, 형식지정자);
fscanf(파일 포인터, 서식, 형식지정자);
```

### 파일 입출력 과정

1) 파일 입출력은 열고, 읽고/쓰고, 닫기 과정을 철저히 따라야한다.
2) 파일을 열 때는 파일 포인터가 사용되며, 이는 동적으로 할당된 것이다.
3) 따라서 파일 처리 이후에 파일을 닫아주지 않으면 메모리 누수가 발생한다.

`파일 열기` -> `파일 읽기/쓰기` -> `파일 닫기`

---

### 파일을 열어 문자열 쓰기

1) 현재 프로그램의 경로에서 특정한 파일을 쓰기 모드로 생성하여 문자열을 기록할 수 있다.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char s[20] = "Hello World";
    FILE *fp;
    fp = fopen("hello_world.txt", "w");
    fprintf(fp, "%s\n", s);
    fclose(fp);
}
```

```cmd
// hello_world.txt 생성
Hellow World
```

---

### 간단한 학생 정보 시스템 만들기

학생들의 이름과 성적 파일 만들기

```cmd
// Tutorials/Debug/input.txt
5
홍길동 98
홍정호 84
홍광호 89
홍진형 70
홍석찬 45
```

### 학생 데이터를 읽어서 그대로 출력하기

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int score;
} Student;

int main(void)
{
    int n, sum = 0;
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    Student *students = (Student *)malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d", &((students + i)->name), &((students + i)->score));
        fprintf("이름: %s, 성적: %d\n", &((students + i)->name), &((students + i)->score));
    }
    return 0;
}
```

```cmd
이름: 홍길동, 성적: 98
이름: 홍정호, 성적: 84
이름: 홍광호, 성적: 89
이름: 홍진형, 성적: 70
이름: 홍석찬, 성적: 45
```

### 성적 평균을 구하고 메모리 할당 해제하기

```c
int main(void)
{
    int n, sum = 0;
    FILE *fp;
    fp = fopen("../debug/input.txt", "r");
    fscanf(fp, "%d", &n);
    Student *students = (Student *)malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d", &((students + i)->name), &((students + i)->score));
    }
    for (int i = 0; i < n; i++)
    {
        sum += (students + i)->score;
    }
    free(students);
    fclose(fp);
    printf("점수 평균: %.2f\n", (double)sum / n);
    return 0;
}
```

```cmd
점수 평균: 77.20
```

---

### 배운내용 정리하기

1) 파일 입출력을 이용해 데이터를 파일로부터 가져오거나 데이터를 파일로 내보낼 수 있다.
2) 파일 입출력이 끝난 이후에는 반드시 파일 객체를 메모리에서 할당 해제해 주어야한다.
