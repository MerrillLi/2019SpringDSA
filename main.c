#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortAlgorithm/HeapSort.h"
#include "SortAlgorithm/InsertionSort.h"
#include "SortAlgorithm/ShellSort.h"
#include "SortAlgorithm/MergeSort.h"
#include "SearchAlgorithm/Insertion/InsertionSearch.h"

int main() {
    srand(time(NULL));
    int arr[20];
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand() % 100;
    }
    MergeSort(arr,20);

    for (int j = 0; j < 20; ++j) {
        printf("%d ",arr[j]);
    }
    printf("\n");

    for (int j = 0; j < 20; ++j) {
        printf("%d ",j);
    }
    printf("\n");
    int search;
    scanf("%d",&search);
    int index = InsertionSearch(arr,20,search);
    printf("\nIndex = %d",index);


    return 0;
}