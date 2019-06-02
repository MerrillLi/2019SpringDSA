//
// Created by 黎钰晖 on 2019-02-18.
//链地址法的HashMap实现(From JDK 1.8)
//非自动扩容版本
//

#ifndef INC_2019SPRINGDSA_LINKEDHASHMAP_H
#define INC_2019SPRINGDSA_LINKEDHASHMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define KeyType int
#define ValueType int

typedef struct Entry
{
    long hash;
    KeyType key;
    ValueType value;
    struct Entry* next;
}Entry;

typedef struct __HashMap
{
    //array of Entry
    Entry* table[1048576];
    //Entry** table;
    int size;
    int capacity;
    int (*hashIndex)(void* key,void* map);
}*LinkedHashMap;

//获取指定数值后的最小2的幂
int minTwoPow(const int n)
{
    return (int)pow(2,ceil(log(n)/log(2)));
}

//得到对象在哈希表中的存储索引
int getHashIndex(void* obj, void* map)
{
    LinkedHashMap hashMap = (LinkedHashMap)map;
    return abs((int)(obj)&(hashMap->capacity - 1));
}

//初始化哈希表
LinkedHashMap InitHashMap(int capacity)
{
    LinkedHashMap map = malloc(sizeof(struct __HashMap));
    map->size = 0;
    map->capacity = minTwoPow(capacity);
    map->hashIndex = getHashIndex;
    //map->table = malloc(sizeof(Entry)*capacity);
    for (int i = 0; i < map->capacity; ++i) {
        map->table[i] = NULL;
    }
    return map;
}

//创建存储节点
Entry* createEntry(int hash,KeyType key,ValueType value)
{
    Entry* entry = (Entry*)malloc(sizeof(struct Entry));
    if(entry == NULL) exit(-1);
    entry->hash = hash;
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// 把一个元素放入Hash表中
void HashMapPut(LinkedHashMap map,KeyType key,ValueType value)
{
    //通过绑定的hash函数计算出Hash值
    int index = 0;
    index = map->hashIndex(key, map);
    //如果Hash表位置没有被占用,则添加进位置中
    if(map->table[index] == NULL )
    {
        map->table[index] = createEntry(index,key,value);
        map->size++;
    }
    //如果hash值已经存在了
    else
    {
        Entry* entry = map->table[index];
        Entry* newNode = createEntry(index,key,value);
        newNode->next = entry;
        map->table[index] = newNode;
        map->size++;
    }
}

//根据键查找HashMap中的值
ValueType HashMapGet(LinkedHashMap map,KeyType key)
{
    //计算并得到哈希链表的入口
    int index = map->hashIndex(key,map);
    Entry* entryList = map->table[index];
    //在链表中寻找
    while(entryList != NULL)
    {

        if(entryList->key == key)
        {
            return entryList->value;
        }
        if(entryList->next != NULL)
            entryList = entryList->next;
        else
            return NULL;
    }
    //查找不到，返回空
    return NULL;
}

//查看表中是否有对应的Key
bool HashMapContains(LinkedHashMap map,KeyType key)
{
    int index = map->hashIndex(key,map);
    Entry* node = map->table[index];
    while(node != NULL)
    {
        if(key == node->key)
            return true;
        else
        {
            if(node->next != NULL)
                node = node->next;
            else
                return false;
        }
    }
    return false;

}

//设置hash表中key的value，同时返回旧的value
ValueType HashMapSet(LinkedHashMap map,KeyType key,ValueType value)
{
    int index = map->hashIndex(key,map);
    //创建虚拟头节点
    Entry* dummyHead = (Entry*)malloc(sizeof(Entry));
    dummyHead->next = map->table[index];
    Entry* node = dummyHead;
    while (node!= NULL)
    {
        //如果匹配key，则记录旧值
        if (node->key == key)
        {
            ValueType oldVal = node->value;
            node->value = value;
            return oldVal;
        }
        node = node->next;

    }
    free(dummyHead);

    return NULL;
}

//移除哈希表中的元素
void HashMapRemove(LinkedHashMap map,KeyType key)
{
    int index = map->hashIndex(key,map);
    Entry* list = map->table[index];
    Entry* dummyHead = (Entry*)malloc(sizeof(struct Entry));
    dummyHead->next = list;
    Entry* node = dummyHead;
    Entry* prev = node,*delNode;

    while(node != NULL)
    {
        if(node->next->key == key)
        {
            prev = node;
            delNode = prev->next;
            prev->next = delNode->next;
            delNode->next = NULL;
            free(delNode);

        }
        node = node->next;
    }
    map->table[index] = dummyHead->next;
    free(dummyHead);


}

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
