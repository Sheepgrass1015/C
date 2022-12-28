#include <stdio.h>
#include <stdlib.h>

//definition
typedef struct _node
{
    int value;
    struct _node *next;
    struct _node *prev;
} Node;
//create list
typedef struct {
    Node *head;
    Node *tail;
} List;

//functions
//create_node
Node *list_create_node(int x){
    Node *p=(Node *)malloc(sizeof(Node));
    p->value=x;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
//create_list
List create_list(){
    Node *p=list_create_node(0);//create a sentinel
    Node *q=list_create_node(0);
    List list;
    list.head=p;
    list.tail=q;
    return list;
}
//insert_head**change
void list_insert_head(List *plist,int x){
    Node *p=list_create_node(x);
    p->prev=plist->head;
    p->next=plist->head->next;
    plist->head->next=p;
}
//interate
void list_interate(List *plist){
    Node *p=plist->head->next;//head is the sentinel
    for(;p;p=p->next){
        printf("%d ",p->value);
    }
    printf("\n");
}
//search
int list_search(List *plist,int x){
    int re=-1;
    int loc=0;
    for(Node *p=plist->head->next;p;p=p->next){
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
    for(Node *p=plist->head->next;p;p=p->next){
        len++;
    }
    return len;
}
//insert_at
void list_insert_at(List *plist,int idx,int x){
    Node *n=list_create_node(x);
    Node *p=NULL;//初始值防止边界值判断出错
    for( p=plist->head->next;idx>1;p=p->next,idx--)
        ;
    if(idx==0){//插在head哨兵处
        n->next=plist->head->next;
        n->prev=plist->head;
        plist->head->next=n;
    }else if(p==plist->tail){//插在tail哨兵处
        p->prev->next=n;
        n->prev=p->prev;
        n->next=p;
        p->prev=n;
    }else{//普通情况
        n->prev=p;
        n->next=p->next;
        p->next=n;
    }
}
//delete**change
void list_delete(List *plist,int x){
    Node *p=NULL;
    Node *q=plist->head;
    for(p=plist->head->next;p;){
        if(p==plist->tail)break;
        if(p->value==x){
            Node *n=p->next;
            p->next->prev=q;
            q->next=p->next;
            free(p);
            p=n;
        }else{
            q=p;
            p=p->next;
        }
    }
}
//append_tail
void list_append_tail(List *plist,int x){
    Node *n=list_create_node(x);
    Node *p;
    p=plist->head->next;
    for(p=plist->head->next;p->next;p=p->next){
        ;
    } 
    p->next=n;
    n->prev=p;
}
//erase
void list_erase(List *plist){
    Node *p;
    for(p=plist->head->next;p;){
        Node *q=p->next;
        free(p);
        p=q;
    }
}
//remove_all
void list_remove_all(Node *p){
    if(p->next){
        list_remove_all(p->next);
        free(p);
    }
}


int main(){//change
    int x;
    List list=create_list();

    while(1){
        scanf("%d",&x);
        if(x==-1) break;
        list_insert_head(&list,x);
    }
    list_interate(&list);
    list_append_tail(&list,9);
    list_interate(&list);
    list_erase(&list);
}