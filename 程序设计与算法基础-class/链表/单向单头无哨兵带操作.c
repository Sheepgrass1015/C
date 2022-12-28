#include <stdio.h>
#include <stdlib.h>

//definitions
//create node
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
//insert_head
void list_insert_head(List *plist,int x){
    Node *p=list_create_node(x);
    p->next=plist->head;
    plist->head=p;
}
//interate
void list_interate(List *plist){
    Node *p=plist->head;
    for(;p;p=p->next){
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
//delete
void list_delete(List *plist,int x){
    Node *p=NULL;
    Node *q=NULL;
    //全部初始化为NULL，这对于判断边界十分关键
    for(p=plist->head;p;){
        if(p->value==x){
            Node *r=p->next;
            if(q){
                q->next=p->next;
            }else{//q=NULL,指的是删除链表头
                plist->head=p->next;
            }
            free(p); 
            //相当于断开又接上，r就是那个连接点
            //为什么要接上呢？也是为了可以一次性删除多个相同的值
            p=r;
            //break;
        }else{//没有找到，p和q都往后移动一个节点
            q=p;
            p=p->next;
            //为了能够一次性删除多个相同的值
            //当进行删除操作后，q不能往前走
        }
    }
}
//append_tail
void list_append_tail(List *plist,int x){
    Node *n=list_create_node(x);
    Node *p;
    for(p=plist->head;p->next;p=p->next){
        ;
    } 
    if(p){
        p->next=n;
    }else{
        plist->head=n;
    }
}
//erase
void list_erase(List *plist){
    Node *p;
    for(p=plist->head;p;){
        Node *q=p->next;
        //如果在free(p)之后再进行p=p->next
        //那么是没有结果的，这就是q出现的原因
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
    List list={NULL};

    while(1){
        scanf("%d",&x);
        if(x==-1) break;
        list_insert_head(&list,x);
    }
    list_interate(&list);
    f(list);
    list_interate(&list);
}