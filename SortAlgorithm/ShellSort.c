//
// Created by 黎钰晖 on 2019-06-02.
//

#include "ShellSort.h"

void ShellSort(int *arr, int size) {

    //缩小增量取[len / 2, len / 2 / 2, ... 1]
    for (int delta = size / 2; delta >= 1; delta = delta / 2) {

        //对增量序列进行插入排序
        //处理[delta ,size]为开头的组,他们都可以成为插入排序组中的非开头的元素
        for (int i = delta; i < size; ++i) {

            //插入排序的移动部分
            int j = i;
            int val = arr[j];
            while (j - delta >= 0 && arr[j - delta] > val) {
                arr[j] = arr[j - delta];
                j -= delta;
            }
            arr[j] = val;

        }
    }

}
