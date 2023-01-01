//请编写函数，交换两个实数的值。
#include <stdio.h>

void RealSwap(double *x, double *y);

int main()
{
    double a, b;
    scanf("%lg%lg", &a, &b);
    RealSwap(&a, &b);
    printf("%g %g\n", a, b);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
void RealSwap(double *x, double *y){
    double a=*x;
    double b=*y;
    *x=b;
    *y=a;
}