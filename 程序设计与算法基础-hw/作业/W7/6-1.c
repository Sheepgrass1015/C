/*
How does one compute square roots?
 The most common way is to use Newton's method of successive approximations,
  which says that whenever we have a guess y for the value of the square root of a number x, 
  we can perform a simple manipulation to get a better guess (one closer to the actual square root) by averaging y with x/y. 
  To make the process simpler, we can always begin to guess 1.0 as square root of any x.

You are going to write a function to calculate the square root: 
double f(double x, double guess, double eps).
x is value to get square root from; guess is 1.0 always; 
eps is a very small number that when the distance between guess's square and x is less than eps,
we say guess is the square root of x.
*/

#include <stdio.h>

double f(double x, double guess, double eps);

int main()
{
    double x, eps;
    
    scanf("%lf %lf", &x, &eps);

    printf("%.3f\n", f(x, 1.0, eps));
        
  return 0;
}

/* 请在这里填写答案 */
double f(double x, double guess, double eps){
    if(guess*guess-x<eps&&guess*guess-x>-eps){
        return guess;
    }else{
        return f(x,(guess+x/guess)/2,eps);//记住这个公式吧，或者运用切线推也是可以的
    }
}