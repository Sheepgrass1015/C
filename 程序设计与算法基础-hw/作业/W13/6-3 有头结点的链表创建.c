/*
创建一个函数myCreate(head,m)，head为链表的头结点，m为要创建的结点个数。函数功能是创建一个带有头结点的链表，结点个数由ｍ指定，在函数中需要将每个结点的数据域输入，函数的返回值为int类型，1代表创建成功，0代表创建失败（失败的原因可能是输入数据有误或内存空间不足等）。


创建 函数 show(head)，显示带有头结点的链表head的全部节点信息。没有返回值。

创建 函数myIndex(head,s) ,在head中查找第一个name域与s相等的结点，返回找到结点的地址，若没有找到，返回NULL。

创建myDel(head,s)函数。在head中查找第一个name域与s相等的结点，将这个结点从head中删除，若删除成功，返回值 为1，没找到结点返0。

函数接口定义：
在这里描述函数接口。例如：
int  myCreate(struct stu *head,int m);
void show(struct stu *head);
struct stu * myIndex(struct stu *head,char *s);
int myDel(struct stu *head,char *s);
其中:
myCreate 函数中 head 和 m 都是用户传入的参数。 head 为链表的头结点，数据域为空。 m 是1-100之间的整数。myCreate函数须返回整型数，1代表链表创建成功，0代表链表未创建成功。

show函数中head 是用户传入的参数。 head 为链表的头结点，数据域为空。功能显示所有结点的信息，每行信息为name no，中间用空格分隔。无返回值。

myIndex函数中， head 和 s 都是用户传入的参数。在head中查找第一个name域与s相等的结点，返回找到结点的地址，若没有找到，返回NULL。

myDel函数中，head 和 s 都是用户传入的参数。在head中查找第一个name域与s相等的结点，将这个结点从head中删除，若删除成功，返回值 为1，没找到结点返0。
*/
#include <stdio.h>
#include <stdlib.h>//明显是用于malloc的
#include <string.h>//注意了，包含string.h，说明肯定和字符串处理有关了，灵活运用函数

struct stu{
      char name[20];
      int no;
      struct stu *next;
};
//看得出来，是一个单头单向有哨兵的链表

int  myCreate(struct stu *head,int m);
void show(struct stu *head);
struct stu * myIndex(struct stu *head,char *s);
int myDel(struct stu *head,char *s);

int main()
{
  struct stu head;
    struct stu *p;
    char name[20];
  int  m;
  scanf("%d", &m);// 输入m，代表结点个数
  if(myCreate(&head,m)==1)//如果创建成功 
      {
            printf("created...\n");
            show(&head);//显示所有结点的信息
             scanf("%s",name);//输入要查找的姓名
             if((p=myIndex(&head,name))!=NULL){//如果找到了显示信息  
                  printf("%s %d\n",p->name,p->no);
             }
             else
                printf("not found.\n");
             scanf("%s",name);//输入要删除的姓名
           if(myDel(&head,name)==1) 
                    printf("deleted.\n");
           else
                    printf("not found.\n");
         }
 else printf("create failure.");
 return 0;
}

/* 请在这里填写答案 */
int  myCreate(struct stu *head,int m){
    head->next=NULL;
    if(m<1||m>100){
        return 0;
    }
    int x;
    char n[20];
    int flag=1;
    struct stu*p=(struct stu*)malloc(sizeof(struct stu));
    for(int i=0;i<m;i++){
        p->next=NULL;
        if(scanf("%s %d",n,&x)!=2){
            flag=0;
        }
        if(i==0){//第一个进来的节点
            strcpy(p->name,n);//strcpy的使用真的很重要
            p->no=x;
            head->next=p;
        }else{//后面进来的节点
        struct stu*q=(struct stu*)malloc(sizeof(struct stu));
            p->next=q;
            q->next=NULL;
            strcpy(q->name,n);
            q->no=x;
            p=q;
        }
    }
    return flag;
}
void show(struct stu *head){
    for(struct stu *p=head->next;p;p=p->next){//有哨兵链表的特点：从head->next开始遍历
        printf("%s %d\n",p->name,p->no);
    }
}
struct stu * myIndex(struct stu *head,char *s){
    struct stu *p=NULL;
    for(p=head->next;p;p=p->next){
        if(strcmp(s,p->name)==0) break;
    }
    return p;
}
int myDel(struct stu *head,char *s){
    struct stu *p=NULL;
    struct stu *q=NULL;
    q=head;
    int flag=1;
    for(p=head->next;p;){
        if(strcmp(s,p->name)==0) break;
        q=p;
        p=p->next;
    }
    if(p==NULL){
        flag=0;
    }else{
        if(p==head->next){//简单直接地分类讨论一下
            head->next=p->next;
            free(p);
        }else{
            q->next=p->next;
            free(p);
        }
    }
    return flag;
}