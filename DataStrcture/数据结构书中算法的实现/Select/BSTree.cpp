#include <iostream>
#include <cstdio>
using namespace std;
#define ENDFLAG 0
typedef int ElemType;


//¶þ²æÅÅÐòÊ÷ 
typedef struct BSTNode
{
	struct	BSTNode *Rchild,*Lchild;
	ElemType data;
}BSTNode,*BSTree;

/*void Init(BSTree &T)
{
	T = NULL;
	T->Lchild = T->Rchild =NULL;
}*/
void InOrder_Traverse(BSTree T)
{
	if(T)
	{
		InOrder_Traverse(T->Lchild);
		cout<<T->data<<" ";
		InOrder_Traverse(T->Rchild);
	}
}


void Insert_BSTree(BSTree &T,ElemType e)
{
	if(!T)
	{
		BSTNode *p ;
		p = new BSTNode;
		p->data = e;
		p->Rchild = p->Lchild = NULL;
		T = p;
	}
	else if(e > T->data) Insert_BSTree(T->Rchild,e);
	else if(e < T->data) Insert_BSTree(T->Lchild,e);
}


void Creat_BSTree(BSTree &T){
	ElemType e;
	T = NULL;
	cin>>e;
	while(e != ENDFLAG)
	{
		Insert_BSTree(T,e);
		cin>>e;
	}
}


int main()
{
	BSTree T;
//	Init(T);
	Creat_BSTree(T);
	InOrder_Traverse(T);
	return 0;
}
