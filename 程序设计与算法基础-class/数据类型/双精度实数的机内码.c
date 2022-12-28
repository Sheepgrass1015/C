#include <stdio.h>
#include<math.h>
int main(){
    double x;
    scanf("%lf",&x);
    double y;
    y=x;
    unsigned char *hex=(unsigned char*)&x;
    unsigned char *hex1=(unsigned char*)&y;
    for(int i=7;i>=0;i--)    
    {        
        printf("int hex : %hhu\n",hex[i]);    
    }
    for(int i=7;i>=0;i--)    
    {        
        printf("int hex1 : %hhu\n",hex1[i]);
    }
}

/*
#include <stdio.h>
void getH_int(int a,char *ch);
void getH_double(double a,char *ch);
int main(){
    double x;
    scanf("%lf",&x);
    int a=0;
    double b;
    char *hex=0;
    if(x<0){
        hex[0]=1;
        x=-x;
    }
    while(a<x){
        a++;
    }
    a--;
    b=x-a;
    printf("a = %d , b = %.20f\n",a,b);
}
void getH_int(int a,char *ch){
    int x=a;
    while(x>0){

    }
}
void getH_double(double a,char *ch){

}
*/
