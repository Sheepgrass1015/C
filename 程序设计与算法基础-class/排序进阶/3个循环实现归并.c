#include <stdio.h>
void merge(int a[],int b[],int alen,int blen,int c[]);
int main(){
    int a[5]={1,3,5,7,9};
    int b[5]={2,4,6,8,10};
    int c[10];
    merge(a,b,5,5,c);
    for(int i=0;i<10;i++){
        printf("%d\n",c[i]);
    }
    
}
void merge(int a[],int b[],int alen,int blen,int c[]){
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while(i<alen&&j<blen){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;
            i++;
        }else{
            c[k]=b[j];
            k++;
            j++;
        }
    }
    if(i==alen){
        for(;j<blen;j++){
            c[k]=b[j];
            k++;
        }
    }
    if(j==blen){
        for(;i<alen;i++){
            c[k]=a[i];
            k++;
        }
    }
}