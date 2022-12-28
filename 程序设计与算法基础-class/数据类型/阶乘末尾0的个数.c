#include <stdio.h>
#include <math.h>

int count(long long x);

int main(){
    int n;
    scanf("%d",&n);
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",count(a[i]));
    }
}
int count(long long x){
    int cnt=0;
    for(long long i=1;i<=x;i++){
        if(i%5==0){
            int j=i;
            while(j%5==0){
                cnt++;
                j/=5;
            }
        }
    }
    return cnt;
}
