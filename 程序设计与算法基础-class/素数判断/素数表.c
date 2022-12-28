/*
已知所有的偶数都不是素数
如果一个数能够被3整除，那么一定能被3的倍数整除
所以，不需要判断[2,√x]的数能否整除，只需要判断[2,x)之间所有的素数能否整除
这种方式适合构建n以内的素数表，不适合判断单个自然数是否是素数
*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int prime[n];//素数表的前n个数
    int nprime=0;//记录现在已经有多少个素数
    for(int x=2;nprime<n;x++){
        int isprime=1;
        for(int i=0;i<nprime;i++){
            if(x%prime[i]==0){
                isprime=0;
                break;
            }
        }
        if(isprime==1){
            prime[nprime]=x;
            nprime++;
        }
    }
    for(int i=0;i<n;i++){
        printf("prime[%d] = %d\n",i+1,prime[i]);
    }
}