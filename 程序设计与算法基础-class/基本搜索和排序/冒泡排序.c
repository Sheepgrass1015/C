#include <stdio.h>
void sort(int a[],int n);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(int i=0;i<n;i++){
    printf("%4d",a[i]);
    }
}
void sort(int a[],int n){
    int temp;
    //冒泡排序一般是冒n-1次，外循环代表的是冒泡次数
    //然后j是在改变的，如果是选小的就从前往后
    //选大的就从后往前
    for(int i=1;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(a[j-1]>a[j]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}