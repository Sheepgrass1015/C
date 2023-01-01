/*
编程实现插入排序函数。void insertionSort(int arr[], int n);。其中arr存放待排序的数据，n为数组长度（1≤n≤1000）。

函数接口定义如下：
（对长度为n的数组arr执行插入排序 ）
void insertionSort(int arr[], int n);
请实现insertionSort函数，使排序后的数据从小到大排列。
*/
#include <stdio.h>

#define N 1000
int arr[N];

/* 对长度为n的数组arr执行插入排序 */
void insertionSort(int arr[], int n);

/* 打印长度为n的数组arr */
void printArray(int arr[], int n);

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
/* 打印长度为n的数组arr */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)  /* 下标0..n-2每个元素后面有个空格 */
            printf(" ");/*下标n-1,也就是最后一个元素后面没有空格*/
    }
    printf("\n");/* 一行打印完后换行 */
}

/* 你的代码将嵌在这里 */
void insertionSort(int arr[], int n){
    if(n==0){
        return;
    }
    for (int i=1;i<=n-1;i++){//用循环比用递归要好，防止segmentation fault
        int j=i-1;
        int temp=arr[i];
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        if(j==-1){
            arr[0]=temp;
        }else{
            arr[j+1]=temp;
        }
    }
}