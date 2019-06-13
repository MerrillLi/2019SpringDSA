//
// Created by ÀèîÚêÍ on 2019-06-04.
//

#include "InsertionSearch.h"

int InsertionSearch(int *arr,int size, int key) {

    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + ((key - arr[low]) / (arr[high] - arr[low])) * (high - low);
        if (arr[mid] < key) {
            low = mid + 1;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            return low;
        }
    }
    return -1;
}
