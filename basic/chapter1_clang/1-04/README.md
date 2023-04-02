# 조건문

```txt
1) 조건문을 통한 프로그램의 흐름 결정
2) IF와 Switch 학습
```

---

## IF

* 내부에 조건을 검사해 프로그램의 진행 경로 결정
* 조건의 개수가 많지 않을 때 사용하는 것이 유리

```c
if (조건 1) {
  // 조건 1에 부합
}
else if (조건 2) {
  // 조건 2에 부합
}
else {
  // 위 조건들에 모두 부합하지 않을 때 
}
```

example1

```c
printf("손님이 몇 명 왔나요?");
int a;
scanf("%d", &a);
if (a == 1 || a == 2) {
    printf("2인석으로 안내합니다.\n");
}
else if (a == 3 || a == 4) {
    printf("4인석으로 안내합니다.\n");
}
else {
    printf("단체석으로 안내합니다.\n");
}
```

example2

```c
 int size;
 printf("메인 메모리 크기를 입력하세요. (GB)");
 scanf("%d", &size);
 if (size >= 16) {
  printf("메인 메모리 크기가 충분합니다.\n");
 }
 else {
  printf("메인 메모리를 증설하세요.\n");
 }
```

---

### Switch

* 다양한 조건이 존재할 때 사용하면 소스코드를 짧게 유지할 수 있다.
* 조건에 부합하는 경우 아래쪽의 case도 모두 만족시킨다.
* 일반적인 경우 case문의 마지막에 break을 넣어 특정 부분만 실행하도록 한다.
* char, int, long, double등의 자료형을 사용할 수 있다.

```c
switch (확인 대상) {
  case value1:
   //value1에 부합
   break;
  case value2:
   //value2에 부합
   break;w
  Default:
   //모두 아닌경우  
```

example 1

```c
 printf("학점을 입력하세요.");
 char count;
 scanf("%c", &count);
 switch (count) {
 case 'A':
  printf("A 학점입니다.\n");
  break;
 case 'B':
  printf("B 학점입니다.\n");
  break;
 case 'C':
  printf("C 학점입니다.\n");
  break;
 default:
  printf("학점을 바르게 입력하세요.\n");
 }
```

example2

```c
 printf("월을 입력하세요.");
 int month;
 scanf("%d", &month);
 switch (month) {
 case 1: case 2: case 12:
  printf("겨울입니다.\n");
  break;
 case 3: case 4: case 5:
  printf("봄입니다.\n");
  break;
 case 6: case 7: case 8:
  printf("여름입니다.\n");
  break;
 case 9: case 10: case 11:
  printf("가을입니다.\n");
  break;
 }
```
