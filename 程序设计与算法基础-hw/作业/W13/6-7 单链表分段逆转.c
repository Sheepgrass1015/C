/*
给定一个带头结点的单链表和一个整数K，要求你将链表中的每K个结点做一次逆转。例如给定单链表 1→2→3→4→5→6 和 K=3，你需要将链表改造成 3→2→1→6→5→4；如果 K=4，则应该得到 4→3→2→1→5→6。

函数接口定义：
void K_Reverse( List L, int K );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;  存储结点数据 
    PtrToNode   Next;  指向下一个结点的指针 
};
typedef PtrToNode List; 定义单链表类型 
L是给定的带头结点的单链表，K是每段的长度。函数K_Reverse应将L中的结点按要求分段逆转。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List ReadInput(); /* 裁判实现，细节不表 */
void PrintList( List L ); /* 裁判实现，细节不表 */
void K_Reverse( List L, int K );

int main()
{
    List L;
    int K;

    L = ReadInput();
    scanf("%d", &K);
    K_Reverse( L, K );
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
void K_Reverse( List L, int K ){
    int a[100000]={0};
    PtrToNode p=NULL;
    int cnt=0;
    int n=0;
    int j=0;
    for(p=L->Next;p;p=p->Next){
        a[cnt]=p->Data;
        cnt++;
    }
    //由于直接在链表里对节点做逆转会很困难，因为同时要改变Data和Next，并且由于不知道下一个节点的数据，所以更难
    //所以我选择在先数组中将数据都逆转过后，再将数组的数据赋值给原来的链表
    //这样的话就根本没有改变原来节点的Next，而只改变了相对容易改变的Data，大大减小了难度
    p=L->Next;
    for(int i=0;i<cnt/K;i++){
        for(j=(n+1)*K-1;j>=n*K;j--){
            p->Data=a[j];
            p=p->Next;
        }
        n++;
    }
    return;
}