//本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
    List tL1=L1;
    List tL2=L2;
    if(L1->Next==NULL && L2->Next==NULL){
        return L1;
    };
    PtrToNode p=(PtrToNode)malloc(sizeof(struct Node));//p是链表头
    p->Data=0;
    p->Next=NULL;
    List head=p;
    List re=NULL;
    if(L1->Next->Data<L2->Next->Data){
        head->Next=L1->Next;
        L1=L1->Next->Next;
        L2=L2->Next;
    }else{
        head->Next=L2->Next;
        L2=L2->Next->Next;
        L1=L1->Next;
    }
    re=head;
    head=head->Next;
    while(L1 && L2){
        //printf("%d %d\n",L1->Data,L2->Data);
        if(L1->Data<L2->Data){
            head->Next=L1;
            L1=L1->Next;
        }else{
            head->Next=L2;
            L2=L2->Next;
        }
        if(L1 || L2){
            head=head->Next;
        }
    }
    if(L2 == NULL && L1 !=NULL){
        head->Next=L1;
    }
    if(L1 == NULL && L2 != NULL){
        head->Next=L2;
    }
    L1->Next=NULL;
    L2->Next=NULL;
    return re;
}