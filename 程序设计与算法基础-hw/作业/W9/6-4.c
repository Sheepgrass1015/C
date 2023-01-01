//本题要求实现快速排序的一趟划分函数，待排序列的长度1<=n<=1000。
/*
函数接口定义：
int Partition ( SqList L, int low,  int high )；
其中L是待排序表，使排序后的数据从小到大排列。
###类型定义：

typedef  int  KeyType;
typedef  struct 
{                      
  KeyType *elem; elem[0]一般作哨兵或缓冲区                  
  int Length;      
}SqList;
*/

#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct 
{                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                     
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
int Partition ( SqList  L,int low,  int  high );
void Qsort ( SqList  L,int low,  int  high );
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  Qsort(L,1,L.Length);
  for(i=1;i<=L.Length;i++)
      printf("%d ",L.elem[i]);
  return 0;
}
void Qsort ( SqList  L,int low,  int  high ) 
{ 
    int  pivotloc;
    if(low<high)
    {  
        pivotloc = Partition(L, low, high ) ;
        Qsort (L, low, pivotloc-1) ; 
        Qsort (L, pivotloc+1, high );
     }
}
/*你的代码将被嵌在这里 */
int Partition ( SqList L, int low,  int high ){
    int i,j,pivot,temp;
    pivot=L.elem[high];//这里就是普通的将high作为pivot了
    i=low;
    j=low;
    for(;j<high;j++){
        if(L.elem[j]<pivot){
            temp=L.elem[j];
            L.elem[j]=L.elem[i];
            L.elem[i]=temp;
            i++;
        }
    }
    temp=L.elem[i];
    L.elem[i]=L.elem[high];
    L.elem[high]=temp;
    return i;
}
/*
仔细想一下，如何改进这个算法呢？让它更快？
那肯定是在对pivot的选择上，要选择low、high、mid中的中位数作为pivot
*/