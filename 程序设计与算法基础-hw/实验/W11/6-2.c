/*
请编写函数，按 h:m:s 的格式输入时间。

函数原型
void TimeInput(int *hour, int *minute, double *second);
说明：hour、minute 和 second 分别为指示时、分和秒数的指针，
函数将按 h:m:s 的格式输入时间。
若输入不正确，则 hour、minute 和 second 所指变量的值不变。
*/
#include <stdio.h>

int TimeIsValid(int hour, int minute, double second);
void TimeInput(int *hour, int *minute, double *second);
void TimeOutput(int hour, int minute, double second);

int main()
{
    int hour = 12, minute = 34;
    double second = 56.78;
    TimeInput(&hour, &minute, &second);
    TimeOutput(hour, minute, second);
    putchar('\n');
    return 0;
}

int TimeIsValid(int hour, int minute, double second)
{
    //...(略)...
}

void TimeOutput(int hour, int minute, double second)
{
    //...(略)...
}

/* 你提交的代码将被嵌在这里 */
void TimeInput(int *hour, int *minute, double *second){
    int hour1,minute1;
    double second1;
    if((scanf("%d : %d : %lf",&hour1,&minute1,&second1))==3&TimeIsValid(hour1,minute1,second1)){
        *hour=hour1;
        *minute=minute1;
        *second=second1;
    }else{
        return ;
    }
}