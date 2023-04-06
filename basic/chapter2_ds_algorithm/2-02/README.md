# 연결 리스트

## 연결 리스트의 필요성

> 배열을 사용하여 데이터 리스트를 관리할 때 메모리 공간이 불필요하게 낭비 될 수 있는데 이것을 연결 리스트를 활용하여 해결할 수 있다.

---

### 배열 기반의 리스트

```c
// 데이터를 순차적으로 저장하고 처리할 때 배열 기반의 리스트를 이용함
// [1, 5, 4, 7 ,6 ,8]
#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data) {
    arr[count] = data;
    count++;
}

void addFirst(int data) {
    for (int i = count; i >= 1; i --) {
        arr[i] = arr[i - 1];
    }
    arr[0] = data;
    count++;
}

void show() {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
}

void removeAt(int index) {
    for (int i = index; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

int main(void) {
    addFirst(4);
    addFirst(5);
    addFirst(1);
    addBack(7);
    addBack(6);
    addBack(8);
    show(); // 1 5 4 7 6 8
    removeAt(4);
    show(); // 1 5 4 7 8
    return 0;
}
```

#### 배열기반 리스트의 특징

```txt
* 특정 위치의 원소에 즉시 접근할 수 있음
* 데이터가 들어갈 공간을 미리 메모리에 할당해야 함
* 원하는 위치에 삽입, 삭제가 비효율적임
```

---

### 연결리스트 구현

```txt
* 일반적으로 구조체와 포인터를 함께 사용하여 구현
* 리스트의 중간 지점에 노드를 추가하거나 삭제할 수 있어야 함
* 필요할 때 마다 메모리 공간을 할당 받음
```

#### 단일 연결 리스트

```txt
* 포인터를 이용해 단방향적으로 다음 노드를 가리킴
* 일반적으로 시작 노드를 head라고 하며 별도로 관리함
* 마지막 노드의 다음 위치 값은 NULL

    head        일반노드       일반노드
[data|next]->[data|next]->[data|next]->NULL

* 연결리스트의 데이터 삽입
    head        일반노드       일반노드
[data|next]  [data|next]->[data|next]->NULL
       ↓      ↑
     [data|next]
       삽입할노드

* 아래 예시는 삽입 및 삭제 기능에서의 예외처리가 빠져있는 간단한 코드임
```

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root) {
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

void freeAll(Node *root) {
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root) {
    Node *cur = head->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);
    showAll(head); // 9 7 1 2
    freeAll(head);
    return 0;
}
```

> 연결 리스트는 삽입과 삭제가 배열에 비해 간단하지만 특정 인덱스로 즉시 접근하지 못하며, 원소를 차례대로 검색해야 한다. 또한, 추가적인 포인터 변수가 사용되어 메모리 공간이 낭비된다.
