/*
P字符串是另一种字符串实现形式。
它也采用char数组来保存字符串中的字符，但是最后一个字符后面没有结尾的'\0'。
它使用另一个int类型的变量来表示字符串中的字符的个数。
本题要求编写P字符串的比较函数。

函数接口定义：
int pstr_cmp(const char *s1, int len1, const char *s2, int len2);

pstr_cmp比较两个字符串的大小，如果两个字符串完全相同，则返回0；否则，返回第一个不相同的字符的差值（s1的那个字符减s2的那个字符的差）。
如果两个字符串的长度不同，但是短的字符串正好是长的字符串的开头的所有字符，则用长的字符串多余部分的第一个字符的值作为差值。如hell和hellA的差值是-65。
*/

#include <stdio.h>

const int SIZE = 80;

//    这两个函数由裁判程序提供
int pstr_scan(char* str, int size);
void pstr_print(const char* str, int length);

int pstr_cmp(const char *s1, int len1, const char *s2, int len2);

int main()
{
    char line[SIZE];
    char text[SIZE];
    
    int len1 = pstr_scan(line, SIZE);
    int len2 = pstr_scan(text, SIZE);

    printf("%d\n", pstr_cmp(line, len1, text, len2));
    
  return 0;
}

/* 请在这里填写答案 */
int pstr_cmp(const char *s1, int len1, const char *s2, int len2){
    int ret;
    int min;
    int i;
    int k;
    if(len1==len2){//len1等于len2，有两种可能：两个字符串完全相等；或者不完全相等——返回第一个不同字符的差值
        int flag=1;
        for(int i=0;i<len1;i++){
            if(s1[i]!=s2[i]){
                ret=s1[i]-s2[i];
                flag=0;
                break;
            }
        }
        if(flag==1){
            ret=0;
        }
    }else{//当len1不等于len2的时候，这个时候必须确定大小，因为对大小不同的字符串，操作和判断是不一样的
            //同样是两种情况：短字符串和长字符串的头部一样；不一样
        if(len1<len2){
            k=0;
            min=len1;
        }else{
            k=1;
            min=len2;
        }
        for(i=0;i<min;i++){
            if(s1[i]!=s2[i]){
                ret=s1[i]-s2[i];
                break;
            }
        }
        if(i==min&&k==0){
            //判断出循环的情况，如果没有判断出s1[i]!=s2[i]，则就是i=min后推出的
            ret=s2[min];
        }else if(i==min&&k==1){
            ret=s1[min];
        }
    }
    return ret;
}