/*
链栈的基本操作 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct {
	int Info;
}Data;

typedef struct StackNode{
	struct StackNode *next;
	Data NodeData;	
}StackNode,*LinkStack;

int InitStack(LinkStack &S){
	S = NULL;
	return OK;
}

int Push(LinkStack &S,Data e){
	StackNode *P;
	P = new StackNode;
	P->NodeData = e;
	P->next = S;
	S = P;
	return OK;
}

int Pop(LinkStack &S,Data &e){
	if(!S) return ERROR;
	e = S->NodeData;
	StackNode *P;
	P = S;
	S = S->next;
	delete P;
	return OK;
}

int GetHead(LinkStack &S,Data &e){
	if(!S) return ERROR;
	e = S->NodeData;
	return OK;
} 

int main()
{
	return 0;
 } 
