/*
对于输入的两个不超过100位数字的非负整数，给出两数之和。
输入格式:
在两行中分别给出两个不超过100位数字的非负整数
输出格式:
在一行中输出两数之和
*/

//高精度加法
#include <stdio.h>

int main(){
    int a[101]={0};
    int b[101]={0};
    int c[101]={0};//多留一位，进位用
    int i=1;
    int j=1;
    char ch;
    ch=getchar();
    //将数字一位一位读到数组里
    while(ch!='\n'){
        a[i]=ch-'0';
        //printf("a[%d] = %d\n",i,a[i]);
        i++;
        ch=getchar();
    }
    ch=getchar();
    while(ch!='\n'){
        b[j]=ch-'0';
        //printf("b[%d] = %d\n",j,b[j]);
        j++;
        ch=getchar();
    }
    int max;
    if(i>j){
        int d=i-j;
        max=i;
        int m=i;
        for(int k=0;k<j;k++){
            b[m]=b[m-d];
            m--;
        }
        for(int k=0;k<=d;k++){
            b[k]=0;
        }
    }else{
        int d=j-i;
        max=j;
        int n=j;
        for(int k=0;k<i;k++){
            a[n]=a[n-d];
            n--;
        }
        for(int k=1;k<=d;k++){
            a[k]=0;
        }
    }
    int carry=0;
    int temp;
    int k;
    for(k=max-1;k>=1;k--){
        c[k]=carry;
        //carry是进位，值得注意的是，这次算出来的进位并不是给这一次的，而是给下一次的
        temp=a[k]+b[k];
        if(temp==0)break;
        carry=0;
        if(temp>=10){
            carry=1;
            temp%=10;
        }
        c[k]+=temp;
    }
    if(carry && i==j){
        c[0]=1;
        for(int i=0;i<max;i++){
            printf("%d",c[i]);
        }
    }else{
        for(int i=1;i<max;i++){
            printf("%d",c[i]);
        }
    }
}
