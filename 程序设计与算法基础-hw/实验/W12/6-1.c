/*
任务描述
本关任务：用指针方法编写程序，分别输入两个按从小到大排序的数组 a 和 b，
将这两个有序数组合并，使合并后的数组 c 仍是从小到大有序的。

相关知识
为了完成本关任务，需要定义第三个数组c。
数组c的长度要大于数组a和b之和，还需要定义三个指针变量，分别指向三个数组。具体步骤如下：
在数组a和b的指针变量指向数组元素时，进入循环，比较a，b两个数组中指针指向的元素的大小，将较小元素存入数组c。
当数组c存入一个数据时，指向数组c的指针需向后移一位；
当a或b中某个数组的元素全部存入数组c时，跳出循环，再把另一个数组中剩下的数组元素全部存入数组c，从而实现两个数组合并后仍然有序。

编程要求
根据提示，在右侧编辑器 Begin-End 区间补充代码，实现将两个有序的数组合并成一个有序数组，输出合并后的数组。
*/
#include<stdio.h>
#define N 20
int main()
{

    int a[N]={ 0 }, b[N]={ 0 };
    int anum,bnum,c[N+N];
    int *pi, *pj,*pk;
    scanf("%d",&anum);   //输入数组a元素个数
    for(pi=a;pi<a+anum;pi++)
    {
        scanf("%d",pi);
    }
    scanf("%d",&bnum);   //输入数组b元素个数
    for(pj=b;pj<b+bnum;pj++)
    {
        scanf("%d",pj);
    }
    
    /***** 在数组a和b都有数据时比较两个数组 *****/
    /********** Begin *********/
    pi=a;
    pj=b;
    pk=c;
    while(pi<a+anum&&pj<b+bnum){
        if(*pi<*pj){
            *pk=*pi;
            pi++;
            pk++;
        }else{
            *pk=*pj;
            pj++;
            pk++;
        }
    }

    /********** End **********/

    /***** 如果数组a还有数据 *****/
    /********** Begin *********/
if(pi<a+anum){
    while(pi<=a+anum){
        *pk=*pi;
        pi++;
        pk++;
    }
}
    /********** End **********/

    /***** 如果数组b还有数据 *****/
    /********** Begin *********/
if(pj<b+bnum){
    while(pj<=b+bnum){
        *pk=*pj;
        pk++;
        pj++;
    }
}
    /********** End **********/
    
    /***** 输出数组c *****/
    /********** Begin *********/
pk=c;
while(pk<c+anum+bnum){
    if(pk==c){
        printf("%d",*pk);
    }else{
        printf(" %d",*pk);
    }
    pk++;
}
    /********** End **********/
    printf("\n");
    return 0;
}
