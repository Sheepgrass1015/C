//本题要求实现一个函数， pur_LinkList(LinkList L)函数是删除带头结点单链表的重复结点。
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

void  pur_LinkList(LinkList L);

void Print_LinkList(LinkList L);/*这里忽略函数的实现*/


int main()
{
    LinkList L;

    L = Creat_LinkList();
    if(L == NULL)
    { 
        printf("L=NULL,error!"); 
        return 0;  
    }

    pur_LinkList(L);
    Print_LinkList(L);

    return 0;
}
/* 请在这里填写答案 */
void  pur_LinkList(LinkList L){
    LNode *p=NULL;
    LNode *q=NULL;
    LNode *r=NULL;
    int a[10000]={0};
    int cnt=0;
    for(p=L->next;p;p=p->next){
        a[cnt]=p->data;
        cnt++;
    }
    //如果要知道一个数在链表中是否重复，就要知道链表中所有的数
    //所以我选择将它们都存放到一个数组里
    //虽然不用这个数组也是可以的……但是我会觉得很麻烦
    //因为链表终究是一个比较复杂的结构，不如数组方便
    int k=0;
    p=L->next;
    for(;k<cnt;k++){
        int flag=1;
        for(int j=0;j<k;j++){
            if(a[j]==a[k]){
                flag=0;
                break;
            }
        }
        if(flag==0){//重复元素
            r=p->next;
            q->next=r;
            free(p);
            p=r;
        }else{
            q=p;
            p=p->next;//常规操作
        }
    }
}