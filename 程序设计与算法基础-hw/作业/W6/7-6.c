/*
给定一个初始为空的栈和一系列压栈、弹栈操作，请编写程序输出每次弹栈的元素。栈的元素值均为整数。

输入格式:
输入第1行为1个正整数n，表示操作个数；接下来n行，每行表示一个操作，格式为1 d或0。1 d表示将整数d压栈，0表示弹栈。n不超过20000。

输出格式:
按顺序输出每次弹栈的元素，每个元素一行。若某弹栈操作不合法（如在栈空时弹栈），则对该操作输出invalid。
*/
//重要的是理解栈的原理和操作
//栈是单进单出的
#include <stdio.h>
int main(){
    int top=0;
    int n;
    int act,num;
    scanf("%d",&n);
    int a[20000+3]={0};//+3防止溢出
    while(n>0){
        scanf("%d",&act);
        if(act==1){
            scanf("%d",&num);
            a[top++]=num;
        }else{
            top--;
            if(top<0){
                printf("invalid\n");
                top++;
            }else{
                printf("%d\n",a[top]);
            }
        }
        n--;
    }
    return 0;
}