/*
P字符串是另一种字符串实现形式。
它也采用char数组来保存字符串中的字符，但是最后一个字符后面没有结尾的'\0'。
它使用另一个int类型的变量来表示字符串中的字符的个数。

本题要求编写P字符串的输入输出函数，能从标准输入读入一个以空格结尾的单词，填入一个P字符串，能将一个P字符串输出到标准输出。

函数接口定义：
int pstr_scan(char* str, int size);
void pstr_print(const char* str, int length);

pstr_scan要从标准输入读入一个字符串，读到空格类字符为止。空格类字符包括空格、Tab和回车换行。
str是要填的P字符串数组，size是这个数组的大小。函数返回读到的字符串的长度。

pstr_print要将一个字符串输出到标准输出。
str是要输出的字符串，length是字符串的长度（字符串中的字符个数）。
*/

//其实思考一下，一个p字符串包含一个char *类型与一个大小，那么可不可以用结构的方式实现呢？

#include <stdio.h>

const int SIZE = 80;

int pstr_scan(char* str, int size);
void pstr_print(const char* str, int length);

int main()
{
    char line[SIZE];

    int length = pstr_scan(line, SIZE);
    pstr_print(line, length);
    
  return 0;
}

/* 请在这里填写答案 */
int pstr_scan(char* str, int size){
    char ch;
    int cnt=0;
    while(1){
        ch=getchar();//要一个个读入，可以使用getchar，当然用scanf也是可以的
        if(ch==32||ch==9||ch==10){
            break;
        }else if(cnt==SIZE){
            str[cnt-1]=ch;//因为没有\0，所以可以填满
            break;
        }else{
            str[cnt]=ch;
            cnt++;
        }
    }
    return cnt;
}
void pstr_print(const char* str, int length){
    for(int i=0;i<length;i++){
        putchar(str[i]);
    }
}
