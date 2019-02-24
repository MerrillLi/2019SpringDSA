//
// Created by ¿ËÓ⁄ÍÕ on 2019-02-24.
//

#ifndef INC_2019SPRINGDSA_SEGMENTTREE_H
#define INC_2019SPRINGDSA_SEGMENTTREE_H

#include <stdlib.h>
#include <assert.h>

#define ElementType void*
typedef struct __SegmentTree
{
    ElementType* data;
    ElementType* tree;
    int size;
}*SegmentTree;

SegmentTree InitSegmentTree(ElementType* data, int length)
{
    SegmentTree segmentTree = (SegmentTree)malloc(sizeof(struct __SegmentTree));
    segmentTree->data = (ElementType*)malloc(sizeof(ElementType) * length);
    for (int i = 0; i < length; ++i) {
        segmentTree->data[i] = data[i];
    }
    segmentTree->tree = (ElementType*)malloc(sizeof(ElementType*) * 4 * length);
    return segmentTree;

}

int SegmentTreeSize(SegmentTree segmentTree)
{
    return segmentTree->size;
}

void segRangeCheck(SegmentTree tree,int index)
{
    assert(!(index < 0 || index >= tree->size));
}

ElementType SegmentTreeGet(SegmentTree segmentTree,int index)
{
    segRangeCheck(segmentTree,index);
    return segmentTree->data[index];
}

int leftChild(SegmentTree segmentTree,int index)
{
    return 2 * index + 1;
}

int rightChild(SegmentTree segmentTree,int index)
{
    return 2 * index + 2;
}

void BuildSegmentTree(SegmentTree segmentTree,int treeIndex,int left,int right)
{

}





#endif //INC_2019SPRINGDSA_SEGMENTTREE_H
