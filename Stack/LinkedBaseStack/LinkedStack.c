//
// Created by 黎钰晖 on 2019-02-25.
//

#include "LinkedStack.h"

LinkedNode *internalCreateStackNode(ElementType data) {
    LinkedNode* node = (LinkedNode*)malloc(sizeof(struct __LinkedNode));
    node->data = data;
    return node;
}

LinkedStack InitLinkedStack() {
    LinkedStack linkedStack = (LinkedStack)malloc(sizeof(struct __LinkedStack));
    linkedStack->size = 0;
    linkedStack->head = internalCreateStackNode(NULL);
    return linkedStack;
}

void LinkedStackPush(LinkedStack stack, ElementType data) {

    LinkedNode* node = internalCreateStackNode(data);
    node->next = stack->head->next;
    stack->head->next = node;
    stack->size ++;

}

ElementType LinkedStackPop(LinkedStack stack) {
    //有东西才可以弹出
    assert(stack->head->next != NULL);
    ElementType ret = stack->head->next->data;
    LinkedNode* delNode = stack->head->next;
    stack->head->next = delNode->next;
    free(delNode);
    stack->size --;

    return ret;

}

void FreeLinkedStack(LinkedStack s) {
    LinkedNode* node = s->head;
    while(node != NULL)
    {
        LinkedNode* next = node->next;
        free(node);
        node = next;
    }
    free(s);

}

void ClearLinkedStack(LinkedStack s) {
    LinkedNode* node = s->head->next;
    while(node != NULL)
    {
        free(node);
        node = node->next;
    }
    s->head->next = NULL;
}
