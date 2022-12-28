#include <stdio.h>
int gcd(int x,int y);
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",gcd(a,b));
}
int gcd(int x,int y){
    if(y==0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}
//辗转相除