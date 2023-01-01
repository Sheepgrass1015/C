/*
楼梯有 n 级台阶，每一步可以跨越 1 ~ 3 级台阶。请问一共有多少种上法。

函数原型
double Climb(int step);
说明：参数 step 是台阶数。若 step>0，则函数值是爬楼梯的方法总数。若 step≤0，则函数值为 0。
*/
#include <stdio.h>

double Climb(int step);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%g\n", Climb(n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */
double Climb(int step){
    if(step<=0){
        return 0;
    }else if(step<=2){
        return step;
    }else if(step==3){
        return 4;
    }else{
        return Climb(step-1)+Climb(step-2)+Climb(step-3);
    }
}