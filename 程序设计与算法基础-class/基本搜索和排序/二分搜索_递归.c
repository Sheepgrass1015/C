#include <stdio.h>
//二分搜索的前提：必须是有序的元素
int s(int a[],int begin,int end,int key);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int d;
    scanf("%d",&d);
    int p=s(a,0,n-1,d);
    printf("%d\n",p);
}
int s(int a[],int begin,int end,int key){
    if(begin>=end){
        return -1;
    }
    int mid=(begin+end)/2;
    if(a[mid]==key){
        return mid;
    }else if(a[mid]>key){
        return s(a,begin,mid-1,key);
    }else{
        return s(a,mid+1,end,key);
    }
    //尾递归，直接调用自己
    //线性的，只调用一次
}