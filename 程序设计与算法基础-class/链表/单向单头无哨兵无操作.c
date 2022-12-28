#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef struct _node{
    int value;
    struct _node *next;
}Node;

int main(){
    Node *head=NULL;
    int x;
    while(1){
        scanf("%d",&x);
        if(x==-1) break;
        //create a node
        Node *p=(Node *)malloc(sizeof(Node));
        p->value=x;
        p->next=NULL;
        //insert head
        p->next=head;
        head=p;
    }
    
    //inerate
    for(Node *p=head;p;p=p->next){
        printf("%d  ",p->value);
    }
}