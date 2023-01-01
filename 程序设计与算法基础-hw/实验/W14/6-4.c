/*
有一种存储英文单词的方法，是把单词的所有字母串在一个单链表上。
为了节省一点空间，如果有两个单词有同样的后缀，就让它们共享这个后缀。
下图给出了单词“loading”和“being”的存储形式。本题要求你找出两个链表的公共后缀。
函数接口定义：
PtrToNode Suffix( List L1, List L2 );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; 存储结点数据 
    PtrToNode   Next; 指向下一个结点的指针 
};
typedef PtrToNode List; 定义单链表类型 
L1和L2都是给定的带头结点的单链表。函数Suffix应返回L1和L2的公共后缀的起点位置。
*/
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput( List L1, List L2 ); /* 裁判实现，细节不表 */
void PrintSublist( PtrToNode StartP ); /* 裁判实现，细节不表 */
PtrToNode Suffix( List L1, List L2 );

int main()
{
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput( L1, L2 );
    P = Suffix( L1, L2 );
    PrintSublist( P );

    return 0;
}

/* 你的代码将被嵌在这里 */
//如果p和q同步前进，不一定可行
//因为p和q的长度不同，但是如果通过调整，使得当进行向后移的过程开始时
//p和q距离尾巴的距离是一样的呢？
PtrToNode Suffix( List L1, List L2 ){
    PtrToNode p=NULL;
    PtrToNode q=NULL;
    PtrToNode temp=NULL;
    p=L1->Next;
    q=L2->Next;
    int cnt1=0;
    int cnt2=0;
    int min,max;;
    for(;p;p=p->Next){
        cnt1++;
    }
    for(;q;q=q->Next){
        cnt2++;
    }
    p=L1->Next;
    q=L2->Next;
    if(cnt1<cnt2){
        temp=p;
        p=q;
        q=temp;
        max=cnt2;
        min=cnt1;
    }else{
        max=cnt1;
        min=cnt2;
    }
    //算出差值
    for(int i=0;i<max-min;i++){
        p=p->Next;
    }
    //通过调整，弥补差值
    //这个时候可以同步后移了
    while(p && q){
        if(p==q){
            return p;
        }else{
            p=p->Next;
            q=q->Next;
        }
    }
}