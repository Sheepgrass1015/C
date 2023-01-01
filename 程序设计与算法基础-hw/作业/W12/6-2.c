/*
本题要求实现一个函数，将给定单向链表逆置，即表头置为表尾，表尾置为表头。链表结点定义如下：

struct ListNode {
    int data;
    struct ListNode *next;
};
函数接口定义：
struct ListNode *reverse( struct ListNode *head );
其中head是用户传入的链表的头指针；函数reverse将链表head逆置，并返回结果链表的头指针。
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *rehead=NULL;
    if(head==NULL){
        return head;
    }
    int x;
    while(1){
        x=head->data;
        struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->data=x;
        p->next=rehead;//关键就在于这一句
        //常规的链表语句是这样的：
        //head->next=p;
        //head=p;
        rehead=p;
        head=head->next;
        if(head==NULL) break;
    }
    return rehead;
}