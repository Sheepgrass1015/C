/*
P字符串是另一种字符串实现形式。
它也采用char数组来保存字符串中的字符，但是最后一个字符后面没有结尾的'\0'。
它使用另一个int类型的变量来表示字符串中的字符的个数。

本题要求编写P字符串的复制和连接函数。

函数接口定义：
int pstr_cpy(char *s1, int len1, int size, const char *s2, int len2);
int pstr_cat(char *s1, int len1, int size, const char *s2, int len2);
pstr_cpy将s2字符串的内容复制到s1字符串，返回新的s1的长度。
pstr_cat将s2字符串的内容连接到s1字符串的后面，返回新的s1的长度。
参数中，size是s1的数组长度。
*/
#include <stdio.h>

const int SIZE = 80;

//    这两个函数由裁判程序提供
int pstr_scan(char* str, int size);
void pstr_print(const char* str, int length);

int pstr_cpy(char *s1, int len1, int size, const char *s2, int len2);
int pstr_cat(char *s1, int len1, int size, const char *s2, int len2);

int main()
{
    char line[SIZE];
    char text[SIZE/2];
    
    int len1 = pstr_scan(line, SIZE);
    int len2 = pstr_scan(text, SIZE/2);

    len1 = pstr_cat(line, len1, SIZE, "\x0D\x0A", 2);
    len1 = pstr_cat(line, len1, SIZE, text, len2);
    len2 = pstr_cpy(text, len2, SIZE/2, line, len1);
    
    pstr_print(line, len1);
    pstr_print(text, len2);
    
  return 0;
}

/* 请在这里填写答案 */
int pstr_cpy(char *s1, int len1, int size, const char *s2, int len2){
    int ret;
    for(int i=0;i<size;i++){
        s1[i]=0;
    }
    if(len2<=size){//对于长度的判断尤其严格，因为一不小心就会超长度
        ret=len2;
        for(int i=0;i<len2;i++){
            s1[i]=s2[i];
        }
    }else{
        ret=size;
        for(int i=0;i<size;i++){
            s1[i]=s2[i];
        }
    }
    return ret;
}
int pstr_cat(char *s1, int len1, int size, const char *s2, int len2){
    int len=len1+len2;
    if(len<=size){
        for(int i=0;i<len2;i++){
            s1[len1+i]=s2[i];
        }
    }else{
        len=size;
        for(int i=0;i<size-len1;i++){
            s1[len1+i]=s2[i];
        }
    }
    return len;
}