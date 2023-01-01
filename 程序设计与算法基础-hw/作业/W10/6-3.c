/*
定义函数，求一组数据中出现次数最多的数据（题目测试数据确保其唯一）

函数接口定义：
int  fun( int a[],int n );
a 是存储数据的数组，n是数组大小.(n<=10)
*/

#include <stdio.h>

int  fun( int a[],int n );
int main()
{
int a[10],i,n;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
printf("%d",fun(a,n));
  return 0;

}

/* 请在这里填写答案 */

int  fun( int a[],int n ){
    int cnt[n];
    for(int i=0;i<n;i++){
        cnt[i]=0;
    }
    int flag=1;
    for(int i=0;i<n;i++){
        if(i==1){
            cnt[1]++;
        }
        for(int j=0;j<i-1;j++){
            if(a[j]==a[i]){
                flag=0;
                cnt[i]++;
            }
            if(flag==1){
                cnt[i]++;
            }
        }
    }
    int max=cnt[0];
    int x=0;
    for(int i=0;i<n;i++){
        if(cnt[i]>max){
            max=cnt[i];
            x=i;
        }
    }
    return a[x];
}