//关于栈和栈的基本操作
#include <stdio.h>
#define true 1
#define false 0
#define MAXSIZE 50//定义栈中最多元素个数
typedef int bool;
typedef int Elemtype;//元素类型根据实际情况而定
typedef int Status;
typedef struct {
    Elemtype data[50];
    int top;//用于栈顶指针
}Stack;

void initStack(Stack *s);
bool StackEmpty(Stack *s);
Status PushStack(Stack *s,Elemtype a);
Status PopStack(Stack *s,Elemtype *e);
Status GetTop(Stack *s,Elemtype *e);

int main(){
    Stack s;
    s.top=-1;
    int cnt;
    scanf("%d",&cnt);
    for(int i=1;i<=cnt;i++){
        if(PushStack(&s,i)==false){
            printf("push failed\n");
            break;
        }
    }
}


//初始化空栈
void initStack(Stack *s){
    s->top=-1;//空栈的头指针应该在-1
}
//判断栈是否为空
bool StackEmpty(Stack *s){
    if(s->top==0){
        return true;
    }else{
        return false;
    }
}
//进栈
Status PushStack(Stack *s,Elemtype a){
    //判断满栈
    if(s->top==MAXSIZE-1){
        return false;
    }
    s->top++;
    s->data[s->top]=a;
    return true;
}
//出栈
Status PopStack(Stack *s,Elemtype *e){
    if(s->top==-1){
        return false;//空栈
    }
    *e=s->data[s->top];//将栈顶顶元素赋值给e
    s->top--;//栈顶下沉
    return true;
}
//读栈顶元素
Status GetTop(Stack *s,Elemtype *e){
    if(s->top==-1){
        return false;//是空栈的话
    }
    *e=s->data[s->top];
    return true;
}