//
// Created by јиоЏкЌ on 2019-02-24.
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
    int size;
    int top;
}*Stack;

Stack InitStack()
{
    Stack stack = (Stack)malloc(sizeof(struct __Stack));
    stack->arr = (ElementType*)malloc(sizeof(ElementType) * DEFAULTSIZE);
    stack->size = 0;
    stack->top = -1;
    return stack;
}





#endif //INC_2019SPRINGDSA_STACK_H
