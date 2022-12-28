#include <stdio.h>
#include <stdlib.h>

//definition**change
typedef struct _node{
    int value;
    struct _node *next;
    struct _node *prev;
} Node;
typedef struct{
    Node *head;
    Node *tail;
} List;

//functions
//create_node **change
Node *create_node(int x){
    Node *p=(Node *)malloc(sizeof(Node));
    p->value=x;
    p->next=p->prev=NULL;
    return p;
}
//insert_head**change
void list_insert_head(List *plist,int x){
    Node *p=create_node(x);
    p->next=plist->head;
    if(plist->head){
        plist->head->prev=p;  
    }
    plist->head=p;
    if(plist->tail==NULL){
        plist->tail=p;
    }
}
//interate
void list_interate(List *plist){
    for(Node *p=plist->head;p;p=p->next){
        printf("%d ",p->value);
    }
    printf("\n");
}
//search
int list_search(List *plist,int x){
    int re=-1;
    int loc=0;
    for(Node *p=plist->head;p;p=p->next){
        if(p->value==x){
            re=loc;
            break;
        }
        loc++;
    }
    return re;
}
//length
int list_length(List *plist){
    int len=0;
    for(Node *p=plist->head;p;p=p->next){
        len++;
    }
    return len;
}
//insert_at**change
void list_insert_at(List *plist,int idx,int x){
    Node *n=create_node(x);
    Node *p=NULL;//初始值防止边界值判断出错
    if(plist->head){//head!=NULL
        for(p=plist->head;idx;p=p->next,idx--)
        ;
        if(p->prev){//p!=head
            p->prev->next=n;
        }
        n->next=p;
        p->next->prev=n;
        p->prev=n;
    }else{//head==NULL
        plist->head=plist->tail=n;
    }
}
//delete**change
void list_delete(List *plist,int x){
    for(Node *p=plist->head;p;){
        if(p->value==x){
            Node *r=p->next;
            if(p->prev){//p!=head
                p->prev->next=p->next;
            }else{//p==head
                plist->head=p->next;
            }
            if(p->next){//p!=tail
                p->next->prev=p->prev;
            }else{//p==tail
                plist->tail=p->prev;
            }
            free(p);
            p=r;
        }else{
            p=p->next;
        }
    }
}
//append_tail**change
void list_append_tail(List *plist,int x){
    Node *n=create_node(x);
    if(plist->tail){
        plist->tail->next=n;
        n->prev=plist->tail;
        plist->tail=n;
    }else{//如果是空链表
        plist->head=plist->tail=n;
    }
}
//erase
void list_erase(List *plist){
    Node *p;
    for(p=plist->head;p;){
        Node *q=p->next;
        free(p);
        p=q;
    }
}

int main(){
    int x;
    List list={.head=NULL,.tail=NULL};

    while(1){
        scanf("%d",&x);
        if(x==-1) break;
        list_insert_head(&list,x);
    }
    list_interate(&list);
}