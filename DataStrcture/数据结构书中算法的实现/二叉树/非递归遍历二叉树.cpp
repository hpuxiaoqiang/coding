#include <iostream>
#include <cstdio>
#include <cstring>
#define OK 1
#define ERROR 0
#define MaxSize
using namespace std;
typedef int status;

typedef char ElemType;
typedef struct BiTNode{
	struct BiTNode *Lchild,*Rchild;
	ElemType data;
}BiTNode,*BiTree;

typedef struct StackNode{
	struct StackNode *next;
	BiTNode *data;
}StackNode,*LinkStack;

int Init(LinkStack &S)
{
	S = NULL;
	return OK;
  }  
status Push(LinkStack &S,BiTNode *e)
{
	StackNode *p;
	p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
status Pop(LinkStack &S,BiTree &e)
{
	StackNode *p;
	if(S == NULL ) return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
status Stack_is_Empty(LinkStack &S)
{
	if(S->next == NULL) return 1;
	else return 0;
}

void Create_BiTree(BiTree &T)
{
	ElemType ch;
	cin>>ch;
	if(ch == '#') T = NULL;
	else{
		T = new BiTNode;
		T->data = ch;
		Create_BiTree(T->Lchild);
		Create_BiTree(T->Rchild);
	} 
}

void InOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *p,*q;
	q = new BiTNode;
	p = T;
	while(p||!Stack_is_Empty(S))
	{
		if(p)
		{
			Push(S,p);
			p = p->Lchild;
		}
		else{
			Pop(S,q);
			cout<<q->data;
			p = q->Rchild;
		}
	}
 } 

int main()
{
	BiTree T;
	Create_BiTree(T);
	InOrderTraverse(T);
	return 0;
}
