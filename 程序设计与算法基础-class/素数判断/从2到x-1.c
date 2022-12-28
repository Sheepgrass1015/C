#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    int isprime=1;
    if(x<2){
        isprime=0;
    }
    for(int i=2;i<x;i++){
        if(x%i==0){
            isprime=0;
            break;
        }
    }
    printf("isprime = %d\n",isprime);
}