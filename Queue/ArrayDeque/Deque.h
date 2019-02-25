//
// Created by јиоЏкЌ on 2019-02-24.
//

#ifndef INC_2019SPRINGDSA_DEQUE_H
#define INC_2019SPRINGDSA_DEQUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int front;
    int rear;
    int count;
} Deque;


/** Checks whether the circular queue is empty or not. */
bool DequeIsEmpty(Deque* obj);

/** Checks whether the circular queue is full or not. */
bool DequeIsFull(Deque* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */
Deque* DequeCreate(int k);

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool DequeEnQueue(Deque* obj, int value);

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool DequeDeQueue(Deque* obj);

/** Get the front item from the queue. */
int DequeFront(Deque* obj);

/** Get the last item from the queue. */
int DequeRear(Deque* obj);


void DequeFree(Deque* obj) {
    free(obj->arr);
    obj->arr = NULL;
    free(obj);
}
#endif //INC_2019SPRINGDSA_DEQUE_H
