/*
本题要求实现一个函数，Get_LinkList(LinkList L, int i)
函数是在带头结点单链表中按序号查找第i个结点的节点,函数返回第i个结点的指针。
*/

#define FLAG  -1
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}LNode, *LinkList;

LinkList Creat_LinkList();/*这里忽略函数的实现*/


LNode *Get_LinkList(LinkList L, int i);

int main()
{
    LinkList L;
    int i;
    LNode *p;

    L = Creat_LinkList();
    if(L == NULL)
    { 
        printf("L=NULL,error!"); 
        return 0;  
    }

    scanf("%d",&i);
    if(p = Get_LinkList(L,i))  printf("%d",p->data);
    else printf("NOT");
    return 0;
}

/* 请在这里填写答案 */
LNode *Get_LinkList(LinkList L, int i){
    LNode *p=NULL;
    int cnt=0;
    for(p=L->next;p;p=p->next){
        cnt++;
    }
    if(i>cnt){
        return NULL;
    }
    p=L;
    for(int k=0;k<i;k++){
        p=p->next;
    }
    return p;
}