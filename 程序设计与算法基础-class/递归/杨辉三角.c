#include <stdio.h>
int y(int m,int n);
int main(){
    int n;
    scanf("%d",&n);
    int k=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            printf("%d  ",y(i,j));
        }
        printf("\n");
        k++;
    }
}
int y(int m,int n){
    if(m==1||m==0||n==0||m==n) return 1;
    return y(m-1,n)+y(m-1,n-1);
}