/*
本题要求实现二路归并排序中的归并操作，待排序列的长度1<=n<=1000。
*/
//其实可以看得出来，这道题主要的难度就在于数据量的大小
#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
void  MergeSort(SqList L,int low,int high);
void Merge(SqList L,int low,int m,int high); 
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  MergeSort(L,1,L.Length);
  for(i=1;i<=L.Length;i++)
   {        
      printf("%d ",L.elem[i]);
   }
  return 0;
}
void MergeSort(SqList L,int low,int high)  
{     
    /*用分治法进行二路归并排序*/  
    int mid;  
    if(low<high)  /*区间长度大于1*/
    {      
        mid=(low+high)/2;               /*分解*/
        MergeSort(L,low,mid);           /*递归地对low到mid序列排序 */ 
        MergeSort(L,mid+1,high);        /*递归地对mid+1到high序列排序 */ 
        Merge(L,low,mid,high);          /*归并*/  
    }  
}
/*你的代码将被嵌在这里 */
void Merge(SqList L,int low,int m,int high){
    int i,j,a[10000],b[10000];//为了符合数据大小定义的数组大小
    for(int k=1;k<=m-low+1;k++){
        a[k]=L.elem[low+k-1];//将从low到m到元素储存到a
    }
    for(int k=1;k<=high-m;k++){
        b[k]=L.elem[m+k];//将从m+1到high到元素储存到b
    }
    i=1;
    j=1;
    //对ab进行归并，并且将归并结果反回来储存到L中
    for(int k=0;k<high-low+1;k++){
        if((i<=m-low+1)&&(j>high-m||a[i]<b[j])){
            L.elem[low+k]=a[i];
            i++;
        }else{
            L.elem[low+k]=b[j];
            j++;
        }
    }
}
/*
从上面的程序中可以看出来，如果像我一样一定要将数据从a[0]开始储存
那么在判断的时候就会很麻烦
其实直接从a[low]储存到a[m]，再从b[m+1]储存到b[high]也是可以的
毕竟数组的大小总是够的
*/