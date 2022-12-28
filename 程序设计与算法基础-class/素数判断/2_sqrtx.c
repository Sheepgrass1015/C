#include <stdio.h>
#include <math.h>
int main(){
    int x;
    scanf("%d",&x);
    int isprime=1;
    if(x<2){
        isprime=0;
    }
    int m=sqrt(x);
    for(int i=2;i<m;i++){
        if(x%i==0){
            isprime=0;
            break;
        }
    }
    printf("isprime = %d\n",isprime);
}