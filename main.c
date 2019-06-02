#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortAlgorithm/HeapSort.h"

int main() {
    srand(time(NULL));
    int arr[20];
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand() % 100;
    }

    for (int j = 0; j < 20; ++j) {
        printf("%d ",arr[j]);
    }
    printf("\n");
    HeapSort(arr,20);
    for (int j = 0; j < 20; ++j) {
        printf("%d ",arr[j]);
    }


    return 0;
}