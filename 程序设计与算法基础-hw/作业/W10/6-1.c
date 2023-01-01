/*
本题要求实现一个对数组进行循环右移的简单函数：一个数组a中存有n（>0）个整数，将每个整数循环向右移m（≥0）个位置
（最后m个数循环移至最前面的m个位置）。

函数接口定义：
void ArrayShift( int a[], int n, int m );
其中a[]是用户传入的数组；n是数组的大小；m是右移的位数。函数ArrayShift须将循环右移后的数组仍然存在a[]中。
*/

#include <stdio.h>
#define MAXN 10

void ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;
    
    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);
    
    ArrayShift(a, n, m);
    
    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}

/* 你的代码将被嵌在这里 */
//实际上有两种实现方法：1、每次移动一个，一共移动n次；2、一次性移动n个
//我选择的是第一种
void ArrayShift( int a[], int n, int m ){
    if(m==0){
        return ;
    }
    for(int i=0;i<m;i++){
        int temp=a[n-1];
        for(int j=n-1;j>=1;j--){
            a[j]=a[j-1];
        }
        a[0]=temp;
    }
}