//用来判断出栈顺序是否合法
/*
给定一个最大容量为 M 的堆栈，将 N 个数字按 1, 2, 3, ..., N 的顺序入栈，
允许按任何顺序出栈，则哪些数字序列是不可能得到的？
例如给定 M=5、N=7，
则我们有可能得到{ 1, 2, 3, 4, 5, 6, 7 }，
但不可能得到{ 3, 2, 1, 7, 5, 6, 4 }。输入第一行给出 3 个不超过 1000 的正整数：
M（堆栈最大容量）、N（入栈元素个数）、K（待检查的出栈序列个数）。
最后 K 行，每行给出 N 个数字的出栈序列。所有同行数字以空格间隔。
*/
#include <stdio.h>

int sort(int a[],int i,int l);//判断出栈顺序是否正确
int overflow(int x,int i,int cap);//判断是否溢出，即此处栈中能pop出x是否合理
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
        for(int q=0;q<n;q++){//其实可以改进，直接在函数里对a数组做判断，简洁一点
            if((sort(a,q,n)==0)||(overflow(a[q],q,m)==0)){
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
int sort(int a[],int i,int l){
    int flag=1;
    int x=a[i];
    for(int j=i+1;j<l;j++){//从第i个后面开始
        if(a[j]<x){
            for(int k=j+1;k<l;k++){
                if(a[k]<x && a[k]>a[j]){//如果有两个数，这两个数都比x小，但是它们不是递减排序的，就是不合法的
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
    if(x>cap+i) flag=0;//在第i个位置（i从0开始），出栈的数最大只能是cap+i
    return flag;
}