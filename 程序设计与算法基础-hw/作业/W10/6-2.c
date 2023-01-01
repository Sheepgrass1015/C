/*
定义一个函数，求一组整数的最大值和最小值。

函数接口定义：
void fun( int *a,int n,int *max, int *min );
a是一个整数数组的起始地址，
n是数据的个数，
max是最大值变量的地址，
min是最小值变量的地址
*/
//这个程序就是指针运用的一个例子——有多个返回值的情况

#include <stdio.h>
void fun( int *a,int n,int *max,int *min);
int main()
{
int num[10],max,min,n=10,i;
for(i=0;i<n;i++)
scanf("%d", &num[i]);
fun(num,n,&max,&min);
 printf("max=%d,min=%d",max,min );
  return 0;
}

/* 请在这里填写答案 */
void fun( int *a,int n,int *max, int *min ){
    *max=*min=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<*min){
            *min=a[i];
        }
        if(a[i]>*max){
            *max=a[i];
        }
    }
}