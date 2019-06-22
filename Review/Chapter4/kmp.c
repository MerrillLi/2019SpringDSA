//
// Created by ÀèîÚêÍ on 2019-06-22.
//

#include "kmp.h"

void makeNext(char *pattern, int *next) {
    const int len = strlen(pattern);
    int i = 1;
    int j = 0;
    next[0] = 0;
    while (i-1<len){
        if(j == 0 || pattern[j] == pattern[i])
        {
            next[i] = j+1;
            i++;
            j++;

        }
        else
            j = next[j - 1];


    }

}
