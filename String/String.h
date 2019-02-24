//
// Created by 黎钰晖 on 2019-02-23.
//

#ifndef INC_2019SPRINGDSA_STRING_H
#define INC_2019SPRINGDSA_STRING_H

#include <stdlib.h>
#include <memory.h>

typedef struct __string
{
    char* str;
    int len;
    int free;
}*string;

//内部API,求字符串长度
int internalStrlen(char* str)
{
    int len = 0;
    char* p = str;
    while(p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

//从指定的char*初始化字符串
string InitString(char* str)
{
    string newStr = (string)malloc(sizeof(struct __string));
    int _len = internalStrlen(str);
    memcpy(newStr->str,str, (_len + 1)* sizeof(char));
    newStr->str[_len] = '\0';
    newStr->len = _len;
    newStr->free = 0;
    return newStr;
}

//指定容量的字符串
string InitStringBySize(char* str,int capacity)
{
    string newStr = (string)malloc(sizeof(struct __string));
    int _len = internalStrlen(str);
    //复制指定长度的字符串
    memcpy(newStr->str,str, capacity* sizeof(char));
    newStr->len = _len;
    newStr->free = capacity - _len;
    return newStr;
}

//追加字符串
string StrAppend(string source,string append)
{

}

//求字符串长度的函数
int StrLength(string str)
{
    return str->len;
}


#endif //INC_2019SPRINGDSA_STRING_H
