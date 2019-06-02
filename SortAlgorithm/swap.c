//
// Created by ÀèîÚêÍ on 2019-06-02.
//

#include "swap.h"

void swap(int* a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}