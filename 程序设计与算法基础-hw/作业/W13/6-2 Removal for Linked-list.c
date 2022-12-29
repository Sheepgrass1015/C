/*
This a linked-list program that reads unknown amount of non-negative integers. -1 is used to indicates the end of the input process.
Then the program reads another integer and find all apprearence of this integer in the previous input and remove them.
Finally the program prints out the remainning integers.

You are required to implement list_append() and list_remove() functions.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

void list_append(List *list, int value);
void list_remove(List *list, int value);
void list_print(List *list);
void list_clear(List *list);

int main()
{
    List list = {NULL, NULL};
    while ( 1 ) {
        int x;
        scanf("%d", &x);
        if ( x == -1 ) {
            break;
        }
        list_append(&list, x);
    }
    int k;
    scanf("%d", &k);
    list_remove(&list, k);
    list_print(&list);
    list_clear(&list);
}

void list_print(List *list)
{
    for ( Node *p = list->head; p; p=p->next ) {
        printf("%d ", p->value);
    }
    printf("\n");
}

void list_clear(List *list)
{
    for ( Node *p = list->head, *q; p; p=q ) {
        q = p->next;
        free(p);
    }
}
//从这个clear函数可以看出，这个链表是没有哨兵的
//如果有哨兵，应该从list->head->next开始遍历
//所以这是一个关于双向双头无哨兵的链表的函数编写


/* 请在这里填写答案 */
void list_append(List *list, int value){
    Node *n=(Node *)malloc(sizeof(Node));
    n->value=value;
    n->next=n->prev=NULL;
    if(list->tail){
        list->tail->next=n;
        n->prev=list->tail;
        list->tail=n;
    }else{
        list->tail=list->head=n;
    }
}
void list_remove(List *list, int value){
    Node *p=NULL;
    Node *q=NULL;
    //时刻记住，q是p的prev
    for(p=list->head;p;){
        if(p->value==value){
            if(p->next){//p不是tail
                Node *r=p->next;
                if(q){//p不是head
                    q->next=p->next;
                    p->next->prev=q;
                }else{//p是head
                    r->prev=NULL;
                    list->head=r;
                }
                free(p);
                p=r;
            }else{//p是tail
                p->prev->next=NULL;
                list->tail=p->prev;
                free(p);
            }
        }else{
            q=p;
            p=p->next;
        }
    }
}
