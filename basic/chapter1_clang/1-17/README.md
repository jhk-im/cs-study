# 전처리기

```txt
1) 전처리기 구문은 다른 프로그램 영역과 독립적으로 처리된다. 
2) 전처리기 구문은 소스코드 파일 단위로 효력이 존재한다. 
```

---

## 파일포함 전처리기

1) #include는 전처리기에서 가장 많이 사용되는 문법이다.
2) 특정한 파일을 라이브러리로 포함시키기 위해 사용한다.
3) #include 구문으로 가져올 수 있는 파일에는 제약이 없다.

```c
#include "파일이름"
#include <파일이름>
```

### include <파일이름>

1) 이와같이 선언하면 시스템 디렉토리에서 파일을 검색한다.
2) 운영체제마다 시스템 디렉토리가 존재하는 경로가 다를 수 있다.
3) 대표적으로 stdio.h와 같은 헤더 파일 등이 시스템 디렉토리에 존재한다.

### include "파일이름"

1) 이와같이 선언하면 현재 폴더에서 파일을 먼저 검색한다.
2) 만약 현재 폴더에 파일이 없다면 시스템 디렉토리에서 파일을 검색한다.

---

### 나만의 헤더파일 작성하기

1) #include를 이용해 가져오는 파일은 말 그대로 파일의 소스코드 자체를 다 가져오는 것이다.
2) 따라서 의도치 않게 한 번 참조한 헤더 파일을 여러번 찹조하지 않도록 유의해야 한다.

```c
// temp.h
int add(int a, int b)
{
    return a + b;
}
```

```c
// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "temp.h"

int main(void)
{
    printf("%d\n", add(3, 7));
    return 0;
}
```

```cmd
// 결과
10
```

---

### 내가 정의한 헤더파일 사용하기

1) #include를 이용해 가져오는 파일은 말 그대로 파일의 소스코드 자체를 전부 다 가져오는 것이다.
2) 따라서 의도치 않게 한 번 참조한 헤더 파일을 여러 번 참조하지 않도록 유의해야 한다.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "temp.h"
#include "temp.h" x -> 오류발생

int main(void)
{
    printf("%d\n", add(3, 7));
    return 0;
```

---

### 메크로 전처리기

1) 프로그램 내에서 사용되는 상수나 함수를 매크로 형태로 저장하기 위해 사용한다.
2) #define 문법을 사용해 정의할 수 있다.

```c
#include <stdio.h>
#define PI 3.1415926535

int main(void)
{
    int r = 10;
    printf("원의 둘레: %.2f\n", 2 * PI * r);
    return 0;
}
```

```cmd
원의 둘레: 62.83
```

* PI -> 매크로 정의

---

### 인자를 가지는 매크로 전처리기

1) #define 문법은 소스코드의 양을 획기적으로 줄이는 데 도움을 준다.

```c
#include <stdio.h>
#define ll long long
#define ld long double

int main(void)
{
    ll a = 987654321000;
    ld b = 100.5054;
    printf("%.1f\n", a * b);
    return 0;
}
```

---

### 조건부 컴파일

1) 조건부 컴파일은 컴파일이 이루어지는 영역을 지정하는 기법이다.
2) 일반적으로 디버깅과 소스코드 이식을 목적으로 하여 작성된다.
3) c언어로 시스템 프로그램을 작성할 때에는 운영체제에 따라서 소스코드가 달라질 수 있다.
4) 이 때 운영체제에 따라 컴파일이 수행되는 소스코드를 다르게 할 수 있다.

```c
// temp.h

#ifndef _TEMP_H_
#define _TEMP_H_

int add(int a, int b)
{
    return a + b;
}
#endif
```

```c
// main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "temp.h"
#include "temp.h"

int main(void)
{
    printf("%d\n", add(3, 7));
    return 0;
}
```

* ifndef - endif에 의해서 temp.h가 한번만 컴파일 되도록 한다.

---

### 파일 분할 컴파일

1) 일반적으로 자신이 직접 라이브러리를 마들 때에는 c언어 파일과, 헤더 파일을 모두 작성해야한다.

```c
// main.c
#include <stdio.h>
#include "temp.h"

int main(void)
{
    printf("%d\n", add(3, 5));
    return 0;
}
```

```c
// temp.h
#ifndef _TEMP_H_
#define _TEMP_H_
int add(int a, int b);
#endif
```

```c
// temp.c
#include "temp.h"

int add(int a, int b)
{
    return a + b;
}
```

* 헤더파일과 c언어 문법을 나눠서 정의한다.
* 깔끔하게 소스코드를 관리할 수 있다.

---

### 배운내용 정리하기

1) 전처리기의 사용은 필수는 아니지만 때에 따라서 소스코드를 획기적으로 줄일 수 있다.
