//
// Created by ÀèîÚêÍ on 2019-03-05.
//

#include <stdbool.h>
#include "BinarySearch.h"

int BinarySearchRecursive(int *arr, int element, int low, int high) {

    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == element)
        return mid;
    else if(element < arr[mid])
        //×ó°ëÇøÓò²éÕÒ,[low,mid - 1]
        return BinarySearchRecursive(arr,element,low,mid - 1);
    else if(element > arr[mid])
        //ÓÒ°ëÇøÓò²éÕÒ,[mid + 1,high]
        return BinarySearchRecursive(arr,element,mid + 1,high);

}


int BinarySearchLoop(int *arr, int data, int low, int high) {
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == data) return mid;
            //ÔÚ×ó°ëÇøÓò²éÕÒ,[low,mid - 1]
        else if(data < arr[mid]) high = mid - 1;
            //ÔÚÓÒ°ëÇøÓò²éÕÒ,[mid + 1,high]
        else if(data > arr[mid]) low = mid + 1;
    }
    return -1;
}
