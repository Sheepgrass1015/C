#include <stdio.h>
int f(int n);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
}
int f(int n){
    if(n==0){
        return 1;
    }else{
        return n*f(n-1);
    }
}