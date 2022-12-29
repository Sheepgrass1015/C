/*
n个人围成一圈（编号依次为：0,1,2...n-1）,从第一个人开始报数，1，2，……数到m者出列，再从下一个开始重新报数，数到m者再出列……。
下面的程序中，用不带附加表头的循环单链表来模拟约瑟夫环，且只设指向最后一个元素的尾指针。
算法的思想是，第一步，先将每个人的编号追加到一个通过尾指针标识的循环单链表中。
第二步，从首元素开始计数，数到m的取下这个元素，并追加到另一个用尾指针标识的循环单链表中……直到全部元素都取下。
第三步，输出最后建立的循环单链表。请编写函数，完成第三步工作：输出通过尾指针标识的循环单链的全部元素。
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void show(struct Node *r);//show data    需要完成的函数

int main(){
    int n,m;scanf("%d%d",&n,&m);
    struct Node *p=fun(n,m);//创建按出列顺序排列的循环单链表，返回指向尾元素的指针：测试程序提供
    show(p);//调用显示函数显示数据   该函数需要编程完成
    return 0;
}
/* 请在这里填写答案 */
void show(struct Node *r){
    if(r==NULL){
        printf("[]\n");
    }else{
        struct Node *p=r->next;
        printf("[");
        while(p!=r){
            printf("%d,",p->data);//其实给出的程序里已经把约瑟夫环的顺序排好了，这里只要按顺序输出就行
            p=p->next;
        }
        printf("%d]",p->data);
    }
    
}