//
// Created by ¿ËÓ⁄ÍÕ on 2019-02-15.
//

#ifndef INC_2019SPRINGDSA_DUALCYCLELINKEDLIST_H
#define INC_2019SPRINGDSA_DUALCYCLELINKEDLIST_H

#include <stdbool.h>

#define ElementType int
typedef struct DualCycNode {
    ElementType data;
    struct DualCycNode *prev;
    struct DualCycNode *next;
} LinkedNode;

typedef struct __DCLinkedList{
    LinkedNode *head;
    int length;
}*DualCycLinkedList;

DualCycLinkedList InitDualCycList();

void DisposeDualCycList(DualCycLinkedList list);

bool DualCycListIsEmpty(DualCycLinkedList list);

ElementType DualCycListGetElement(DualCycLinkedList list, int index);

bool DualCycListContains(DualCycLinkedList list, ElementType element);

void DualCycListInsert(DualCycLinkedList list, ElementType element);

void DualCycListRemove(DualCycLinkedList list,ElementType element);

#endif //INC_2019SPRINGDSA_DUALCYCLELINKEDLIST_H
