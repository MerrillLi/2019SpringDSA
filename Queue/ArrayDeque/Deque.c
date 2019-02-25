//
// Created by ÀèîÚêÍ on 2019-02-24.
//

#include "Deque.h"

bool DequeIsEmpty(Deque *obj) {
    return obj->count == 0;
}

bool DequeIsFull(Deque *obj) {
    return obj->count == obj->size;
}

Deque *DequeCreate(int k) {
    Deque* queue = (Deque*)malloc(sizeof(Deque));
    queue->arr = (int*)malloc(sizeof(int)*k);
    queue->rear = -1;
    queue->front = 0;
    queue->size = k;
    queue->count = 0;
    return queue;
}

bool DequeEnQueue(Deque *obj, int value) {
    if(DequeIsFull(obj)) return false;
    obj->arr[++ obj->rear % obj->size] = value;
    obj->count ++;
    return true;
}

int DequeFront(Deque *obj) {
    if(DequeIsEmpty(obj)) return -1;
    return obj->arr[obj->front % obj->size];
}

bool DequeDeQueue(Deque *obj) {
    if(DequeIsEmpty(obj)) return false;
    obj->front ++;
    obj->count --;
    return true;
}

int DequeRear(Deque *obj) {
    if(DequeIsEmpty(obj)) return -1;
    return obj->arr[obj->rear % obj->size];
}
