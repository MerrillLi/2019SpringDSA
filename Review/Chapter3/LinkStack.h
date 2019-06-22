//
// Created by јиоЏкЌ on 2019-06-22.
//

#ifndef INC_2019SPRINGDSA_LINKSTACK_H
#define INC_2019SPRINGDSA_LINKSTACK_H

#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

typedef struct stackNode {
    ElemType data;
    struct stackNode *next;
} stackNode, *LinkStack;


LinkStack init_linkedstack() {
    return NULL;
}

void push_linkedstack(LinkStack *stack, ElemType e) {
    stackNode *newnode = (stackNode *) malloc(sizeof(stackNode));
    newnode->data = e;
    newnode->next = *stack;
    *stack = newnode;

}

ElemType pop_linkedstack(LinkStack *stack) {
    if(stack == NULL)
        return false;
    stackNode *delNode = *stack;
    *stack = delNode->next;
    free(delNode);
    return delNode->data;

}

bool empty_linkedstack(LinkStack stack) {
    return stack == NULL;
}

ElemType gettop_linkedstack(LinkStack stack){
    return stack == NULL? false: stack->data;
}



#endif //INC_2019SPRINGDSA_LINKSTACK_H
