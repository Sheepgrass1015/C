#include <stdio.h>

int Power(int, int);

const int MOD = 10007;
int main()
{
    int N, k;
    scanf("%d%d", &N, &k);
    printf("%d\n", Power(N, k));        
    return 0;
}

/* Your function will be put here */
int Power(int N, int k){
    int re;
    if(N>MOD){
        N=N%MOD;//如果N一开始就很大，直接带入就超出范围了
    }
    if(k==0){
        return 1;
    }
    if(k%2==0){
        re=Power(N,k/2)%MOD;//可以发现，不管是先mod再乘幂还是先乘幂再mod，结果都是一样的
        return re*re%MOD;//10007真是个神奇的数字
    }else{
        return N*Power(N,k-1)%MOD;
    }
}

/*
The function Power calculates the exponential function N,k. 
But since the exponential function grows rapidly, you are supposed to return (N,k)%10007 instead.
Both N and k are integers, which are no more than 2147483647.
*/