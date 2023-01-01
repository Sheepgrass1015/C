/*
本题要求实现一个计算复数之积的简单函数。

函数接口定义：
struct complex multiply(struct complex x, struct complex y);
其中struct complex是复数结构体，其定义如下：

struct complex{
    int real;
    int imag;
};

*/
#include <stdio.h>

struct complex{
    int real;
    int imag;
};

struct complex multiply(struct complex x, struct complex y);

int main()
{
    struct complex product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n", 
            x.real, x.imag, y.real, y.imag, product.real, product.imag);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
struct complex multiply(struct complex x, struct complex y){
    int a,b,c,d;
    a=x.real;
    b=x.imag;
    c=y.real;
    d=y.imag;
    struct complex re;
    re.real=a*c-b*d;
    re.imag=a*d+b*c;
    return re;
}