//
// Created by 黎钰晖 on 2019-02-23.
//

#include <stdlib.h>
#include <stdbool.h>
#include "SinglyLinkedList.h"


//初始化单链表
SinglyLinkedList InitLinkedList()
{
    SinglyLinkedList linkedList = (SinglyLinkedList)malloc(sizeof(struct __SinglyLinkedList));
    linkedList->size = 0;
    linkedList->head = (SinglyNode)malloc(sizeof(struct __SinglyNode));
    return linkedList;
}

//判断是否为空
bool LinkedListEmpty(SinglyLinkedList linkedList)
{
    return linkedList->size == 0;
}

//生成节点
SinglyNode internalCreateSingleNode(ElementType element)
{
    SinglyNode newNode = (SinglyNode)malloc(sizeof(struct __SinglyNode));
    newNode->data = element;
    newNode->data = NULL;
    return newNode;
}

//将数据插入链表
void LinkedListInsert(SinglyLinkedList linkedList,ElementType element)
{
    //头插法
    SinglyNode newNode = internalCreateSingleNode(element);
    newNode->next = linkedList->head;
    linkedList->head = newNode;
    linkedList->size ++;
}

//查询数据是否存在链表中
bool LinkedListContains(SinglyLinkedList linkedList,ElementType element)
{
    SinglyNode node = linkedList->head->next;
    while(node != NULL)
    {
        if(node->data == element) return true;
        node = node->next;
    }
    return false;
}

//将数据从链表中移除
void LinkedListRemove(SinglyLinkedList linkedList,ElementType element)
{
    SinglyNode prev = linkedList->head;
    SinglyNode node = linkedList->head->next;
    while (node != NULL)
    {
        if(node == element) break;
        prev = prev->next;
        node = node->next;
    }
    SinglyNode next = node->next;

    prev->next = next;
    free(node);

    linkedList->size --;
}

//移除全部节点
void LinkedListClear(SinglyLinkedList linkedList)
{
    SinglyNode node = linkedList->head->next;
    while(node != NULL)
    {
        SinglyNode delNode = node;
        node = node->next;
        free(delNode);
    }
    linkedList->head = NULL;
    linkedList->size = 0;
}

//得到节点
SinglyNode LinkedListGetNode(SinglyLinkedList linkedList,ElementType element)
{
    SinglyNode node = linkedList->head->next;
    while(node != NULL)
    {
        if(node->data == element) return node;
        node = node->next ;
    }
    return NULL;
}
