/*
函数hmean()用于计算整数x和y的调和平均数，结果应保存在指针r所指向的浮点数对象中。
当x+y等于0时，函数返回0表示无法计算，否则返回1。
数学上，两个数x和y的调和平均数 z = 2xy/(x+y) 。
*/
#include <stdio.h>

//hmean()函数定义处

int main()
{
    int x=0,y=0;
    scanf("%d %d",&x,&y);

    float r = 0;
    int b = hmean(x,y,&r);

    if (b)
        printf("hmean(%d,%d)=%.2f",x,y,r);
    else
        printf("Input error.");

    return 0;
}
int hmean(const int x, const int y, float* r){
    if(x+y==0){
        return 0;
    }
    double x1=x;
    double y1=y;
    *r=2*x1*y1/(x1+y1);
    return 1;
}