/*
D字符串是动态分配内存的字符串，它也采用char数组来保存字符串中的字符，但是这个数组是在堆中动态分配得到的。

本题要求编写D字符串的创建函数。

函数接口定义：
char *dstr_create(const char *s);
dstr_create用输入的字符串s的内容创建一个新的字符串。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//    该函数由系统提供
char *dstr_readword();

char *dstr_create(const char *s);

int main()
{
    char *s = dstr_create("hello");
    printf("%lu-%s\n", strlen(s), s);
    free(s);
    char *t = dstr_readword();
    s = dstr_create(t);
    free(t);
    printf("%lu-%s\n", strlen(s), s);
    free(s);
}

/* 请在这里填写答案 */
char *dstr_create(const char *s){
    unsigned long len=0;
    while(*s!=0){
        len++;
        s++;
    }
    char *re=(char *)malloc(sizeof(int)+sizeof(int)*len);//为了防止空间不够，用sizeof(int)
    s-=len;//将s置回开头
    for(int i=0;i<len;i++){
        *re=*s;
        re++;
        s++;
    }
    re-=len;
    return re;
}