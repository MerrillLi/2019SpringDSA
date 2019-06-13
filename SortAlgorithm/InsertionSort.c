//
// Created by 黎钰晖 on 2019-06-02.
//

#include "InsertionSort.h"

void InsertionSort(int *arr, int size) {
    //遍历[1,size-1]区间
    for (int i = 1; i < size; ++i) {
        //[0,i-1]区间是有序的,从i-1开始进行比较
        int val = arr[i];
        int j = i - 1;
        //当遇到比val小的那个的时候，退出循环
        while (j >=0 && arr[j] > val) {
            arr[j + 1] = arr[j];

            j--;
        }
        //此时，j指向的就是那个比val小的数，[0,j]是有序的，需要填充的是j+1所在的空位
        arr[j + 1] = val;

    }
}
