//
// Created by ¿ËÓ⁄ÍÕ on 2019-02-24.
//

#ifndef INC_2019SPRINGDSA_QUEUE_H
#define INC_2019SPRINGDSA_QUEUE_H

#include <stdlib.h>
#include <printf.h>

#define DEFAULTSIZE 10
#define ElementType int
//◊ÛÕ∑”“Œ≤
typedef struct __Queue
{
    ElementType* arr;
    int front;
    int rear;
    int size;
    int capacity;
}*Queue;

Queue InitQueue();

int QueueIndex(Queue queue,int index);

void EnQueue(Queue queue,ElementType element);

int QueueSize(Queue queue);

void* QueueFront(Queue queue);

void* DeQueue(Queue queue);

void* QueueRear(Queue queue);

void Print(Queue queue);




#endif //INC_2019SPRINGDSA_QUEUE_H
