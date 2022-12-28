#include <stdio.h>
void sort_bubble(int a[],int size);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort_bubble(a,n);
    for(int i=0;i<n;i++){
    printf("%4d",a[i]);
    }
}
void sort_bubble(int a[], int size){
	for ( int i=size-1; i>0; i-- ) {
		int loc = -1;
		for ( int j=0; j<i; j++ ) {
			if ( a[j] > a[j+1] ) {
				int t = a[j];
	                a[j] = a[j+1];
	                a[j+1] = t;
	                loc = j;//loc记录的是最后一次交换的位置
							//下一次，loc之后的位置就不用考虑了（已经有序
            }
        }        
		i = loc+1;//这里针对i从前往后而言，如果是i从后往前，就是loc-1
	}
}