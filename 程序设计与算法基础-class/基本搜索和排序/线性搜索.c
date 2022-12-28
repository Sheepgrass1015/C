#include <stdio.h>
int s(int length ,int a[] ,int key);
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int p=s(10,a,7);
    printf("%d\n",p);
}
int s(int length ,int a[] ,int key){
	int r=0;
	for(int i=0;i<length;i++){
		if(a[i]==key){
				r=i;
				break;
			}
	}
	return r;
}
