//
// Created by 黎钰晖 on 2019-02-24.
//

#ifndef INC_2019SPRINGDSA_STACK_H
#define INC_2019SPRINGDSA_STACK_H

#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define DEFAULTSIZE 10
typedef struct __Stack
{
    ElementType* arr;
    int top;
    int capacity;
}*Stack;

//初始化自动扩容栈
Stack InitStack()
{
    Stack stack = (Stack)malloc(sizeof(struct __Stack));
    stack->arr = (ElementType*)malloc(sizeof(ElementType) * DEFAULTSIZE);
    stack->top = -1;
    stack->capacity = DEFAULTSIZE;
    return stack;
}

//添加进栈
void StackPush(Stack s, ElementType element)
{
    if(s->top + 1 == s->capacity)
    {
        ElementType* newarr = (ElementType*)malloc(sizeof(ElementType) * 2 * s->capacity);
        for (int i = 0; i < s->top + 1; ++i) {
            newarr[i] = s->arr[i];
        }
        s->arr = newarr;
        s->capacity *= 2;
    }
    s->arr[++ s->top] = element;

}

//弹出顶端元素
ElementType StackPop(Stack s)
{
    return s->arr[s->top --];
}

//查看顶端元素
ElementType StackTop(Stack s)
{
    return s->arr[s->top];
}









#endif //INC_2019SPRINGDSA_STACK_H
