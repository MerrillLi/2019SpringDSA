//
// Created by јиоЏкЌ on 2019-06-22.
//

#ifndef INC_2019SPRINGDSA_STACK_H
#define INC_2019SPRINGDSA_STACK_H
#define ElemType int

#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayStack {
    ElemType *arr;
    int top;
    int capacity;
} *ArrayStack;

ArrayStack init_arraystack(int capacity) {
    ArrayStack stack = (ArrayStack) malloc(sizeof(struct ArrayStack));

    stack->arr = (ElemType *) malloc(sizeof(ElemType) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

bool push_arraystack(ArrayStack stack, ElemType e) {
    if (stack->top == stack->capacity - 1)
        return false;
    stack->arr[++stack->top] = e;
    return true;
}

ElemType pop_arraystack(ArrayStack stack) {
    if (stack->top == -1)
        return false;
    return stack->arr[stack->top--];
}

ElemType empty_arraystack(ArrayStack stack){
    return stack->top == -1;
}

ElemType full_arraystack(ArrayStack stack){
    return stack->top == stack->capacity - 1;
}

ElemType size_arraystack(ArrayStack stack){
    return stack->top;
}

ElemType gettop_arraystack(ArrayStack stack){
    if(!empty_arraystack(stack)){
        return stack->arr[stack->top];
    }
    return false;
}

void ensure_push_arraystack(ArrayStack stack,ElemType e){
    stack->capacity *= 2;
    stack->arr = realloc(stack->arr, sizeof(ElemType) * (stack->capacity));
    stack->arr[++stack->top] = e;
}

#endif //INC_2019SPRINGDSA_STACK_H
