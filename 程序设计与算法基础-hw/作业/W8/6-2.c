/*
本题要求使用选择法排序，将给定的n个整数从小到大排序后输出，并输出排序过程中每一步的中间结果。
*/
#include <stdio.h>
int min(int a[],int begin,int n);
int main(){
    int n,temp,k;
    int a[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d\n",a[0]);
    }
    else{
        for(int i=0;i<n-1;i++){
            k=min(a,i,n);
            temp=a[k];
            a[k]=a[i];
            a[i]=temp;
            for(int j=0;j<n;j++){
                if(j==0){
                    printf("%d",a[j]);
                }else{
                    printf(" %d",a[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

//写一个查找min的函数 ，方便在main里使用
int min(int a[],int begin,int n){
    int min=a[begin];
    int ret=begin;
    for(int i=begin;i<n;i++){
        if(a[i]<min){
            min=a[i];
            ret=i;
        }
    }
    return ret;
}