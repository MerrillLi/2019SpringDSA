//
// Created by јиоЏкЌ on 2019-06-22.
//

#ifndef INC_2019SPRINGDSA_LINKEDQUEUE_H
#define INC_2019SPRINGDSA_LINKEDQUEUE_H

#include <stdlib.h>
#define ElemType int

typedef struct queueNode{
    ElemType data;
    struct queueNode* next;
}queueNode;

typedef struct LinkedQueue{
    queueNode* front;
    queueNode* rear;
    int size;
}*LinkedQueue;

LinkedQueue init_linkedqueue(){
    LinkedQueue queue = (LinkedQueue)malloc(sizeof(struct LinkedQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue_linkedqueue(LinkedQueue queue,ElemType e){
    queueNode* node = (queueNode*)malloc(sizeof(queueNode));
    node->data = e;
    node->next = NULL;
    queue->rear->next = node;
    if(queue->size == 0)
        queue->front = node;

    queue->size ++;
}

void dequeue_linkqueue(LinkedQueue queue){

    if(queue->front == NULL)
        return;
    queueNode* delNode = queue->front;
    queue->front = delNode->next;

    if(queue->size == 1)
        queue->rear = NULL;
    free(delNode);
    queue->size --;
}

#endif //INC_2019SPRINGDSA_LINKEDQUEUE_H
