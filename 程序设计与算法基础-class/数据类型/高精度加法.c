#include <stdio.h>

int main(){
    int a[101]={0};
    int b[101]={0};
    int c[101]={0};
    int i=1;
    int j=1;
    char ch;
    ch=getchar();
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