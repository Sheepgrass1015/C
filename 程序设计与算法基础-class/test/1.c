#include <stdio.h>
#include <math.h>

int main(){
    float a,b,c;
    a=1.345f;
    b=1.123f;
    c=a+b;
    if(fabs(c-2.468)<1e-12){
        printf("相等\n");
    }else{
        printf("不相等\n");
    }
}