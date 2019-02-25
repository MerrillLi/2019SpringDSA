//
// Created by 黎钰晖 on 2019-02-25.
//

#include "LinkedQueue.h"

ElementType LinkedQueueDequeue(LinkedQueue queue, ElementType data) {
    //出队尾排法
    QueueNode* prevNode = queue->tail->prev;
    QueueNode* delNode = queue->tail;

    //调整前一节点的next指针
    prevNode->next = NULL;

    //调整记录的尾节点
    queue->tail = prevNode;

    //释放内存占用
    free(delNode);

}

LinkedQueue InitLinkedQueue() {
    LinkedQueue linkedQueue = (LinkedQueue)malloc(sizeof(struct __QueueNode));
    linkedQueue->head = internalCreateQueueNode(NULL);
    linkedQueue->tail = linkedQueue->head;
    linkedQueue->head->next = linkedQueue->head;
    linkedQueue->head->prev = linkedQueue->head;
    linkedQueue->size = 0;
    return linkedQueue;
}

QueueNode *internalCreateQueueNode(ElementType data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(struct __QueueNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void LinkedQueueEnqueue(LinkedQueue queue, ElementType data) {
    //入队头插法,非循环形式
    QueueNode* node = internalCreateQueueNode(data);
    //加入头节点的下一个
    queue->head->next = node;
    //node的设置
    node->next = NULL;
    node->prev = queue->head;
    //如果队列没有跟踪过尾节点,就记录尾节点
    if(queue->tail == queue->head)
    {
        queue->tail == node;
    }
    queue->size ++;

}
