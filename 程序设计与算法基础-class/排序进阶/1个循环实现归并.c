#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int b[],int lo,int hi,int mi);
void p(int a[],int n);
int main(){
    int n=13;
    int a[n];
    for(int k=0;k<n;k++){
        a[k]=rand()%100;
    }
    int b[n];
    p(a,n);

    int i=2;
    int j=0;
    for(;i<n;i*=2){
        for(j=0;j<n;j+=i){
            if(j+i<n){
                merge(a,b,j,j+i-1,(j+j+i-1)/2);
            }else{
                merge(a,b,j,n-1,(j+n-1)/2);
            }
        }
       //p(b,n); 
       for(int k=0;k<n;k++){
        a[k]=b[k];
       }
    }
//又i<n得，推出循环时i>=n，所以要/2
//最后一次是特殊的，这个时候要将前i/2个和后面的n-i/2个归并
    merge(a,b,0,n-1,i/2-1);
    p(b,n);
}
void merge(int a[],int b[],int lo,int hi,int mi){
    int i=lo;
    int j=mi+1;
    int k=lo;
    for(;k<=hi;k++){
        if((i<=mi)&&(j>hi||a[i]<a[j])){
            b[k]=a[i];
            i++;
        }else{
            b[k]=a[j];
            j++;
        }
    }
}
void p(int a[],int n){
    for(int k=0;k<n;k++){
        if(k==0){
            printf("%d",a[k]);
        }else{
            printf("%4d",a[k]);
        }
    }
    printf("\n");
}