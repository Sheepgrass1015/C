#include <stdio.h>
#include <stdlib.h>

//definition**change
typedef struct _node {
    int value;
    struct _node *next;
} Node;
typedef struct{
    Node *head;
    Node *tail;
} List;

//functions 
//create_node 
Node *list_create_node(int x){
    Node *p=(Node *)malloc(sizeof(Node*));
    p->value=x;
    p->next=NULL;
    return p;
}
//insert_head**change
void list_insert_head(List *plist,int x){
    Node *p=list_create_node(x);
    p->next=plist->head;
    plist->head=p;
    if(plist->tail==NULL){//如果是空链表
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
//append_tail**change
void list_append_tail(List *plist,int x){
    Node *n=list_create_node(x);
    plist->tail->next=n->next;
    plist->tail=n;
    if(plist->tail==NULL){//如果是空链表
        plist->head=n;
    }
}
//insert_at
void list_insert_at(List *plist,int idx,int x){
    Node *n=list_create_node(x);
    Node *p=NULL;//初始值防止边界值判断出错
    if(idx>0){
        for(p=plist->head;p;p=p->next){
            if(idx==1) break;
            idx--;
        }
    }
    if(p!=NULL){
        n->next=p->next;
        p->next=n;
    }else{
        //要插到链表头
        n->next=plist->head;
        plist->head=n;
    }
}
//delete**change，对于删除tail有特别判定
void list_delete(List *plist,int x){
    Node *p=NULL;
    Node *q=NULL;
    for(p=plist->head;p;){
        if(p->value==x){
            Node *r=p->next;
            if(q){
                q->next=p->next;
            }else{//q=NULL,指的是删除链表头
                plist->head=p->next;
            }
            if(p==plist->tail){//删除tail的情况
                plist->tail=q;
            }
            free(p); 
            p=r;
            //break;
        }else{
            q=p;
            p=p->next;
        }
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
//remove_all(相当于erase的递归版本)
void list_remove_all(Node *p){
    if(p){
        list_remove_all(p->next);
        free(p);
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