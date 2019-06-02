//
// Created by 黎钰晖 on 2019-05-21.
//

#include "HeapSort.h"
#include "swap.h"

#define leftChild(x) 2*x+1
#define rightChild(x) 2*x+2
#define parent(x) x/2

void buildHeap(int *pInt, int i, int size);


void HeapSort(int *arr, int size);


//建立大顶堆
void buildHeap(int *arr, int index, int size) {
    /*
     * parent表示在这个堆中作为父节点的游标
     * child表示parent下的孩子，可能为左孩子也可能是右孩子
     */
    //记录初始状态下的parent值
    int parent = index;
    //迭代的循环，每次都首先定位到parent的左孩子
    for (int child = leftChild(parent); child < size; child = leftChild(parent)) {
        //如果有右节点，并且右节点的值更大，则选中右节点
        if (child + 1 < size && arr[child] < arr[child + 1]) {
            child++;
        }
        //如果孩子节点的值比父亲节点的值还要大
        //则交换两个节点，相当于把孩子节点上移
        //否则，则说明已经不必再往下交换，终止循环
        if (arr[parent] < arr[child]) {
            swap(&arr[parent],&arr[child]);
            parent = child;
        } else {
            break;
        }
    }
}

void HeapSort(int *arr, int size) {

    //构建大顶堆
    for (int i = size / 2 - 1; i >= 0; --i) {
        buildHeap(arr, i, size);
    }
    //每次抽取第一个元素与最后的元素交换
    for (int i = size - 1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        buildHeap(arr, 0, i);
    }

}


