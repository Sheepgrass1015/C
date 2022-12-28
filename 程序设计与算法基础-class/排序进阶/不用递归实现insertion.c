#include <stdio.h>
#include <stdlib.h>

void insertion(int a[],int n);

int main(){
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i]=rand()%100;
        insertion(arr,i);
        //为什么不是i+1？
    }

    for(int i=0;i<100;i++){
        if((i+1)%10==1){
            printf("%d",arr[i]);
        }else if((i+1)%10==0){
            printf("%4d\n",arr[i]);
        }else{
            printf("%4d",arr[i]);
        }
    }
    printf("\n");
}
void insertion(int a[],int n){
    int x;
    x=a[n];
    int j;
    if(n==1){
        return;
    }
    for(j=n-2;j>=0;j--){
        if(a[j]>a[n]){
            a[j+1]=a[j];
        }else{
            break;
        }
    }
    a[j+1]=x;
}