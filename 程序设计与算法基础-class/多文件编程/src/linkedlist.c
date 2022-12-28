#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct _node {
    int value;
    struct _node *next;
} Node;

List list_create(){//check
    List l;
    l.head=NULL;
    l.tail=NULL;
    return l;
}
void list_free(List *list){//check
    Node *p=list->head;
    Node *q=list->tail;
    if(p && q){
        for(Node *r=list->head;r;){
            Node *s=r->next;
            free(r);
            r=s;
        }
    }
    list->head=NULL;
    list->tail=NULL;
}

void list_append(List *list, int v){//check
    Node *n=(Node *)malloc(sizeof(Node));
    n->next=NULL;
    n->value=v;
    Node *p=list->tail;
    if(p){
        if(list->head){
            p->next=n;
        }
    }else{
        if(list->head){
            list->head->next=n;
        }else{
            list->head=n;
        }
    }
    list->tail=n;
}
void list_insert(List *list, int v){//check
    Node *n=(Node *)malloc(sizeof(Node));
    n->next=NULL;
    n->value=v;
    Node *p=list->head;
    if(p){
        if(list->tail){
            n->next=p;
        } 
    }else{
        if(list->tail){
            n->next=list->tail;
        }else{
            list->tail=n;
        }
    }
    list->head=n;
}

void list_set(List *list, int index, int v){//check
    Node *p=list->head;
    for(int i=0;i<index;i++){
        p=p->next;
    }
    p->value=v;
}
int list_get(List *list, int index){//check
    Node *p=list->head;
    for(int i=0;i<index;i++){
        p=p->next;
    }
    return p->value;
}

int list_size(List *list){//check
    int s=0;
    Node *p=NULL;
    Node *q=NULL;
    p=list->head;
    q=list->tail;
    if(p==NULL || q==NULL){
        if(p==NULL && q==NULL){
            return 0;
        }else{
            return 1;
        }
    }else{
        for(;p;p=p->next){
            s++;
        }
        return s;
    }

}

int list_find(List *list, int v){//check
    int index=0;
    Node *p=list->head;
    Node *q=list->tail;
    if(p==NULL){
        if(q==NULL){
            return -1;
        }else{
            if(q->value==v){
                return 0;
            }else{
                return -1;
            }
        }
    }
    for(;p;p=p->next){
        if(p->value==v){
            break;
        }
        index++;
    }
    if(p==NULL){
        return -1;
    }else{
        return index;
    }
}
void list_remove(List *list, int v){
    Node *p=list->head;
    Node *q=list->tail;
    Node *r;
    if(p==NULL && q->value==v){
        list->tail=NULL;
        return;
    }
    if(q==NULL && p->value==v){
        printf("1\n");
        list->head=NULL;
        return ;
    }
    //q和p都不为NULL
    p=list->head;
    q=NULL;
    for(;p;){
        if(p->value==v){
            r=p->next;
            if(p==list->head){
                list->head=p->next;
                free(p);
                p=r;
            }else if(p==list->tail){
                list->tail=q;
                list->tail->next=NULL;
                free(p);
                return ;
            }else{
                q->next=p->next;
                free(p);
                p=r;
            }
        }else{
            q=p;
            p=p->next;
        }
    }
}

void list_iterate(List *list, void (*func)(int v)){
    Node *p=list->head;
    Node *q=list->tail;
    if(p && q){
        for(;p;p=p->next){
            func(p->value);
        }
        return ;
    }
    if(p==NULL && q!=NULL){
        func(q->value);
        return;
    }else  if(q==NULL && p!=NULL){
        func(p->value);
        return;
    }else{
        return;
    }
}
