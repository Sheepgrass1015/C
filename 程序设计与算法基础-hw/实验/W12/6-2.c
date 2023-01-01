/*
用指针实现，输入6个整数，把最小数与第1个数交换，最大数与最后1个数交换，其它数据不动。
输入保证最大值和最小值唯一。请编写3个函数：
（1）输入6个数；（2）进行处理函数；（2）输出6个数，每个数占3个宽度，左对齐。
*/
#include <stdio.h>
void inputdata(int *p);
void swapdata(int *p);
void printdata(int *p);
int main(){
    int a[6];
    inputdata(a);
    swapdata(a);
    printdata(a);
    return 0;
}
void inputdata(int *p){
    for(;p<p+6;p++){
        scanf("%d",p);//这样写多少让人怕怕的……
    }
}
void swapdata(int *p){
    int *max;
    int *min;
    min=p;
    max=p;
    int *p1;
    int *p2;
    p1=p;
    p2=p+5;
    int temp;
    for(;p<p1+6;p++){
        if(*p<*min){
            min=p;
        }
        if(*p>*max){
            max=p;
        }
    }
    if(!(max==p1&&min==p2)){
    temp=*p1;
    *p1=*min;
    *min=temp;
    temp=*p2;
    *p2=*max;
    *max=temp;
    }else{
        temp=*p2;
        *p2=*p1;
        *p1=temp;
    }

}
void printdata(int *p){
    int *p1;
    p1=p;
    for(;p<p1+6;p++){
        printf("%-3d",*p);
    }
}
