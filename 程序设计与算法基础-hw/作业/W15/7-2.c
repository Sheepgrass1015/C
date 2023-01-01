/*
从输入中读取一个数n，求出n！中末尾0的个数。

输入格式:
输入有若干行。第一行上有一个整数m，指明接下来的数字的个数。然后是m行，每一行包含一个确定的正整数n，1<=n<=1000000000。

输出格式:
对输入行中的每一个数据n，输出一行，其内容是n！中末尾0的个数。
*/

#include <stdio.h>
#include <math.h>

int count(long long x);

int main(){
    int n;
    scanf("%d",&n);
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",count(a[i]));
    }
}
int count(long long x){
    int cnt=0;
    while(x>=5){
        int i=x/5;
        cnt+=i;
        x/=5;
    }
    return cnt;
}
//要做对这道题，最主要的是理解它背后的原理
//两个数相乘为什么会产生0？要么就是其中一个原本就是10的倍数
//另一种可能就是5*偶数，而在阶乘的情况中，其实偶数是比5多的多的
//所以现在的问题就是，n的阶乘中到底有多少个5相乘？
//那么我们就将遇到的每一个数都进行5的拆分，然后再将结果叠加，就得到答案了