/*
链表的基本操作 
*/ 

#include <iostream>
using namespace  std;
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct {
	int num;
}ElemData;

typedef struct LinkNode{
	struct LinkNode *next;
	ElemData NodeData;
}LinkNode,*LinkList; 

int Init(LinkList &L){
	L = new LinkNode;
	L->next = NULL;	
	return OK;
}

void CreatLinkList(LinkList &L,ElemData e){
	LinkNode *P = new LinkNode;
	P->NodeData = e;
	P->next = L->next;//保存当前链表尾指针 
	L->next = P;
	L = P;
	return OK;
}

void CreatLinkList_2(LinkList &L,ElemData e){
	LinkList r;
	LinkNode *P = new LinkNode;
	r = L;
	P->NodeData = e;
	P->next = L->next;//保存当前链表尾指针 
	L->next = P;
	L = P;
	return OK;
}


int GetElem(LinkList &L,ElemData e,int i){
	LinkNode *P = new LinkNode;
	P =L->next;
	int j = 1; 
	while(P&& j < i){
		P = P->next;
		j++;
	}
	if(!P&&j>i) return ERROR;
	e = P->next->NodeData;
	return  OK;
} 

int SearchElem(){
	
}

int DeleteElem(){
	
}

int InsertElem(){
	
}


int main()
{

	return 0;
}
 
