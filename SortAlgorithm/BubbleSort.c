//
// Created by ÀèîÚêÍ on 2019-02-25.
//

#include "BubbleSort.h"


void BubbleSort(int* arr,int size)
{
    for (int i = 0; i <size - 1 ; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if(arr[j] < arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}