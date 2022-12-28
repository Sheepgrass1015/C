#include <stdio.h>
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
	int ret=-1;
	int mid;
	while(begin<=end){//判断条件一：头和尾没遇上，如果头尾遇上，就是没找到
		mid=(begin+end)/2;
		if(a[mid]==key){
			ret=mid;
			break;//判断条件二：和目标值不想等，如果想等，就是找到了
		}else if(a[mid]>key){
			end=mid-1;
		}else{
			begin=mid+1;
		}
	}
	return ret;
}