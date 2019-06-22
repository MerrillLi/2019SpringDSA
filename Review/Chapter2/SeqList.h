//
// Created by ¿ËÓ⁄ÍÕ on 2019-06-21.
//

#ifndef INC_2019SPRINGDSA_SEQLIST_H
#define INC_2019SPRINGDSA_SEQLIST_H

#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

/*
 *
 * High Recommend to Follow Five Steps
 * It is a standard for Sequential List
 *
 * 1. Verify Index
 * 2. Verify Capacity
 * 3. Execute
 * 4. Verify Return Value
 * 5. Return
 *
 * Not all of them are necessary
 * It is an approach to write correct SeqList Algorithm
 */

typedef struct SeqList {
    ElemType *data;
    int size;
    int capacity;
} *SeqList;


SeqList init_seqlist(int capacity) {
    SeqList list = (SeqList) malloc(sizeof(struct SeqList));
    list->data = (ElemType *) malloc(sizeof(ElemType) * capacity);
    list->capacity = capacity;
    list->size = 0;
    return list;
}

void destroy_seqlist(SeqList *list) {
    free((*list)->data);
    free(list);
    list = NULL;
}

void clear_seqlist(SeqList list) {
    list->size = 0;
}

int length_seqlist(SeqList list) {
    return list->size;
}

ElemType get_seqlist(SeqList list, int i) {
    if (i >= 0 || i <= list->size - 1)
        return list->data[i];

    return false;
}

int locate_seqlist(SeqList list, ElemType e) {

    int i = 0;

    //Step3 locate the element
    while (i < list->size && list->data[i] != e)
        i++;

    // Step4 Verify the Return
    if (i >= list->size)
        return -1;
    //Step5 Return
    return i;

}

bool contain_seqlist(SeqList list, ElemType e) {

    int i = 0;
    bool found = false;
    while (i < list->size && !found)
        if (list->data[i] == e)
            found = 1;
        else
            i++;
    return found;


}

bool insert_seqlist(SeqList list, int index, ElemType e) {

    // 1. Verify Index
    if (index < 0 || index >= list->size)
        return false;

    // 2. Verify Capacity
    if (list->size == list->capacity)
        return false;

    // 3. Execute
    // [0,index - 1]  [index, size - 1]
    for (int i = list->size - 1; i >= index; --i) {
        list->data[i + 1] = list->data[i];
    }

    list->data[index] = e;
    list->size ++;

    // 4. Verify Return Value

    // 5. Return
    return true;

}

bool remove_seqlist(SeqList list, int index) {
    // 1. Verify Index
    if (index < 0 || index >= list->size)
        return false;
    // 2. Verify Capacity
    if (list->size == 0)
        return false;
    // 3. Execute
    //[0,index - 1],[index],[index + 1, size -1]
    for (int i = index + 1; i <= list->size - 1; ++i) {
        list->data[i - 1] = list->data[i];
    }
    // 4. Verify Return Value

    // 5. Return
    return true;
}

bool empty_seqlist(SeqList list) {
    return list->size == 0;
}

bool full_seqlist(SeqList list) {
    return list->size == list->capacity;
}

int prior_seqlist(SeqList list, ElemType e) {
    // 1. Verify Index
    // 2. Verify Capacity
    // 3. Execute
    int i = 0;
    while (i < list->size && list->data[i] != e)
        i++;
    // 4. Verify Return Value
    // should in the range of [1, size-1]
    if (i > list->size - 1 || i < 1)
        return false;
    // 5. Return
    return i - 1;
}

int next_seqlist(SeqList list, ElemType e) {
    // 1. Verify Index
    // 2. Verify Capacity
    // 3. Execute
    int i = 0;
    while (i < list->size && list->data[i] != e)
        i++;
    // 4. Verify Return Value
    // should be in the range if [0, size - 1 - 1]
    if (i > list->size - 2)
        return false;
    // 5. Return
    return i + 1;
}

bool ensure_insert_seqlist(SeqList list, int index, ElemType e) {

    // should be in the range of [0,size-1]
    if (index < 0 || index > list->size - 1)
        return false;

    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, sizeof(ElemType) * list->capacity);
    }
    //[0,index - 1] [index] [index + 1,size]
    for (int i = list->size-1; i >= index + 1; --i) {
        list->data[i + 1] = list->data[i];
    }

    list->data[index] = e;
    list->size ++;
    return true;
}


#endif //INC_2019SPRINGDSA_SEQLIST_H
