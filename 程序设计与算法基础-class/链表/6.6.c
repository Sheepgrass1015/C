#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
void K_Reverse( List L, int K );

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
    /*scanf("%d", &N);
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
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;*/
}
/* 你的代码将被嵌在这里 */
List MakeEmpty(){
    PtrToLNode p=(PtrToLNode)malloc(sizeof(struct LNode));
    p->Data=0;
    p->Next=NULL;
    List L=p;
    return L;
}
Position Find( List L, ElementType X ){
    PtrToLNode p=NULL;
    for(p=L->Next;p;p=p->Next){
        if(p->Data==X){
            break;
        }
    }
    return p;
}
bool Insert( List L, ElementType X, Position P ){
    PtrToLNode p=NULL;
    PtrToLNode q=NULL;
    PtrToLNode n=(PtrToLNode)malloc(sizeof(struct LNode));
    n->Data=X;
    n->Next=NULL;
    q=L;
    if(P==NULL){
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
            free(n);
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
    if(p){
        if(q){
            q->Next=p->Next;
            free(p);
        }else{
            L->Next=p->Next;
            free(p);
        }
        return true;
    }else{
        printf("Wrong Position for Deletion\n");
        return false;
    }
}