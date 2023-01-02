/*
在国外的一本数学书中收录了各种各样的数列，其中就有这样一个数列：

1, 2, 5, 10, 21, 42, 85, 170, 341, ...

起先大家都感到莫名其妙，不知道它有什么用。它既非等差数列，又非等比数列，也不是一些非常有名的数列。
后经人指点，大家才恍然大悟，原来它是九连环数列。

第 1 项为 1，表明解开 1 个环需 1 步；第 2 项为 2，表明解开 2 个环需要 2 步；......，第 9 项为 341，表明解开 9 个环需要 341 步，......，以此类推。
请编写递归函数，求九连环数列中任一项的值。

函数原型
double NumRing(int index);
说明：参数 index 为索引号(正整数)，函数值为汉诺塔数列第 index 项的值。(其实这并不是真的……)

要求：不要使用循环语句。不要调用 pow、exp 等函数。可调用前面作业中的 IsOdd 或 IsEven 函数判断奇数或偶数。
*/
#include <stdio.h>

int IsOdd(int x);
int IsEven(int x);
double NumRing(int index);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.15g\n", NumRing(n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */
double NumRing(int index){
    if(index==1){
        return 1;
    }else{
        if(IsOdd(index)==1){
            return 2*(NumRing(index-1))+1;
        }else{
            return 2*(NumRing(index-1));
        }
    }
}
int IsOdd(int x){
    if(x%2==1){
        return 1;
    }else{
        return 0;
    }
}
int IsEven(int x){
    if(x%2==0){
        return 1;
    }else{
        return 0;
    }
}