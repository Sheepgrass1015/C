#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100
int lomuto(int a[],int lo,int hi);
void swap(int *a,int *b);
void quicksort(int a[],int lo,int hi);
int slect_pivot(int a[],int lo,int hi);
int main(){
    clock_t start,stop;
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
    quicksort(a,0,n-1);
    stop=clock();
    printf("\nafter sort:\n");
    for(int i=0;i<n;i++){
        if((i+1)%10==0){
            printf("%4d\n",a[i]);
        }else{
            printf("%4d",a[i]);
        }
    }
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

int slect_pivot(int a[],int lo,int hi){
    int mi=lo+(hi-lo)/2;
    if((a[lo]-a[mi])*(a[lo]-a[hi])<0){
        return lo;
    }else if((a[mi]-a[lo])*(a[mi]-a[hi])<0){
        return mi;
    }else{
        return hi;
    }
}
//select_pivot的作用是取lo、hi、mi的中位数作为pivot
//这样保证了pivot既不会是最大数，也不会是最小数
//这使得排序的速度大大提高了
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int lomuto(int a[],int lo,int hi){
    int p=slect_pivot(a,hi,lo);
    if(p!=hi){
        swap(&a[p],&a[hi]);
    }
    int i=lo;
    int j=lo;
    for(;j<=hi;j++){
        if(a[j]<a[hi]){
            swap(&a[j],&a[i]);
            i++;
        }
    }
    swap(&a[i],&a[hi]);
    return i;
}
void quicksort(int a[],int lo,int hi){
    int p;
    if(hi-lo<1||lo<0){
        return ;
    }else{
        p=lomuto(a,lo,hi);
        quicksort(a,lo,p-1);
        quicksort(a,p+1,hi);
    }
}