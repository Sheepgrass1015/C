#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
int hoare(int a[],int lo,int hi);
void quicksort(int a[],int lo,int hi);
void swap(int *a,int *b);
int main(){
    time_t start ,stop;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
        //printf("%4d",a[i]);
    }
    for(int i=0;i<n;i++){
        if((i+1)%10==0){
            printf("%4d\n",a[i]);
        }else{
            printf("%4d",a[i]);
        }
    }
    start=clock();
    quicksort(a,1,n-2);
    stop=clock();
    printf("\nafter sort:\n");
    int flag=1;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            flag=0;
        }
    }
    if(flag==1){
        printf("yes time=%fms\n",difftime(stop,start));
    }else{
        printf("no/n");
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int hoare(int a[],int lo,int hi){
    int pivot=a[lo+(hi-lo)/2];
    int i=lo-1;
    int j=hi+1;
    int temp;
    while(i<j){
        while(a[i]<pivot&&i<j){
            i++;
        }
        while(a[j]>pivot&&i<j){
            j--;
        }
        swap(&a[i],&a[j]);
        i++;
        j--;
    }
    return j;
}
void quicksort(int a[],int lo,int hi){
    if(lo>=hi){
        return;
    }
    int p=hoare(a,lo,hi);
    quicksort(a,lo,p);
    quicksort(a,p+1,hi);
}