/*
用牛顿迭代法求平方根
*/
#include <stdio.h>
double sqrt(double x);

int main(){
    double a;
    scanf("%lf",&a);
    printf("sqrt(a) = %f\n",sqrt(a));
}

double sqrt(double x) {
     if (x == 0) return 0;
     double last = 0.0;
     double res = 1.0;
     while (res != last)
     {
         last = res;
         res = (res + x / res) / 2;//从x_n-1的切线方程求x_n
     }
     return res;
      }