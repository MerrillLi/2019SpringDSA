//
// Created by 黎钰晖 on 2019-03-14.
//

#ifndef INC_2019SPRINGDSA_STATICLINKEDLIST_H
#define INC_2019SPRINGDSA_STATICLINKEDLIST_H

#define ElemType int
#define MAXSIZE 100

#include <stdlib.h>

typedef struct node
{
    ElemType data;
    int link;
}StaticNode;

typedef struct __StaticLinkedList
{
    //代表一块内存区域
    StaticNode Nodes[MAXSIZE];
    //代表一个可以分配的内存空间
    int newPtr;
}*StaticLinkedListSpace;

//初始化静态空间
void InitStaticLinkedListSpace(StaticLinkedListSpace * space)
{
    //初始化静态链表空间
    *space = (StaticLinkedListSpace)malloc(sizeof(struct __StaticLinkedList));
    //空域位置为0
    (*space)->newPtr = 0;
    //初始化每一个节点的信息
    for (int i = 0; i < MAXSIZE - 1; ++i) {
        (*space)->Nodes[i].link = i + 1;
    }
    (*space)->Nodes[MAXSIZE - 1].link = -1;
}

void InitStaticLinkedList()
{

}

void DestroyStaticLinkedList(StaticLinkedListSpace space,int* SlinkEntry)
{
    int node = *SlinkEntry;
    int delNode = node;
    //节点不为空
    while(node != -1)
    {

    }

}

void InsertStaticLinkedList(StaticLinkedListSpace space,int* Slink,int i,ElemType data)
{
    int j = 0;

}


#endif //INC_2019SPRINGDSA_STATICLINKEDLIST_H
