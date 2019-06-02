//
// Created by 黎钰晖 on 2019-02-26.
//

#ifndef INC_2019SPRINGDSA_OPENADDRHASHMAP_H
#define INC_2019SPRINGDSA_OPENADDRHASHMAP_H

#include <stdlib.h>
#include <stdbool.h>

#define KeyType int
#define ValueType int

#define EMPTY 0
#define USED 2

typedef struct dataNode
{
    KeyType key;
    ValueType value;
    int tag;
}dataNode;

typedef struct __OAHashMap
{
    dataNode* data;
    int capacity;
    int size;
}*OAHashMap;


int hashIndex(int key, int capacity)
{
    return key % capacity;
}

OAHashMap InitOAHashMap(int capacity)
{
    OAHashMap hashMap = (OAHashMap)malloc(sizeof(OAHashMap));
    hashMap->capacity = capacity;
    hashMap->size = 0;
    hashMap->data = (dataNode*)malloc(sizeof(dataNode) * capacity);
    return hashMap;
}

void OAHashMapPut(OAHashMap hashMap,KeyType key,ValueType value)
{
    int index = hashIndex(key,hashMap->capacity);
    if(hashMap->data[index].tag == EMPTY)
    {
        hashMap->data[index].value = value;
    }else {
        int i = index;
        while (hashMap->data[i++].tag != EMPTY)
        {
            if(i == hashMap->capacity -1)
                i = 0;
        }
    }
}

ValueType OAHashMapRemove(OAHashMap hashMap, KeyType key)
{
    int index = hashIndex(key,hashMap->capacity);
    while(hashMap->data[index++].key != key)
    {
        if(index == hashMap->capacity - 1)
            index = 0;
    }
    ValueType val = hashMap->data[index].value;
    hashMap->data[index].tag = EMPTY;
    return val;
}

bool OAHashMapContains(OAHashMap hashMap,KeyType key)
{
    int index = hashIndex(key,hashMap->capacity);
    //记录结束点
    int start = index;
    //处理区间 [start , capacity - 1] && [0 , start - 1]
    while(hashMap->data[index++ % hashMap->capacity ].key != key )
    {
        if(hashMap->data[index++ % hashMap->capacity ].key == key)
        if(index == start + hashMap->capacity) return false;
        if(index == hashMap->capacity - 1) index = 0;
    }
    return false;
}





#endif //INC_2019SPRINGDSA_OPENADDRHASHMAP_H
