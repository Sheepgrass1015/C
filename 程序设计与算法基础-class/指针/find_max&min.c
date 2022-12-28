#include <stdio.h>
#define MAXN 10
void find(int a[], int len, int *pmax, int *pmin);
int main(){
    int i, len, min, max;
    int a[]={23,6,83,89,2,9,1,29,0};
    len=sizeof(a)/sizeof(a[0]);
    find(a,len,&max,&min);
    printf("%d %d\n", max, min);
    return 0;
}
void find(int a[], int len, int *pmax, int *pmin){
    int i;
    *pmax = *pmin = a[0];
    for (i = 1; i < len; i++) {
        if(a[i]<*pmin)
        *pmin=a[i];
        if(a[i]>*pmax)
        *pmax=a[i];
    }
}