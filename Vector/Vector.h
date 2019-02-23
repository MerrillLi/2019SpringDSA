//
// Created by 黎钰晖 on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_VECTOR_H
#define INC_2019SPRINGDSA_VECTOR_H

#include "stdbool.h"

#define ElementType int

typedef struct __Vector
{
    ElementType* data;
    int size;
    int capacity;
}*Vector;

Vector InitVector(int capacity);


void DisposeVector(Vector vector);


//判断数组是否为空
bool VectorEmpty(Vector vector);


//数组扩容
void internalResize(Vector vector,int newCapacity);


void internalRangeCheck(Vector vector,int index);


//插入指定位置
void VectorAddAt(Vector vector, int index, ElementType element);


//末尾添加一个元素
void VectorAddLast(Vector vector,ElementType element);


//在头部添加一个元素
void VectorAddFirst(Vector vector,ElementType element);


//获取指定索引位置的元素
ElementType VectorGet(Vector vector,int index);


//设置指定索引位置的元素,返回旧值
ElementType VectorSet(Vector vector,int index,ElementType element);


//查询是否含有指定的元素
bool VectorContains(Vector vector,ElementType element);


//查找指定元素下标，找不到则返回-1
int VectorFind(Vector vector,ElementType element);

//删除指定位置的存储对象
ElementType VectorRemoveAt(Vector vector, int index);


//删除指定的元素
ElementType VectorRemove(Vector vector,ElementType element);


//删除Vector中第一个元素
ElementType VectorRemoveFirst(Vector vector);


//删除Vector中最后一个元素
ElementType VectorRemoveLast(Vector vector);


void VectorToString(Vector vector);















#endif //INC_2019SPRINGDSA_VECTOR_H
