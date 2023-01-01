//本题要求实现一个函数，求一组数的平均值、最大值。
#include <stdio.h>
#define N 5
float Fun(  int *p, int n,int *max);

int main()
{
    int a[10],i,max;
    int *pa=a;
    float ave;
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    ave=Fun(pa,N,&max);
    printf("max=%d,average=%.2f",max,ave);
    return 0;
}

/* 请在这里填写答案 */
float Fun(  int *p, int n,int *max){
    double sum=0;
    int *a=p;
    int m=*p;
    while(a<p+n){
        sum+=*a;
        if(*a>m){
            m=*a;
        }
        a++;
    }
    *max=m;
    double average=sum/n;
    return average;
}