#include <stdio.h>

int main(){
    int number;
    scanf("%d",&number);
    unsigned mask=1u<<31;//1u说明mask是unsigned类型，否则移位结果不同
    for(;mask;mask>>=1){
        printf("%d",number&mask? 1:0);
    }
    printf("\n");
}