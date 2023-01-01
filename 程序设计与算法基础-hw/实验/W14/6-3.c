/*
Write a function to add two polynomials. Do not destroy the input. Use a linked list implementation with a dummy head node.
Note: The zero polynomial is represented by an empty list with only the dummy head node.

Format of functions:
Polynomial Add( Polynomial a, Polynomial b );
where Polynomial is defined as the following:

typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;
Nodes are sorted in decreasing order of exponents. 
The function Add is supposed to return a polynomial which is the sum of a and b.
*/
//简单来说就是一个计算多项式之和的程序，裁判会给出次数和指数（如果考场上遇到这道题，那必须问老师英文的意思了）
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */
Polynomial Add( Polynomial a, Polynomial b ){
    Polynomial re=NULL;
    PtrToNode p=NULL;
    p=a->Next;
    PtrToNode q=NULL;
    q=b->Next;
    //创建一个新的链表，作为最终需要返回的结果
    PtrToNode head=(PtrToNode)malloc(sizeof(struct Node));
    head->Coefficient=0;
    head->Exponent=0;
    head->Next=NULL;
    re=head;
    while(p && q){
        int flag=1;
        PtrToNode add=(PtrToNode)malloc(sizeof(struct Node));
        add->Next=NULL;
        if(p->Exponent>q->Exponent){//先从次数大的开始
            add->Coefficient=p->Coefficient;
            add->Exponent=p->Exponent;
            p=p->Next;
        }else if(p->Exponent<q->Exponent){
            add->Coefficient=q->Coefficient;
            add->Exponent=q->Exponent;
            q=q->Next;
        }else if(p->Exponent==q->Exponent){//这个时候就要考虑完全抵消的情况（也是从结果反推的
            if((p->Coefficient+q->Coefficient)!=0){
                add->Coefficient=p->Coefficient+q->Coefficient;
                add->Exponent=q->Exponent;
            }else{
                flag=0;
            }
            p=p->Next;
            q=q->Next;
        }
        if(flag){//没有抵消的情况（大多数情况
            head->Next=add;
            head=add;
        }
    }
    if(p==NULL && q==NULL){
        return re;
    }else if(p==NULL){
        while(q){//其实可以完全后面就接上q的。直接就add->Next=q
            PtrToNode add=(PtrToNode)malloc(sizeof(struct Node));
            add->Next=NULL;
            add->Coefficient=q->Coefficient;
            add->Exponent=q->Exponent;
            q=q->Next;
            head->Next=add;
            head=add;
        }
    }else {
            PtrToNode add=(PtrToNode)malloc(sizeof(struct Node));
            add->Next=NULL;
            add->Coefficient=p->Coefficient;
            add->Exponent=p->Exponent;
            p=p->Next;
            head->Next=add;
            head=add;
    }
}