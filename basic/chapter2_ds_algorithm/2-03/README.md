# 양방향 연결 리스트

## 양방향 열결 리스트 개요

```txt
* Head와 Tail을 모두 가지고 있음
* 각 노드는 앞에 있는 노드와 뒤에 있는 노드의 정보를 모두 저장하고 있음
* head<->일반노드<->일반노드<->tail

* 양방향 연결 리스트의 데이터 삽입
[prev|data|next]   [prev|data|next]<->[prev|data|next]<->[prev|data|next]
            ⇅         ⇅
          [prev|data|next]
               삽입할노드

* 아래 예시는 삽입 및 삭제 기능에서의 예외처리가 빠져있는 간단한 코드임
```

---

### 오름차순 양방향 연결 리스트

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

void insert(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* cur;
    cur = head->next;
    while (cur->data < data && cur != tail) {
        cur = cur->next;
    }
    Node* prev = cur->prev;
    prev->next = node;
    node->prev = prev;
    cur->prev = node;
    node->next = cur;
}

void removeFront() {
    Node* node = head->next;
    head->next = node->next;
    Node* next = node->next;
    next->prev = head;
    free(node);
}

void show() {
    Node* cur = head->next;
    while (cur != tail) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    insert(2);
    insert(1);
    insert(3);
    insert(9);
    insert(7);
    removeFront();
    show(); // 2 3 9 7
    return 0;
}
```

> 양방향 연결 리스트는 각 노드가 앞,뒤 노드의 정보를 모두 저장하고 있기 때문에 리스트의 앞 혹은 뒤에서부터 모두 접근할 수 있다.
