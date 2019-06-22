//
// Created by 黎钰晖 on 2019-06-21.
//

#ifndef INC_2019SPRINGDSA_LINKEDLIST_H
#define INC_2019SPRINGDSA_LINKEDLIST_H

#include <stdbool.h>
#include "stdlib.h"
#define ElemType int
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node,*LinkList;



LinkList init_linklist(){
    return NULL;
}

void destroy_linklist(LinkList list){
    while(list != NULL){
        Node* p = list;
        list = list->next;
        free(p);
    }
}

void clear_linklist(LinkList list){
    while(list != NULL){
        Node* p = list;
        list = list->next;
        free(p);
    }
}

int length_linklist(LinkList list){
    Node* p = list;
    int len = 0;
    while(p != NULL){
        p = p->next;
        len ++;
    }
    return len;
}

bool empty_linklist(LinkList list){
    return list == NULL;
}

bool contain_linklist(LinkList list,ElemType e){
    Node* p = list;
    while(p != NULL && p->data != e){
        p = p->next;
    }

    if(p == NULL)
        return false;
    return true;
}

Node* locate_linklist(LinkList list,int index){

    // 1. Verify Index
    // 2. Verify Capacity
    // 3. Execute
    int i = 0;
    Node* p = list;
    while(p != NULL && i<index)
        i++;
    // 4. Verify Return Value
    // should be in the range of [0,size - 1]
    // critical condition : index < 0  and p == NULL
    if(p == NULL && index < 0)
        return false;
    // 5. Return
    return p;
}

ElemType get_linklist(LinkList list,int index){
    // 1. Verify Index
    // 2. Verify Capacity
    // 3. Execute
    int i = 0;
    Node* p = list;
    while(p != NULL && i<index)
        i++;
    // 4. Verify Return Value
    // should be in the range of [0,size - 1]
    // critical condition : index < 0  and p == NULL
    if(p == NULL && index < 0)
        return false;
    // 5. Return
    return p->data;
}

Node* next_linklist(LinkList list,ElemType e){
    Node* p = list;
    while (p != NULL && list->data != e)
        p = p->next;
    if(p->next !=NULL)
        return p->next;
    return NULL;
}

Node* prior_linklist(LinkList list,ElemType e){
    Node* p = list;
    while (p != NULL &&p->next !=NULL && list->next->data != e)
        p = p->next;
    if(p->next != NULL)
        return p;
    return NULL;
}

bool insert_linklist(LinkList* list,int index,ElemType e){
    Node* p = *list;
    //处理头节点插入的情况
    if(index == 0){
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = e;
        *list = node;
        return true;
    }

    //寻找到插入节点的前一个节点
    int i = 0;
    while(i < index - 1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    //检查插入点合法性
    if(p == NULL || i< 0){
        return false;
    } else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = e;
        node->next = p->next;
        p->next = node;
    }
    return true;
}

bool remove_linklist(LinkList* list,int index){

    if(index == 0 && *list != NULL){
        Node* delNode = *list;
        *list = delNode->next;
        free(delNode);
        return true;
    }

    int i = 0;
    Node* p = *list;
    //找到前驱节点
    while(p != NULL && i < index - 1){
        Node* delNode = p->next;
        p->next = delNode->next;
        free(delNode);
        i++;

    }

    if(p == NULL || p->next == NULL || index < 0)
        return false;

    return true;

}



#endif //INC_2019SPRINGDSA_LINKEDLIST_H
