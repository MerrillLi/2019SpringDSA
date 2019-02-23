//
// Created by 黎钰晖 on 2019-02-23.
//

#ifndef INC_2019SPRINGDSA_SINGLYLINKEDLIST_H
#define INC_2019SPRINGDSA_SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdbool.h>

#define ElementType void*
typedef struct __SinglyNode
{
    ElementType* data;
    struct __SinglyNode* next;
}*SinglyNode;

typedef struct __SinglyLinkedList
{
    SinglyNode head;
    int size;
}*SinglyLinkedList;

//初始化单链表
SinglyLinkedList InitLinkedList();

//判断是否为空
bool LinkedListEmpty(SinglyLinkedList linkedList);

//生成节点
SinglyNode internalCreateSingleNode(ElementType element);

//将数据插入链表
void LinkedListInsert(SinglyLinkedList linkedList,ElementType element);

//查询数据是否存在链表中
bool LinkedListContains(SinglyLinkedList linkedList,ElementType element);

//将数据从链表中移除
void LinkedListRemove(SinglyLinkedList linkedList,ElementType element);

//移除全部节点
void LinkedListClear(SinglyLinkedList linkedList);

//得到节点
SinglyNode LinkedListGetNode(SinglyLinkedList linkedList,ElementType element);

#endif //INC_2019SPRINGDSA_SINGLYLINKEDLIST_H
