//
// Created by 黎钰晖 on 2019-02-25.
//
#include "MergeSort.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//将长度为n的数组逆序
void reverse(int *arr, int n)
{
    int i = 0,j = n - 1;
    while(i < j)
    {
        swap(&arr[i], &arr[j]);
        i ++;
        j --;
    }
}

//将数组向左循环移位i个位置
void exchange(int *arr, int n, int i)
{
    reverse(arr, i);
    reverse(arr + i, n - i);
    reverse(arr, n);
}

//原地合并两个数组
void inplace_Merge(int* arr, int l, int mid, int r)
{
    int i = l, j = mid, k = r;
    // J in [l,r], j = (l + r) / 2, j closer to r, it can be equal to r
    while(i < j && j <= r)
    {
        int step = 0;
        while(i < j && arr[i] <= arr[j])
            ++ i;
        while(j <= k && arr[j] <= arr[i])
        {
            ++ j;
            ++ step;
        }
        exchange(arr + i, j - i, j - i - step);
        i = i + step;
    }
}

//原地归并排序指定区间
void inplace_MergeSortSection(int* arr,int l,int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    inplace_MergeSortSection(arr, l, mid);
    inplace_MergeSortSection(arr, mid + 1, r);
    inplace_Merge(arr, l, mid + 1, r);
}

//原地归并排序算法
void inplace_mergesort(int* arr,int size)
{
    inplace_MergeSortSection(arr, 0, size - 1);
}

//额外空间的合并算法
void extraspace_merge(int *arr,int l, int mid, int r)
{
    //[l,r]区间上的归并
    //分为[l,mid]&[mid+1,r]
    int leftIndex = l;
    int rightIndex = mid + 1;
    int arrIndex = 0;
    int* newarr = (int*)malloc(sizeof(int) * (r - l + 1));
    while(leftIndex <= mid && rightIndex <= r)
    {
        newarr[arrIndex++] = arr[leftIndex] < arr[rightIndex] ? arr[leftIndex++] : arr[rightIndex++];
    }

    while(leftIndex <= mid)
        newarr[arrIndex++] = arr[leftIndex++];
    while(rightIndex <= r)
        newarr[arrIndex++] = arr[rightIndex++];

    for (int i = l, t = 0; i <=r ; ++i, ++t) {
        arr[i] = newarr[t];
    }

}

//额外空间的区间归并排序算法
void mergesort_section(int* arr, int l, int r)
{
    if( l >= r) return;
    int mid = (l + r) / 2;
    mergesort_section(arr, l, mid);
    mergesort_section(arr, mid + 1, r);
    extraspace_merge(arr, l, mid, r);
}

//额外空间的归并排序算法
void merge_sort(int *arr, int size) {
    mergesort_section(arr, 0, size - 1);
}
