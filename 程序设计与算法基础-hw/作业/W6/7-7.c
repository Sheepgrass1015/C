/*
给定一个最大容量为 M 的堆栈，将 N 个数字按 1, 2, 3, ..., N 的顺序入栈，允许按任何顺序出栈，则哪些数字序列是不可能得到的？
例如给定 M=5、N=7，则我们有可能得到{ 1, 2, 3, 4, 5, 6, 7 }，但不可能得到{ 3, 2, 1, 7, 5, 6, 4 }。

输入格式：
输入第一行给出 3 个不超过 1000 的正整数：M（堆栈最大容量）、N（入栈元素个数）、K（待检查的出栈序列个数）。
最后 K 行，每行给出 N 个数字的出栈序列。所有同行数字以空格间隔。

输出格式：
对每一行出栈序列，如果其的确是有可能得到的合法序列，就在一行中输出YES，否则输出NO。
*/
#include <stdio.h>
int sort(int a[],int x,int i,int l);
int overflow(int x,int i,int cap);
int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    int a[n];
    int flag;
    for(int p=0;p<k;p++){
        flag=1;
        for(int q=0;q<n;q++){
            scanf("%d",&a[q]);
        }
        for(int q=0;q<n;q++){
            if((sort(a,a[q],q,n)==0)||(overflow(a[q],q,m)==0)){
                flag=0;
                break;
            }
        }
        if(flag==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
int sort(int a[],int x,int i,int l){
    int flag=1;
    for(int j=i+1;j<l-1;j++){
        if(a[j]<x){
            for(int k=j+1;k<l;k++){
                if((x>a[k])&&(a[k]>a[j])){
                    flag=0;
                    goto here;
                }
            }
        }
    }
    here:
    return flag;
}
int overflow(int x,int i,int cap){
    int flag=1;
    if(x-i>cap){
        flag=0;
    }
    return flag;
}