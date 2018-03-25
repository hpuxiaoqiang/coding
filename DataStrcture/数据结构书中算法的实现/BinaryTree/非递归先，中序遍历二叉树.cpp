#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
typedef  int status;
typedef char ElemType;

typedef struct BiTNode{
	struct BiTNode *Lchild,*Rchild;
	ElemType data;
}BiTNode,*BiTree;

typedef struct StackNode{
	struct StackNode *next;
	BiTNode *address;
}StackNode,*LinkStack;

void InitStack(LinkStack &S)
{
	S = NULL;
}
status Push(LinkStack &S,BiTNode *e)
{
	StackNode *p;
	p = new StackNode;
	p->address = e;
	p->next = S;
	S = p;
	return OK;
}

status Pop(LinkStack &S,BiTNode *e)
{
	if(S = NULL) return ERROR;
	StackNode *p;
	e = S->address;
	p = S;
	S = S->next;
	delete p;
	return OK;
 } 

status Stack_is_Empty(LinkStack &S)
{
	if( S == NULL) return OK;
	else return ERROR; 
}

void Creat_BiTree(BiTree &T){
	char ch;
	cin>>ch;
	if(ch == '#') T = NULL;
	else{
		T = new BiTNode;
		T->data = ch;
		 Creat_BiTree(T->Lchild);
		 Creat_BiTree(T->Rchild); 
	}
}
//中序非递归遍历二叉树 
int PreOrderBiTree(BiTree T)
{
	StackNode *S;
	InitStack(S);
	if(T == NULL) return ERROR;
	BiTNode *p;
	BiTNode *q;
	q = new BiTNode;
	p = T;
	while(p||!Stack_is_Empty(S))
	{
		if(p)
		{
			Push(S,p);
			p = p->Lchild;
		}else{
			Pop(S,q);
			cout<<q->data;
			p = q->Rchild;
		}	
	}
	
}
//先序非递归遍历二叉树 
void OrderBiTree(BiTree T)
{
	StackNode *S;
	InitStack(S);
	BiTNode *p;
	p = T;
	while(p||!Stack_is_Empty(S))
	{
		while(p)
		{
			Push(S,p);
			cout<<p->data;
			p = p->Lchild;
		}
		Pop(S,p);
		p->Rchild;
	}
}


int main()
{
	BiTree T;
	Creat_BiTree(T);
	PreOrderBiTree(T);
	return 0;
 } 
