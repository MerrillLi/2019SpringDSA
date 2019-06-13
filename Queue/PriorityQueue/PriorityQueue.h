//
// Created by ¿ËÓ⁄ÍÕ on 2019-03-02.
//

#ifndef INC_2019SPRINGDSA_PRIORITYQUEUE_H
#define INC_2019SPRINGDSA_PRIORITYQUEUE_H
#define ElementType int
#define MAX_HEAP 1
#define MIN_HEAP 2

#include <stdlib.h>
typedef struct __PriorityQueue
{
    ElementType* data;
    int capacity;
    int size;
    int Type;
}*PriorityQueue;

PriorityQueue InitPriorityQueue(int capacity,int heapType)
{
    PriorityQueue pq = (PriorityQueue)malloc(sizeof(struct __PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->data = (ElementType*)malloc(sizeof(ElementType) * capacity);
    pq->Type = heapType;
    return pq;
}

void SiftUp(ElementType* data,int index)
{

}

void SiftDown(ElementType* data,int index)
{

}



#endif //INC_2019SPRINGDSA_PRIORITYQUEUE_H
