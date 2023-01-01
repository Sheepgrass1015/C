/*
本题要求使用二分查找法，在给定的n个升序排列的整数中查找x，并输出查找过程中每一步的中间结果。
如果数组a中的元素与x的值相同，输出相应的下标（下标从0开始）；如果没有找到，输出“Not Found”。
如果输入的n个整数没有按照从小到大的顺序排列，或者出现了相同的数，则输出“Invalid Value”。

二分查找法的算法步骤描述如下：

设n个元素的数组a已升序排列，用left和right两个变量来表示查找的区间，
即在a[left] 〜 a[right]区间去查找x。初始状态为left = 0，right = n-1。
首先用要查找的x与查找区间的中间位置元素a[mid]（mid = (left + right) / 2）比较，
如果相等则找到；如果x < a[mid]，由于数组是升序排列的，则只要在a[left] 〜 a[mid-1]区间继续查找；
如果x > a[mid]，则只要在a[mid+1] 〜 a[right]区间继续查找。
也就是根据与中间元素比较的情况产生了新的区间值left、right值，当出现left > right时，说明不存在值为x的元素。

输入格式：
输入在第1行中给出一个正整数n（1≤n≤10）和一个整数x，第2行输入n个整数，其间以空格分隔。题目保证数据不超过长整型整数的范围。

输出格式：
在每一行中输出查找过程中对应步骤的中间结果，按照“[left,right][mid]”的格式输出。提示：相邻数字、符号之间没有空格。

如果找到，输出相应的下标（下标从0开始）；如果没有找到，在一行中输出“Not Found”。

如果输入的n个整数没有按照从小到大的顺序排列，或者出现了相同的数，则输出“Invalid Value”。
*/
#include <stdio.h>
int main(){
    int n,x,left,right,mid,found,ret;
    int a[1000];
    ret=0;
    found=0;
    scanf("%d %d",&n,&x);
    //首先创造数组
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    left=0;
    right=n-1;

    //然后判断是否会有invalid value的情况出现
    //即不单调递增，或者有重复数据
    for(int i=0;i<n-1;i++){
        if(a[i]>=a[i+1]){
            printf("Invalid Value\n");
            goto here;//如果是invalid value直接跳到输出
        }
    }

    //接下来二分查找
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==x){
            found=1;
            ret=mid;
            break;
        }else if(a[mid]>x){
            printf("[%d,%d][%d]\n",left,right,mid);
            right=mid-1;
        }else{
            printf("[%d,%d][%d]\n",left,right,mid);
            left=mid+1;
        }
    }
    if(found==0){
        printf("Not Found\n");
    }else{
        printf("[%d,%d][%d]\n",left,right,mid);
        printf("%d\n",ret);
    }
    here:
    return 0;
}