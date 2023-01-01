/*
让数组元素往左循环移动n位。
从键盘接收1个整数n，将一维整型数组的6个元素，向左循环移动n位。已知0<=n<=10。
在主函数中输出移动后的数据，每个数占2个宽度，左对齐。
*/
#include <stdio.h>
void moveleft (int *p,int n );
int main(){
    int a[6]={1,2,3,4,5,6},n,i;
    scanf("%d",&n);
    moveleft(a,n);
    for (i=0;i<6;i++)
        printf("%-2d",a[i]);
    return 0;
}
//一个一个移，一共移动n%6次即可
void moveleft (int *p,int n ){
    if(n>=6){
        n=n%6;
    }
    if(n==0){
        return;
    }
    for(int i=0;i<n;i++){
        int temp=p[0];
        for(int j=1;j<=5;j++){
            p[j-1]=p[j];
        }
        p[5]=temp;
    }
}