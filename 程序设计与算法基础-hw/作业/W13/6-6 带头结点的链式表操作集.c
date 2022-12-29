/*
本题要求实现带头结点的链式表操作集。

函数接口定义：
List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
其中List结构定义如下：

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
各个操作函数的定义为：

List MakeEmpty()：创建并返回一个空的线性表；

Position Find( List L, ElementType X )：返回线性表中X的位置。若找不到则返回ERROR；

bool Insert( List L, ElementType X, Position P )：将X插入在位置P指向的结点之前，返回true。
如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回false；

bool Delete( List L, Position P )：将位置P的元素删除并返回true。
若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回false
*/
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};//单头单向有哨兵的链表
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);//有insertNULL这种操作，写的时候记得判断
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty(){
    PtrToLNode p=(PtrToLNode)malloc(sizeof(struct LNode));
    p->Data=0;
    p->Next=NULL;
    List L=p;//初始化一个空链表头，并且将其赋给链表
    return L;
}
Position Find( List L, ElementType X ){
    PtrToLNode p=NULL;
    for(p=L->Next;p;p=p->Next){
        if(p->Data==X){
            break;
        }
    }
    return p;//注意看要返回的是这个节点的地址还是它的序号
}
bool Insert( List L, ElementType X, Position P ){
    PtrToLNode p=NULL;
    PtrToLNode q=NULL;
    PtrToLNode n=(PtrToLNode)malloc(sizeof(struct LNode));
    n->Data=X;
    n->Next=NULL;
    q=L;
    if(P==NULL){//insertNULL，也就是在空链表里插入
        for(p=L->Next;p;){
            q=p;
            p=p->Next;
        }
        q->Next=n;
        return true;
    }
    for(p=L->Next;p;){
        if(p==P) break;
        q=p;
        p=p->Next;
    }
    if(p==L->Next){//p插在表头
        n->Next=L->Next;
        L->Next=n;
        return true;
    }else{//p不是插在表头
        if(p){//找到了
            n->Next=p;
            q->Next=n;
            return true;
        }else{
            free(n);//如果没用上，记得及时free！及时free！及时free！！
            printf("Wrong Position for Insertion\n");
            return false;
        }
    }
}
bool Delete( List L, Position P ){
    PtrToLNode p=NULL;
    PtrToLNode q=NULL;
    q=L;
    for(p=L->Next;p;){
        if(p==P) break;
        q=p;
        p=p->Next;
    }
    if(p){//这里因为有头节点，就不需要判断q是不是NULL了，因为这种情况不存在！
        q->Next=p->Next;
        free(p);
        return true;
    }else{
        printf("Wrong Position for Deletion\n");
        return false;
    }
}
