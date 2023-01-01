/*
大一新生LinYX 最近学了一个新的算法—递归，他发现这个算法可以解决一些高中的数列问题，
如果已知f1以及公式fn=a*fn-1+b，求fn很方便。聪明的你也应该已经学会了递归，那就来表现一下吧。

输入格式:
输入包含若干行数据，每行都有4个整数，n，f1,a，b。

输出格式:
输出fn 。每组测试数据显示在不同行。
*/
#include <stdio.h>
int a[1000][4];
int fn(int m,int n,int p,int q);
int main(){
    int cnt=0;
    int t;
    while(1){
        t=scanf("%d %d %d %d",&a[cnt][0],&a[cnt][1],&a[cnt][2],&a[cnt][3]);
        if(t!=4){
            break;
        }else{
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++){
        printf("%d\n",fn(a[i][0],a[i][1],a[i][2],a[i][3]));
    }
    return 0;
}
int fn(int m,int n,int p,int q){
    if(m==1){
        return n;
    }else{
        return p*fn(m-1,n,p,q)+q;//其实就是从f(n-1)推f(n)
    }
}