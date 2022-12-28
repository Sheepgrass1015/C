/*
同时使用一个队列order和一个堆栈s来解决该问题，其中，order存储待判断的出栈序列，而s用于模拟序列中每个元素的入栈和出栈过程。
这里按照1-n的顺序将每个元素压入栈s：
每次压入一个元素，检查栈顶元素与队列头元素是否相同，若相同，s与order同时执行pop操作。
若最终栈s为空，说明order里存放的序列是合理的出栈顺序，否则就是不合理的出栈序列。
*/
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
 
bool StackOrder(int A[],int B[],stack *s){
 	if(A==NULL) 
 		return false;
 	int i,j;
 	i=j=0;
 	while(i<5){
 		printf("插入数据\n");//用于检测 
 		push(s,A[i++]);
 		while(!stackempty(s)&&B[j]==gettop(s)){
 			pop(s);
 			j++;
 		}		
 	}
 	if(stackempty(s))
 		return true;
 	return false;
 
 }
int main(){ 
//	初始化	
	stack s1,s2;
	inistack(&s1);
	inistack(&s2);
	int A[5]={1,2,3,4,5};
	int B[5]={3,2,1,5,4};//正确顺序，错误顺序：3,1,2,4,5 
	bool flag=0;
	//判断函数 
	flag=StackOrder(A,B,&s1);
	if(flag)
		printf("顺序正确！");
	else
		printf("顺序错误！");
}



