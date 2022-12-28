#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//******堆栈数据结构****** 
typedef struct
{
	char *base;
	char *top;
	int size;
}stack;
//******堆初始化 ****** 
void inistack(stack *A) 
{	
	A ->base =(char *)malloc(100*sizeof(char));
	A ->top = A ->base;
	A ->size = 100;	
} 
//******判断栈是否为空******
bool stackempty(stack *A) 
{
	if(A->top==A->base)
		return true;
	else
		return false;
}
bool push(stack *A,char x)
{
	if(A->top-A->base >=A ->size)
		A->base = (char *)realloc(A ->base, (A->size+10)*sizeof(char));
	*A->top++=x;
	    return true;
} 
char pop(stack *A)
{
	if(A->top==A->base )
		return 0;
	
	return(*--A->top);
}
char gettop(stack *A)
{
	if(A->top==A->base)
		return 0;
	return *(A->top-1);
}