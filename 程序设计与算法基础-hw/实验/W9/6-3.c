/*
编程实现选择排序函数。void selectionSort(int arr[], int n);。其中arr存放待排序的数据，n为数组长度（1≤n≤1000）。

函数接口定义如下：
（对长度为n的数组arr执行选择排序）
void selectionSort(int arr[], int n);
请实现selectionSort函数，使排序后的数据从小到大排列。
*/
#include <stdio.h>

#define N 1000
int arr[N];

/* 对长度为n的数组arr执行选择排序 */
void selectionSort(int arr[], int n);

/* 打印长度为n的数组arr */
void printArray(int arr[], int n);

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
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
void selectionSort(int arr[], int n){
    int temp;
    for(int i=n;i>=1;i--){
        for(int j=1;j<i;j++){
            if(arr[j-1]>arr[j]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}