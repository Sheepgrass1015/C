#include <stdio.h>
static int cnt=0;
void hanoi(int n,char source,char target,char aux);
int main(){
    int n;
    char a,b,c;
    scanf("%d %c %c %c",&n,&a,&b,&c);
    hanoi(n,a,b,c);
    }
void hanoi(int n,char source,char target,char aux){
    if(n>0){
        hanoi(n-1,source,aux,target);
        cnt++;
        printf("第%d 步：将 %d 从 %c 移动到 %c\n",cnt,n,source,aux);
        hanoi(n-1,aux,target,source);
    }
}
/*汉诺塔的代码真的很简单，其实假设能够把前n-1个从source移动到target后，
就只要考虑第n个的实现——把前n-1个移动到中间柱上，然后把第n个移动到目标柱上，
最后把前n-1个移动到目标柱上，这样n个圆盘的移动就完成了
*/