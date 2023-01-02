/*
输入两个数n和m，n为需要排序的数的个数，m为冒泡排序的轮数。一轮是指一次完整冒泡过程。
然后，输入一组不超过10个的整数，用冒泡排序法从大到小的排序，根据m输出第m轮冒泡后的中间结果。

函数接口定义：
void sort(int a[],int n,int m)；
其中 数组a 、整数n 和整数m
都是用户传入的参数。 a 存储了未排序的n个数，m为排序的轮数。函数实现冒泡排序输出中间排序结果。
*/
#include <stdio.h>
#define N 10
void sort(int a[],int n,int m);
int  main( )
{    
int a[N],n,m,i;
scanf("%d%d",&n,&m);
sort(a,n,m);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
printf("\n");
return 0;
}

/* 请在这里填写答案 */
void sort(int a[],int n,int m){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int temp;
    for(int i=0;i<m;i++){//其实也就是固定了循环次数
        for(int j=n-1;j>=i+1;j--){
            if(a[j-1]<a[j]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}