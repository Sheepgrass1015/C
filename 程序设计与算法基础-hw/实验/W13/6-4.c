/*
D字符串是动态分配内存的字符串，它也采用char数组来保存字符串中的字符，但是这个数组是在堆中动态分配得到的。

本题要求编写D字符串的连接函数。

函数接口定义：
char *dstr_add(char *s, char c);
char *dstr_concat(char *this, const char *that);
dstr_add在s的后面加上一个字符c，返回新的字符串。
dstr_concat在this后面加上字符串that，返回新的字符串。
这两个函数的第一个参数都必须是D字符串，不能是静态数组。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//    这两个函数由系统提供
char *dstr_readword();
char *dstr_create(const char *s);

char *dstr_add(char *s, char c);
char *dstr_concat(char *this, const char *that);

int main()
{
    char *s = dstr_create("hello");
    s = dstr_add(s, '!');
    printf("%lu-%s\n", strlen(s), s);
    char *t = dstr_readword();
    s = dstr_concat(s, t);
    free(t);
    printf("%lu-%s\n", strlen(s), s);
    free(s);
}

/* 请在这里填写答案 */
char *dstr_add(char *s, char c){
    int n=0;
    while(*s!=0){
        n++;
        s++;
    }
    s-=n;//先计算出长度，然后将s复原
    //实际上是重新创建一个长度为n+1的D字符串，然后把原字符串拷贝进去
    //最后再加一个ch
    //最好是把原来的free一下
    char *re=(char*)malloc(sizeof(int)+sizeof(int)*(n+1));
    for(int i=0;i<n;i++){
        *re=*s;
        re++;
        s++;
    }
    *re=c;
    re-=n;
    return re;
}
char *dstr_concat(char *this, const char *that){
    int len1=0;
    int len2=0;
    while(*this!=0){
        len1++;
        this++;
    }
    this-=len1;
    while(*that!=0){
        len2++;
        that++;
    }
    that-=len2;
    char *re=(char *)malloc(sizeof(int)+sizeof(int)*(len1+len2));
    for(int i=0;i<len1;i++){
        *re=*this;
        re++;
        this++;
    }
    for(int i=0;i<len2;i++){
        *re=*that;
        re++;
        that++;
    }
    re=re-len1-len2;
    return re;
}