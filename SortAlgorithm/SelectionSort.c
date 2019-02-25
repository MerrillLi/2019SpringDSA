//
// Created by 黎钰晖 on 2019-02-25.
//

#include "SelectionSort.h"

void InsertionSort(int arr[], int size) {
    //从数组的最后开始，升序排列
    int index = size - 1;
    //保证对每一个元素都进行了操作
    for (int i = 0; i < size; ++i) {
        int maxIndex = 0;
        //查找最大的元素
        for (int j = 0; j < size - i; ++j) {
            if(arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        //交换写入位置和最大元素两个元素的位置
        int t = arr[index];
        arr[index] = arr[maxIndex];
        arr[maxIndex] = t;
        index --;
    }
}
