//
// Created by 黎钰晖 on 2019-02-23.
//
#include "Vector.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"

Vector InitVector(int capacity)
{
    Vector vector = malloc(sizeof(struct __Vector));
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(ElementType)*capacity);
    return vector;
}

void DisposeVector(Vector vector)
{
    free(vector->data);
    vector->data = NULL;
    free(vector);
    vector = NULL;
}

//判断数组是否为空
bool VectorEmpty(Vector vector)
{
    return vector->size == 0;
}

//数组扩容
void internalResize(Vector vector,int newCapacity)
{
    //翻倍扩容
    ElementType* newData =(ElementType*)malloc(sizeof(ElementType) * newCapacity);
    for (int i = 0; i < vector->size; ++i) {
        newData[i] = vector->data[i];
    }
    ElementType* oldData = vector->data;
    vector->data = newData;
    vector->capacity = newCapacity;
    free(oldData);
}

void internalRangeCheck(Vector vector,int index)
{
    assert(!(index < 0 || index > vector->size));
}

//插入指定位置
void VectorAddAt(Vector vector, int index, ElementType element)
{
    internalRangeCheck(vector,index);
    if(vector->size == vector->capacity)
        internalResize(vector,2 * vector->size);

    for (int i = vector->size - 1; i >= index; --i) {
        vector->data[i + 1] = vector->data[i];
    }
    vector->data[index] = element;
    vector->size ++;

}

//末尾添加一个元素
void VectorAddLast(Vector vector,ElementType element)
{
    VectorAddAt(vector, vector->size, element);
}

//在头部添加一个元素
void VectorAddFirst(Vector vector,ElementType element)
{
    VectorAddAt(vector, 0, element);
}

//获取指定索引位置的元素
ElementType VectorGet(Vector vector,int index)
{
    internalRangeCheck(vector,index);
    return vector->data[index];
}

//设置指定索引位置的元素,返回旧值
ElementType VectorSet(Vector vector,int index,ElementType element)
{
    internalRangeCheck(vector,index);
    ElementType oldVal = vector->data[index];
    vector->data[index] = element;
    return oldVal;
}

//查询是否含有指定的元素
bool VectorContains(Vector vector,ElementType element)
{
    for (int i = 0; i < vector->size; ++i) {
        if(vector->data[i] == element) return true;
    }
    return false;
}

//查找指定元素下标，找不到则返回-1
int VectorFind(Vector vector,ElementType element)
{
    for (int i = 0; i < vector->size; ++i) {
        if(vector->data[i] == element) return i;
    }
    return -1;
}

//删除指定位置的存储对象
ElementType VectorRemoveAt(Vector vector, int index)
{
    internalRangeCheck(vector,index);
    ElementType delVal = vector->data[index];
    for (int i = index + 1; i < vector->size; ++i) {
        vector->data[i - 1] = vector->data[i];
    }

    vector->size --;
    return delVal;
}

//删除指定的元素
ElementType VectorRemove(Vector vector,ElementType element)
{
    int index = VectorFind(vector,element);
    if(index != -1)
        VectorRemoveAt(vector,index);
}

//删除Vector中第一个元素
ElementType VectorRemoveFirst(Vector vector)
{
    return VectorRemoveAt(vector,0);
}

//删除Vector中最后一个元素
ElementType VectorRemoveLast(Vector vector)
{
    return VectorRemoveAt(vector,vector->size - 1);
}

void VectorToString(Vector vector)
{
    printf("[");
    printf("%d",vector->data[0]);
    for (int i = 1; i < vector->size; ++i) {
        printf(", %d",vector->data[i]);
    }
    printf("]\n");
}