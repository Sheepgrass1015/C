#include <stdio.h>

int power(int x,int n);

int main(){
    int x,n;
    scanf("%d %d",&x,&n);
    printf("x^n = %d\n",power(x,n));
}

int power(int x,int n){
	if(n==0){
		return 1;
	}else if(n%2==0){
		int t= power(x,n/2);
		return t*t;
	}else{
		return x*power(x,n-1);
	}
}