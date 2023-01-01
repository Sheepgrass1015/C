/*
本题要求使用冒泡法排序，将给定的n个整数从小到大排序后输出，并输出排序过程中每一步的中间结果。
*/
#include <stdio.h>
int main(){
    int n,i,j,temp;
    int a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d\n",a[0]);//这其实是根据提交结果加上的特判
        goto here;
    }
    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        for(int k=0;k<n;k++){
            if(k==0){
                printf("%d",a[k]);
            }else{
                printf(" %d",a[k]);
            }
        }
        printf("\n");
    }
    here:
    return 0;
}