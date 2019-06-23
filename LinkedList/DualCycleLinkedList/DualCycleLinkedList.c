//
// Created by 黎钰晖 on 2019-02-15.
//

#include "DualCycleLinkedList.h"
#include <stdlib.h>
#include <stdbool.h>

//创建一个双向链表节点
struct DualCycNode* internalCreateNode(ElementType element)
{
    struct DualCycNode* newNode = (struct DualCycNode*)malloc(sizeof(struct DualCycNode));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = element;
    return newNode;
}

//初始化循环双链表,含形式头节点
DualCycLinkedList InitDualCycList()
{
    DualCycLinkedList list = malloc(sizeof(struct __DCLinkedList));
    list->length = 0;
    list->head = internalCreateNode(NULL);
    list->head->next = list->head;
    list->head->prev = list->head;
    return list;
}

//清空链表
void DisposeDualCycList(DualCycLinkedList list)
{
    struct DualCycNode* current = list->head->next;
    //如果没有返回到头节点，即遍历没有结束
    while(current != list->head)
    {
        //保存下一个节点的引用
        struct DualCycNode* tmp = current->next;
        //释放当前节点
        free(current);
        //移动到下一个节点
        current = tmp;
    }

}

//判断是否为空
bool DualCycListIsEmpty(DualCycLinkedList list)
{
    return list->length == 0;
}

//返回指定下标的元素
ElementType DualCycListGetElement(DualCycLinkedList list, int index)
{

}

//查找是否存在
bool DualCycListContains(DualCycLinkedList list, ElementType element)
{
    struct DualCycNode* current = list->head->next;

    while(current != list->head)
    {
        if(current->data == element)
        {
            return true;
        }
        current = current->next;
    }

    return false;

}

//插入一个元素，头插法
void DualCycListInsert(DualCycLinkedList list, ElementType element)
{
    struct DualCycNode* newNode = internalCreateNode(element);
    struct DualCycNode* nextNode = list->head->next;

    list->head->next = newNode;
    newNode->next = nextNode;

    nextNode->prev = newNode;
    newNode->prev = list->head;

    list->length ++;


}

//删除一个元素
void DualCycListRemove(DualCycLinkedList list,ElementType element)
{
    struct DualCycNode* delNode = list->head->next;
    //定位到删除节点
    while(delNode != list->head)
    {
        if(delNode->data == element) break;
        delNode = delNode->next;
    }

    //执行删除操作
    struct DualCycNode* prev = delNode->prev;
    struct DualCycNode* next = delNode->next;

    prev->next = next;
    next->prev = prev;

    free(delNode);

    list->length --;

}