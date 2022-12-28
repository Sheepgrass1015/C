#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu{
      char name[20];
      int no;
      struct stu *next;
};

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
            strcpy(p->name,n);
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
    for(struct stu *p=head->next;p;p=p->next){
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
        if(p==head->next){
            head->next=p->next;
            free(p);
        }else{
            q->next=p->next;
            free(p);
        }
    }
    return flag;
}