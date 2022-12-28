#include <stdio.h>

void sort ( int a[], int len );

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for ( int i=0; i<n; i++ ) {
        scanf("%d", &a[i]);
    }
    
    sort(a, n);

    for ( int i=0; i<n; i++ ) {
        printf("%d\n", a[i]);
    }
}

void sort ( int a[], int len ){
    int i,j,temp,p,pivot;
    int x;
    if(len<=1){
        return;
    }else{
        i=0;
        p=(len-1)/2;
        pivot=a[p];
        for(j=0;j<len;j++){
            if(a[j]<pivot){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i++;
            }
        }
        x=i;
        }
        if(x>1){
            sort(a,x);
        }
        if(len-x>1){
            sort(a+x,len-x);
    }
}
