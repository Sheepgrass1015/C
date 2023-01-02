/*
设曲线方程f(x)=0在区间[a,b]上连续，如果f(a)f(b)<0，
则方程在区间内至少存在一个根r，使得f(r)=0. 
现在要求用二分法编写一个求解各类一元方程方程在给定区间解的通用函数，
调用该函数来求下列三个方程在区间[a,b]上的解.
要求：编写的函数要能判断在给定区间上是否有解，
如果有解按照二分法进行求解，如果无解函数返回一个实数值-32768作为无解的标志。
函数接口定义：
double bisection(double (*f)(),double a,double b)
其中 参数f是一个指向函数的指针变量。参数 a 和b是解区间的两个端点，函数的返回值为方程在区间上的解。
*/
#include <stdio.h>
#include <math.h>
double quadratic(double x)  /*一个一元二次函数f*/
{
    return x*x-5;
}
double cubic(double x)  /*一个一元三次函数f*/
{
    return x*x*x-5;
}
/* 你编写的二分法解方程的函数放在这里   */
int main()
{
    double x;
    double a,b;
    scanf("%lf%lf",&a,&b);        //输入解区间左右端点的值
    x=bisection(quadratic,a,b); //解一元二次方程
    printf("%.3f\n",x);
    x=bisection(cubic,a,b);        //解一元三次方程
    printf("%.3f\n",x);
    x=bisection(sin,a,b);            //求解方程sinx=0
    printf("%.3f\n",x);
    return 0;
}
/*你的代码将会在此处*/
double bisection(double (*f)(),double a,double b){
    double ret;
    if(f(a)*f(b)>0){//其实挺简陋的……只考虑了单调的情况
        return -32768;
    }else {
        ret=(a+b)/2;
        while(fabs(f(ret))>0.00001){//不是解
            if(f(a)*f(ret)<0){
                b=ret;
                ret=(a+b)/2;
            }else if(f(b)*f(ret)<0){
                a=ret;
                ret=(b+a)/2;
            }
        }
        return ret;
    }
}