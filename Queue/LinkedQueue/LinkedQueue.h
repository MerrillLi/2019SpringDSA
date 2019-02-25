//
// Created by ¿ËÓ⁄ÍÕ on 2019-02-25.
//

#ifndef INC_2019SPRINGDSA_LINKEDQUEUE_H
#define INC_2019SPRINGDSA_LINKEDQUEUE_H
#include <stdlib.h>
#define ElementType int
typedef struct __QueueNode
{
    ElementType data;
    struct __QueueNode* next;
    struct __QueueNode* prev;
}QueueNode;

typedef struct __LinkedQueue
{
    QueueNode* head;
    QueueNode* tail;
    int size;

}*LinkedQueue;

QueueNode* internalCreateQueueNode(ElementType data);

LinkedQueue InitLinkedQueue();

void LinkedQueueEnqueue(LinkedQueue queue,ElementType data);

ElementType LinkedQueueDequeue(LinkedQueue queue,ElementType data);



#endif //INC_2019SPRINGDSA_LINKEDQUEUE_H
