#include <stdio.h>

void insertion(int a[],int len);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertion(a,n);
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
}



void insertion(int a[],int len){
    int i,j;
    for(i=1;i<len;i++){
        int store=a[i];
        for(j=i-1;j>=0;j--){
            if(a[j]>store){
                a[j+1]=a[j];
                //边检查边后移，这样的话就免去一次后移的循环了
            }else{
                break;
            }
        }
        a[j+1]=store;
    }
}
