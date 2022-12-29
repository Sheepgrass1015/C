/*
本题要求实现链式表的操作集。
函数接口定义：
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );
其中List结构定义如下：

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

各个操作函数的定义为：
Position Find( List L, ElementType X )：返回线性表中首次出现X的位置。若找不到则返回ERROR；
List Insert( List L, ElementType X, Position P )：将X插入在位置P指向的结点之前，返回链表的表头。
如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR；
List Delete( List L, Position P )：将位置P的元素删除并返回链表的表头。
若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR。
*/
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;//简单的单头单向无哨兵的链表

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);//所以我们知道，插在NULL之前是可以的
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( List L, ElementType X ){
    PtrToLNode p=NULL;
    for(p=L;p;p=p->Next){
        if(p->Data==X){
            break;
        }
    }
    if(p){
        return p;
    }else{
        return ERROR;
    }
}
List Insert( List L, ElementType X, Position P ){
    PtrToLNode p=NULL;
    PtrToLNode q=NULL;
    struct LNode *n=(struct LNode *)malloc(sizeof(struct LNode));
    n->Data=X;
    n->Next=NULL;
    if(P==NULL){//为什么知道要判断P为NULL的情况？——看题目给出的代码
        if(L==NULL){//空链表
            n->Next=L;
            L=n;
        }else{//插在末尾
            for(p=L;p->Next;p=p->Next)
            ;
            p->Next=n;
        }
        return L;
    }
    for(p=L;p;){
        //会进入这个循环，说明既不是空链表，也不插在末尾——所以判断上述两种情况的代码要放在前面
        if(p==P) break;
        q=p;
        p=p->Next;
    }
    if(p){
        if(q){
            q->Next=n;
            n->Next=p;
        }else{//插在表头
            n->Next=L;
            L=n;
        }
        return L;
    }else{//在经过循环之后p是NULL才说明是没有找到
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
}
List Delete( List L, Position P ){
    PtrToLNode p=NULL;
    PtrToLNode q=NULL;
    for(p=L;p;){
        if(p==P) break;
        q=p;
        p=p->Next;
    }
    if(p){//存在
        if(q){//不是表头
            q->Next=p->Next;
            free(p);
        }else{//表头
            L=p->Next;
            free(p);
        }
        return L;
    }else{//不存在
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
}
