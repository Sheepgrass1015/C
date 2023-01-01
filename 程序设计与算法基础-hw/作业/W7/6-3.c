/*
本题要求实现一个函数，对一个整数进行按位顺序输出
*/
#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    printdigits(n);

    return 0;
}

/* 你的代码将被嵌在这里 */
void printdigits( int n ){
    if(n<10){
        printf("%d\n",n);
    }else{
        printdigits(n/10);//永远假设前面n-1项已经可以被打印出来
        printf("%d\n",n%10);
    }
}
