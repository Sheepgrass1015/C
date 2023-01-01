/*
请编写程序，输入十进制双精度实数，输出其 64 位机内码。

要求：以十六进制形式输出机内码。

输入格式
十进制实数

输出格式
机内码(十六进制)
*/

#include <stdio.h>
#include<math.h>
int main(){
    double x;
    scanf("%lf",&x);
    unsigned char *hex=(unsigned char*)&x;
    for(int i=7;i>=0;i--)    
    {        
        printf("%02X",hex[i]);    
    }
}
//这个是真的不太懂