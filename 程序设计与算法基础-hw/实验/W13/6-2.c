//化简假分数
#include <stdio.h>

typedef struct {
    int integer;
    int numerator;
    int denominator;
} Fraction;

Fraction fraction_reduce(Fraction f);

int main()
{
    Fraction f = {0};
    scanf("%d/%d", &f.numerator, &f.denominator);
    f = fraction_reduce(f);
    if ( f.integer ) {
        printf("%d", f.integer);
        if ( f.numerator ) {
            printf(" ");
        }
    }
    if ( f.numerator ) {
        printf("%d", f.numerator);
        if ( f.denominator != f.numerator ) {
            printf("/%d", f.denominator);
        }
    }   
    printf("\n");
}

/* Put your code here. */
Fraction fraction_reduce(Fraction f){
    int i=f.integer;
    int n=f.numerator;
    int d=f.denominator;
    Fraction re;
    if(n%d==0){//化简之后是整数的情况
        re.integer=n/d;
        re.numerator=0;
        re.denominator=0;
        return re;
    }
    if(n>d){//真的是假分数
        while(n>d){
            i++;//先把整数部分算出来
            n-=d;
        }
    }
    int x,y;
    x=d;
    y=n;
    int max;
    int temp;
    //辗转相除法求bdq
    while(y!=0){
        temp=x%y;
        x=y;
        y=temp;
    }
    max=x;
    d/=max;
    n/=max;
    re.integer=i;
    re.numerator=n;
    re.denominator=d;
    return re;
}