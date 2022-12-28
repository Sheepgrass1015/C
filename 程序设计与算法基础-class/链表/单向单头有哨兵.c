#include <stdio.h>
#include <stdlib.h>

//definition
typedef struct _node
{
    int value;
    struct _node *next;
} Node;
//create list
typedef struct {
    Node *head;
} List;

//functions
//create_node
Node *list_create_node(int x){
    Node *p=(Node *)malloc(sizeof(Node));
    p->value=x;
    p->next=NULL;
    return p;
}
//create_list
List create_list(){
    Node *p=list_create_node(0);//create a sentinel
    List list;
    list.head=p;
    return list;
}
//insert_head**change
void list_insert_head(List *plist,int x){
    Node *p=list_create_node(x);
     p->next=plist->head->next;
     plist->head->next=p;
}
//interate**change
void list_interate(List *plist){
    Node *p=plist->head->next;//head is the sentinel
    for(;p;p=p->next){
        printf("%d ",p->value);
    }
    printf("\n");
}
//search**change
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
//length**change
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
    if(idx==0){
        n->next=plist->head->next;
        plist->head->next=n;
    }else{
        n->next=p->next;
        p->next=n;
    }
    
}
//delete
void list_delete(List *plist,int x){
    Node *p=NULL;
    Node *q=plist->head;
    //全部初始化为NULL，这对于判断边界十分关键
    for(p=plist->head->next;p;){
        if(p->value==x){
            Node *n=p->next;
            q->next=p->next;
            free(p);
            p=n;
            //这里不需要考虑p->next=NULL的问题
            //因为如果这样，说明只有哨兵，是空链表
            //马上退出了
        }else{
            q=p;
            p=p->next;
        }
    }
}
//append_tail**change
void list_append_tail(List *plist,int x){
    Node *n=list_create_node(x);
    Node *p;
    for(p=plist->head->next;p->next;p=p->next){
        ;
    } 
    p->next=n;
    //不需要考虑p是不是空的，因为有哨兵在
}
//erase**change
void list_erase(List *plist){
    Node *p;
    for(p=plist->head->next;p;){
        Node *q=p->next;
        free(p);
        p=q;
    }
}
//remove_all**change
void list_remove_all(Node *p){
    if(p->next){
        list_remove_all(p->next);
        free(p);
    }
}
void f(Node *head){
    head->next=NULL;
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
    f(list.head);
    list_interate(&list);
    list_erase(&list);
}