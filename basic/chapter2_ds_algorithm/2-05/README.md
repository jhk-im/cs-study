# 스택으로 계산기 만들기

## 개요

```txt
* 중위 표기법을 후위 표기법으로 변환
* 후위 표기법을 계산하여 결과 값을 도출

중위표기법
- 일반적으로 사람이 수식을 표기할 때 사용하는 방법
- 7 * 5 + 3

후위표기법
- 컴퓨터가 계산하기에 편한 수식의 형태
- 연산자가 뒤쪽에 위치함
- 7 5 * 3 +
```

---

### 중위 표기법 -> 후위 표기법 변환

```txt
* 피연산자가 들어오면 바로 출력
* 연산자가 들어오면 자기보다 우선순위가 높거나 같은 것들을 빼고 자신을 스택에 담음
* 여는 괄호를 만나면 무조건 스택에 담음
* 닫는 괄호를 만나면 여는 괄호를 만날 때까지 스택에서 출력
```

### 후위 표기법 계산

```txt
* 피연산자가 들어오면 스택에 담음
* 연산자를 만나면 스택에서 두 개의 연산자를 꺼내 연산한 뒤 결과를 스택에 담음
* 연산을 마친 뒤 스택에 남아있는 하나의 피연산자가 연산 수행 결과
```