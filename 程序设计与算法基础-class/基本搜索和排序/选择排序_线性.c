#include <stdio.h>
int findmin(int a[],int begin,int end);
void sort(int a[],int e);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(int i=0;i<n;i++){
        printf("%4d",a[i]);
    }
}
int findmin(int a[],int begin,int end){
	int loc=begin;
	for(int i=begin;i<end;i++){
		if(a[i]<a[loc]){
			loc=i;
		}
	}
	return loc;
}//这是单独写了一个函数找出最小数
void sort(int a[],int e){
//选择排序的机制很简单，就是挑出最小的放当前位置，然后位置向后移
	for(int b=0;b<e;b++){
		int loc=findmin(a,b,e);
		int t=a[b];
		a[b]=a[loc];
		a[loc]=t;
	}
}