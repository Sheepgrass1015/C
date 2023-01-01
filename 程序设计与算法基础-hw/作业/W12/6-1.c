/*
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下：

struct ListNode {
    int data;
    ListNode *next;
};
函数接口定义：
struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。

函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。
返回指向新链表头结点的指针，同时将L中存储的地址改为删除了奇数值结点后的链表的头结点地址（所以要传入L的指针）。


*/


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist(){
    struct ListNode *L;
    int x;
    struct ListNode *head;
    while(1){
        scanf("%d",&x);
        if(x==-1)break;
        struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->data=x;
        p->next=NULL;
        int i=0;
        if(head){
            head->next=p;
        }else{
            i=1;//当是一个空链表的时候，这个节点就是表头，即返回值。所以标记一下
        }
        head=p;
        if(i==1){
            L=head;
        }
    }
    return L;

}
struct ListNode *getodd( struct ListNode **L ){
    struct ListNode *p=*L;
    struct ListNode *q=NULL;
    struct ListNode *oddhead=NULL;
    struct ListNode *re=NULL;
    for(;p;){
        if(p->data%2==1){
            int i=0;
            if(oddhead){
                oddhead->next=p;
            }else{
                i=1;
            }
            oddhead=p;
            if(i==1){
                re=oddhead;
            }
            if(q){
                q->next=p->next;
            }else{
                *L=p->next;
            }
        }else{
            q=p;
        }
        p=p->next;
    }
    return re;
}