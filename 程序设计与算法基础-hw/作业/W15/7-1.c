/*
所有真因子之和小于其本身的数称为亏数。如：4 的真因子 1、2 之和为 3，小于 4，是亏数。

所有真因子之和大于其本身的数称为盈数。如：12 的真因子 1、2、3、4、6 之和为 16，大于 12，是盈数。

不盈不亏的数，即：所有真因子之和等于其本身的数，称为完美数。如：6 的真因子 1、2、3 之和恰为 6，是完美数。

请编写程序，显示指定范围内的完美数。
*/
#include <stdio.h>
#include <math.h>

int judge(int x);

int main(){
    int a,b,cnt=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        if(judge(i)){
            cnt++;
            if(cnt==1){
                printf("%d",i);
            }else{
                printf(" %d",i);
            }
        }
    }
    if(cnt==0){
        printf("None\n");
    }
}

int judge(int x){
    int sum=0;
    for(int i=1;i<x;i++){
        if(x%i==0){
            sum+=i;
        }
    }
    if(sum==x){
        return 1;
    }else{
        return 0;
    }
}