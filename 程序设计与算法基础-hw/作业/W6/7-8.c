//Gram-Schmidt算法用来确定一组向量是否为线性无关的。
#include <stdio.h>
#include <math.h>
double a[1000][1000];
double q[1000][1000];//储存正交化之后的向量
double qq[1000][1000];//储存单位向量
double absv[1000];//储存模长
int flag[1000];//判断当前向量是否与之前向量线性相关
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    int mark=0;//判断向量组是否线性相关，如果是，记下第几个
    double sum=0;
    double t;
    for(int i=0;i<m;i++){
        flag[i]=1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    int flagg=0;
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if(a[i][j]!=0){
                flagg=1;
            }
        }
    }
    if(flagg==0){
        mark=2;
        goto here;
    }
    //初始化第一个向量的有关信息
    for(int i=0;i<n;i++){
        q[0][i]=a[0][i];
        sum+=a[0][i]*a[0][i];
        if (sum==0){
            goto here;
        }
        //printf("sum=%.2f\n",sum);
    }
    absv[0]=sqrt(sum);
    //printf("%.2f\n",absv[0]);
    for(int i=0;i<n;i++){
        qq[0][i]=q[0][i]/absv[0];
        //printf("qq[0][%d]=%.2f\n",i,qq[0][i]);
    }
    //初始化完毕,开始判断是否线性相关
    int k;
    for(k=1;k<m;k++){
        //第k+1个向量
        for(int i=0;i<n;i++){
            q[k][i]=a[k][i];//对a[k][i]进行讨论
            for(int j=0;j<k;j++){
                t=0;
                for(int p=0;p<n;p++){
                    t+=qq[j][p]*a[k][p];
                }
                q[k][i]=q[k][i]-t*qq[j][i];
            }
            if(!(fabs(q[k][i])<1E-6)){
                flag[k]=0;
            }
        }//循环结束，q[k][0-（n-1）]已经压满
        if(flag[k]==1){//跳出，第k+1个向量与之前向量线性相关
            mark=k+1;
            //printf("mark=%d\n",mark);
            goto here;
        }
        //第k+1个向量和之前向量线性无关
        //处理，qq、absv添加量
        sum=0;
        for(int i=0;i<n;i++){
            sum+=q[k][i]*q[k][i];
        }
        absv[k]=sqrt(sum);
        if (sum!=0){
            for(int i=0;i<n;i++){
                qq[k][i]=q[k][i]/absv[k];
            }
        }
    }
    here:
    if(mark!=0){
        printf("YES %d\n",mark);
    }else{
        printf("NO\n");
        for(int i=0;i<n;i++){
            if(i==0){
                printf("%.2lf",qq[m-1][i]);
            }else{
                printf(" %.2lf",qq[m-1][i]);
            }
        }
    }
    return 0;
}