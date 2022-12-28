/*
埃拉托斯特尼筛法，简称埃氏筛或爱氏筛，是一种由希腊数学家埃拉托斯特尼所提出的一种简单检定素数的算法。
要得到自然数n以内的全部素数，必须把不大于根号n的所有素数的倍数剔除，剩下的就是素数。
给出要筛数值的范围n，找出以内的素数。
先用2去筛，即把2留下，把2的倍数剔除掉；再用下一个质数，也就是3筛，把3留下，把3的倍数剔除掉；
接下去用下一个质数5筛，把5留下，把5的倍数剔除掉；不断重复下去......。
*/
#include <stdio.h>
#include <math.h>

int list(int a[],int n);//创建2~√n的素数表

int main(){
    int n;
    scanf("%d",&n);
    int nprime=0;
    int a[n];
    int len=list(a,n);
    int flag[n];
    for(int i=0;i<n;i++){
        flag[i]=1;
    }
    int cnt=0;
    for(int i=0;i<len;i++){
        int t=a[i];
        for(int x=t+1;x<=n;x++){
            if(x%t==0){
                flag[x-1]=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(flag[i]==1){
            printf("%d\n",i+1);
        }
    }
}

int list(int a[],int n){
    int nprime=0;
    for(int x=2;x<=sqrt(n);x++){
        int isprime=1;
        for(int i=0;i<nprime;i++){
            if(x%a[i]==0){
                isprime=0;
                break;
            }
        }
        if(isprime==1){
            a[nprime]=x;
            nprime++;
        }
    }
    return nprime;
}