# 스택

## 스택 개요

```txt
* 한쪽으로 들어가고 들어간 쪽에서 나오는 자료구조
* 수식 계산 등의 알고리즘에서 다방면으로 활용
* PUSH: 데이터 넣기 / POP: 데이터 꺼내기

PUSH(7)
[7][][][][][][]
PUSH(5)
[7][5][][][][][]
PUSH(4)
[7][5][4][][][][]
POP()
[7][5][][][][][]
PUSH(6)
[7][5][6][][][][]
POP()
[7][5][][][][][]
```

---

### 배열을 이용한 스택 구현

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
    if (top == SIZE -1){
        printf("스택 오버플로우 발생\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("스택 언더플로우 발생\n");
        return -INF;
    }
    return stack[top--];
}

void show() {
    printf("--- 스택 최상단 ---\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("--- 스택 최하단 ---\n");
}

int main(void) {
    push(7);
    push(5);
    push(4);
    pop();
    push(6);
    pop();
    show(); // 최상단 - 5 7 - 최하단
    return 0;
}
```

>배열을 활용하는 경우 메모리 공간을 미리 할당하는 부분이 비효율적이다.

### 열결 리스트를 이용한 스택 구현

```txt
* 스택 삽입 과정

 top->일반          일반            일반
[data|next] -> [data|next] -> [data|next]
    ↖︎
[data|next]
삽입할 노드->top
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void push(Stack *stack, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("스택 언더플로우 발생\n");
        return -INF;
    }
    Node *node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

void show(Stack *stack) {
    Node *cur = stack->top;
    printf("--- 스택 최상단 ---\n");
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("--- 스택 최하단 ---\n");
}

int main(void) {
    Stack stack;
    stack.top = NULL;
    push(&stack, 7);
    push(&stack, 5);
    push(&stack, 4);
    pop(&stack);
    push(&stack, 6);
    pop(&stack);
    show(&stack); // 최상단 - 5 7 - 최하단
    return 0;
}
```

> 연결 리스트를 활용하면 메모리 낭비 없이 안정적으로 스택을 구현할 수 있다.
