//
// Created by 黎钰晖 on 2019-06-02.
//

#include "MergeSort.h"
#include "swap.h"
#include <stdlib.h>
#include <memory.h>

void merge_sort(int *arr, int start, int end) {

    //递归终止条件
    //如果区间只有一个元素，则本身就有序
    if (start == end)
        return;
        //如果区间有两个元素，则看情况交换两个数
    else if (start - end == 1) {
        if (arr[start] > arr[end])
            swap(&arr[start], &arr[end]);
        return;
    }

    //递归部分
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    //结束上面的递归后，出现了两个有序的数组
    //分别是[start,mid],[mid + 1,end]
    int *temp = (int *) malloc(sizeof(int) * (end - start + 1));
    int mergeIndex = 0, leftIndex = start, rightIndex = mid + 1;
    while (leftIndex <= mid && rightIndex <= end)
        temp[mergeIndex++] = arr[leftIndex] < arr[rightIndex] ? arr[leftIndex++] : arr[rightIndex++];
    while (leftIndex <= mid)
        temp[mergeIndex++] = arr[leftIndex++];
    while (rightIndex <= end)
        temp[mergeIndex++] = arr[rightIndex++];

    //复制归并的数组到原始的数组当中
    memcpy(&arr[start],temp,sizeof(int) * (end - start + 1));
}


void MergeSort(int *arr, int size) {
    merge_sort(arr, 0, size - 1);
}
