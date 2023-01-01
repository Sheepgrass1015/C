//请编写递归函数，求组合数。
//这里的难点在于如何快速完成对于组合数的计算，怎么样最快
//这就涉及到相应的数学公式
#include <stdio.h>

double Cmb(int x, int y);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%.10g\n", Cmb(m, n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */
double Cmb(int x, int y){
    if(y==0||x==y){
        return 1;
    }
    if(y==1){
        return x;
    }else{
        if(y>x/2){
            y=x-y;
        }
        return x*Cmb(x-1,y-1)/y;
    }
}