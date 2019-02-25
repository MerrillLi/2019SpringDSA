//
// Created by 黎钰晖 on 2019-02-25.
//

#ifndef INC_2019SPRINGDSA_LINKEDSTACK_H
#define INC_2019SPRINGDSA_LINKEDSTACK_H
#define ElementType int

#include <stdlib.h>
#include <assert.h>

typedef struct __LinkedNode
{
    ElementType data;
    struct __LinkedNode* next;
}LinkedNode;

typedef struct __LinkedStack
{
    LinkedNode* head;
    int size;
}*LinkedStack;


LinkedNode* internalCreateStackNode(ElementType data);

LinkedStack InitLinkedStack();

void LinkedStackPush(LinkedStack stack,ElementType data);

ElementType LinkedStackPop(LinkedStack stack);

//完全删除Stack，包括其本身
void FreeLinkedStack(LinkedStack s);

void ClearLinkedStack(LinkedStack s);




#endif //INC_2019SPRINGDSA_LINKEDSTACK_H
