#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[100];
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void push(Stack *stack, char *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = stack->top;
    stack->top = node;
}

char *getTop(Stack *stack)
{
    Node *top = stack->top;
    return top->data;
}

char *pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("스택 언더플로우가 발생했습니다.\n");
        return NULL;
    }
    Node *node = stack->top;
    char *data = (char *)malloc(sizeof(char) * 100);
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

int getPriority(char *i)
{
    if (!strcmp(i, "("))
        return 0;
    if (!strcmp(i, "+") || !strcmp(i, "-"))
        return 1;
    if (!strcmp(i, "*") || !strcmp(i, "/"))
        return 2;
    return 3;
}

char *transition(Stack *stack, char **s, int size)
{
    static char res[1000] = "";
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/"))
        {
            while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i]))
            {
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            push(stack, s[i]);
        }
        else if (!strcmp(s[i], "("))
            push(stack, s[i]);
        else if (!strcmp(s[i], ")"))
        {
            while (strcmp(getTop(stack), "("))
            {
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            pop(stack);
        }
        else
            strcat(res, s[i]);
        strcat(res, " ");
    }
    while (stack->top != NULL)
    {
        strcat(res, pop(stack));
        strcat(res, " ");
    }
    return res;
}

void calculate(Stack *stack, char **s, int size)
{
    int x, y, z;
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/"))
        {
            x = atoi(pop(stack));
            y = atoi(pop(stack));
            if (!strcmp(s[i], "+"))
                z = y + x;
            if (!strcmp(s[i], "-"))
                z = y - x;
            if (!strcmp(s[i], "*"))
                z = y * x;
            if (!strcmp(s[i], "/"))
                z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z);
            push(stack, buffer);
        }
        else
        {
            push(stack, s[i]);
        }
    }
    printf("%s ", pop(stack));
}

int main(void)
{
    Stack stack;
    stack.top = NULL;
    char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
    int size = 1;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ' ')
            size++;
    }
    char *ptr = strtok(a, " ");
    char **input = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++)
    {
        input[i] = (char*)malloc(sizeof(char) * 100);
    }
    for (int i = 0; i < size; i++)
    {
        strcpy(input[i], ptr);
        ptr = strtok(NULL, " ");
    }
    char b[1000] = "";
    strcpy(b, transition(&stack, input, size));
    printf("후위 표기법: %s\n", b);
    size = 1;
    for (int i = 0; i < strlen(b) - 1; i++) // 마지막은 항상 공백이 들어가므로 1을 빼기
    {
        if (b[i] == ' ')
            size++;
    }
    char *ptr2 = strtok(b, " ");
    for (int i = 0; i < size; i++)
    {
        strcpy(input[i], ptr2);
        ptr2 = strtok(NULL, " ");
    }
    calculate(&stack, input, size);
    return 0;
}