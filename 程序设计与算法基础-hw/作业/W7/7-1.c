/*
本题目要求读入1个正整数n，然后编写递归函数reverse(int n)实现将该正整数逆序输出。
*/
#include <stdio.h>
void reverse(int n);
int main(){
    int n;
    scanf("%d",&n);
    reverse(n);
    printf("\n");
    return 0;
}
void reverse(int n){
    if(n<10){
        printf("%d",n);
    }else{
        printf("%d",n%10);
        reverse(n/10);//永远假设已经可以做到
    }
}